-- ----------------------------
-- 10.1.1 内置函数
-- ----------------------------
-- 1.数学函数
SELECT FLOOR(1+RAND()*(5-1));
SELECT RAND(4);
SELECT RAND();
SELECT RAND(4);
SELECT category_id, GROUP_CONCAT(id) FROM sh_goods GROUP BY category_id ORDER BY RAND() LIMIT 1;
-- 2.比较函数
SELECT id, name, keyword, category_id FROM sh_goods WHERE category_id IN(3, 11);
-- 3.位运算函数
# 创建数据表
CREATE TABLE mydb.mybin (b1 VARBINARY(20), b2 VARBINARY(20));
# 添加数据
INSERT INTO mydb.mybin VALUES (2, 6), (3, 1), (4, 9);
# 查询结果
SELECT BIT_AND(b1), BIT_OR(b1), BIT_XOR(b1) FROM mydb.mybin;

SELECT CAST(BIT_AND(b1) AS UNSIGNED) AS one, CAST(BIT_OR(b1) AS UNSIGNED) AS two, CAST(BIT_XOR(b1) AS UNSIGNED) AS three FROM mydb.mybin;
-- 4.数据类型转换函数
SELECT CONVERT(3.6/-1.2,SIGNED) res1, CAST(0.5/1 AS UNSIGNED) res2, UNHEX('41') res3;
-- 5.字符串函数
SELECT CHAR_LENGTH('努力的 ren'), LENGTH('努力的 ren');
SELECT STRCMP('C','A'), STRCMP('12','12'), STRCMP('D','H');
SELECT SUBSTRING('hello',2,3) sub, LEFT('hello',3) l, RIGHT('hello',3) r, LPAD('hello',6,'*') lpad, RPAD('hello',6,'*') rpad;

SELECT INSTR('banana','na') instr, LOCATE('na','banana') locate, FIND_IN_SET('in','liner,in,hit,in') find;

SELECT CONCAT('*', LTRIM(' hello '), '*') ltrim, CONCAT('*', RTRIM(' hello '), '*') rtrim, CONCAT('*', TRIM(' hello '), '*') trim;

SELECT INSERT('welcome', 3, 4, 'HA') first, INSERT('welcome', -4, 3, 'HA') two, INSERT('welcome', 7, 10, 'HA') three, REPLACE('welcome', 'e', 'E') four;
-- 6.日期和时间函数
SELECT NOW();
SELECT NOW(4);
SELECT NOW(), SYSDATE(), SLEEP(2), NOW(), SYSDATE()\G

SELECT FROM_UNIXTIME(UNIX_TIMESTAMP(), '%W') '星期', FROM_UNIXTIME(UNIX_TIMESTAMP(), '%y/%c/%e') '日期', FROM_UNIXTIME(UNIX_TIMESTAMP(), '%H:%i:%s') '时间';

SELECT EXTRACT(DAY_SECOND FROM NOW());

SELECT '2022-06-09 14:50:00'+INTERVAL 1 DAY one, '2022-06-09 14:50:00'-INTERVAL '2 10:02:00' DAY_SECOND two, DATE_ADD('2022-06-09 14:50:00', INTERVAL '4' YEAR) three, DATE_SUB('2022-06-09 14:50:00', INTERVAL '20' MINUTE) four\G
-- 7.加密散列函数
SELECT MD5('123456'), SHA1('123456'), SHA2('123456',256)\G
-- 8.系统信息函数
SELECT BENCHMARK(10000000,'3*7');
USE shop;
SELECT BENCHMARK(100000000,'SELECT name FROM sh_goods WHERE id=2');
-- 9.JSON函数
SELECT JSON_ARRAY('cake', 2, NULL), JSON_OBJECT("id", 12, "name", "Tom");
SELECT JSON_SET('{"id": 12}', "$.email", "test@163.com") c1, JSON_SET('{"id": 12}', "$.id", "8") c2\G
SELECT JSON_REMOVE('["a",[2,3],"b"]',"$[1]");

SELECT JSON_MERGE_PATCH('{"a":1,"b":2}', '{"a":11,"b":22,"c":33}') PATCH, JSON_MERGE_PRESERVE('{"a":1,"b":2}', '{"a":11,"b":22,"c":3}') PRESERVE\G

SELECT JSON_EXTRACT('["cookie","1",{"eat":"cookie"}]','$[0]','$[1]') c1, JSON_SEARCH('["cookie","1",{"eat":"cookie"}]','all',"cookie") c2 \G
-- 10.其他常用函数
SELECT INET_ATON('192.168.22.11');
SELECT INET_NTOA(3232241163);
SELECT SLEEP(2);
SELECT UUID();
-- ----------------------------
-- 10.1.2 自定义函数
-- ----------------------------
-- 2.创建自定义函数
# 选择shop数据库
USE shop;
# 创建自定义函数
DELIMITER $$
CREATE FUNCTION sayHello (name VARCHAR(30))
    RETURNS VARCHAR(50) NO SQL
    RETURN CONCAT('Hello ', name, '!');
    $$
DELIMITER ;
-- 3.查看自定义函数
SHOW CREATE FUNCTION sayHello\G
SHOW FUNCTION STATUS LIKE 'sayHello'\G
-- 4.调用自定义函数
SELECT sayHello('TOM');
-- 5.删除自定义函数
DROP FUNCTION IF EXISTS sayHello;
-- ----------------------------
-- 10.2.2 创建存储过程
-- ----------------------------
DELIMITER $$
CREATE PROCEDURE proc(IN sid INT)
    BEGIN
        SELECT id, name FROM sh_goods_category where id>sid;
    END
    $$
DELIMITER ;
-- ----------------------------
-- 10.2.3 查看存储过程
-- ----------------------------
-- 1.查看存储过程的状态信息
SHOW PROCEDURE STATUS LIKE 'proc'\G
-- 2.查看存储过程的创建信息
SHOW CREATE PROCEDURE proc\G
-- 3.通过数据表查询存储过程
SELECT * FROM information_schema.Routines WHERE ROUTINE_NAME='proc' AND ROUTINE_TYPE='PROCEDURE'\G
-- ----------------------------
-- 10.2.4 调用存储过程
-- ----------------------------
CALL proc(14);
-- ----------------------------
-- 10.2.5 修改存储过程
-- ----------------------------
ALTER PROCEDURE proc SQL SECURITY INVOKER COMMENT '从商品分类表中获取大于指定id值的数据';
SHOW PROCEDURE STATUS LIKE 'proc'\G
-- ----------------------------
-- 10.2.6 删除存储过程
-- ----------------------------
DROP PROCEDURE IF EXISTS proc;
SELECT * FROM  information_schema.Routines WHERE ROUTINE_NAME='proc' AND ROUTINE_TYPE='PROCEDURE'\G
-- ----------------------------
-- 10.2.7 存储过程的错误处理
-- ----------------------------
-- 1.自定义错误名称
DELIMITER $$
CREATE PROCEDURE proc()
    BEGIN
         DECLARE command_not_allowed CONDITION FOR SQLSTATE '42000';
    END
    $$
DELIMITER ;
-- 2.自定义错误处理程序
DELIMITER $$
CREATE PROCEDURE proc_demo()
    BEGIN
        DECLARE CONTINUE HANDLER FOR SQLSTATE '23000'
        SET @num=1;
        INSERT INTO sh_goods_category (id, name) VALUES(20, '运动');
        SET @num=2;
        INSERT INTO sh_goods_category (id, name) VALUES(20, '运动');
        SET @num=3;
    END
    $$
DELIMITER ;
CALL proc_demo();
SELECT @num;
-- ----------------------------
-- 10.3.1 系统变量
-- ----------------------------
-- 1.查看系统变量
SHOW VARIABLES LIKE 'auto_inc%';
SELECT @@auto_increment_offset;
-- 2.修改系统变量
# 客户端1
SET auto_increment_offset=5;
# 客户端2
SHOW VARIABLES LIKE 'auto_increment_offset';
# 客户端1
# 修改全局系统变量auto_increment_offset
SET GLOBAL auto_increment_offset=5;
# 查看auto_increment_offset的值
SHOW VARIABLES LIKE 'auto_increment_offset';
# 客户端2
SHOW VARIABLES LIKE 'auto_increment_offset';
# 客户端3
SHOW VARIABLES LIKE 'auto_increment_offset';
SET GLOBAL auto_increment_offset=1;
SET auto_increment_offset=1;
-- ----------------------------
-- 10.3.2 会话变量
-- ----------------------------
# 定义字符串类型会话变量
SET @name='admin';
# 定义整型会话变量
SET @age=22;
# 使用SELECT语句定义会话变量
SET @price = (SELECT price FROM sh_goods LIMIT 1);

SELECT id, name, price FROM sh_goods LIMIT 1 INTO @g_id, @g_name, @g_price;
SELECT @name, @age, @price, @g_id, @g_name, @g_price;

SELECT JSON_ARRAY(id,name), JSON_OBJECT(id,name) FROM sh_goods LIMIT 1 INTO @arrinfo, @objinfo;
SELECT @arrinfo, @objinfo;
-- ----------------------------
-- 10.3.3 局部变量
-- ----------------------------
DELIMITER $$
CREATE FUNCTION func() RETURNS INT DETERMINISTIC
    BEGIN
       DECLARE age INT DEFAULT 10;
       RETURN age;
    END
    $$
DELIMITER ;
SELECT func();
SELECT age;
-- ----------------------------
-- 10.4.1 判断语句
-- ----------------------------
-- 1.IF语句
SELECT id, name FROM sh_goods WHERE IF(score=5, score, 0);

DELIMITER $$
CREATE PROCEDURE isnull(IN val INT)
    BEGIN
        IF val IS NULL
            THEN SELECT 'THE parameter is NULL';
        ELSE
            SELECT 'THE parameter is not NULL';
        END IF;
    END
    $$
DELIMITER ;
-- 2.CASE语句
SELECT id, name, (CASE WHEN price<50 THEN '小额商品' WHEN price>=50 AND price<100 THEN '低价商品' WHEN price>=100 AND price<200 THEN '平价商品' WHEN price>200 THEN '大额商品' END) AS desc_price FROM sh_goods;

DELIMITER $$
CREATE PROCEDURE proc_level(IN score DECIMAL(5, 2))
    BEGIN
         CASE
         WHEN score>=90 THEN SELECT '优秀';
         WHEN score<90 AND score>=80 THEN SELECT '良好';
         WHEN score<80 AND score>=70 THEN SELECT '中等';
         WHEN score<70 AND score>=60 THEN SELECT '及格';
         ELSE SELECT '不及格';
         END CASE;
     END
     $$
DELIMITER ;
-- ----------------------------
-- 10.4.2 循环语句
-- ----------------------------
-- 1.LOOP语句
DELIMITER $$
CREATE PROCEDURE proc_sum()
    BEGIN
        DECLARE i, sum INT DEFAULT 0;
        sign: LOOP
            IF i>=10 THEN
                SELECT i, sum;
                LEAVE sign;
            ELSE
                SET sum=sum+i;
                SET i=i+1;
            END IF;
        END LOOP sign;
     END
     $$
DELIMITER ;
CALL proc_sum();
-- 2.REPEAT语句
DELIMITER $$
CREATE PROCEDURE proc_odd()
    BEGIN
        DECLARE i, sum INT DEFAULT 0;
        REPEAT
           IF i%2!=0 THEN
               SET sum=sum+i;
           END IF;
           SET i=i+1;
           UNTIL i>10 
         END REPEAT;
         SELECT i, sum;
    END
    $$
DELIMITER ;
CALL proc_odd();
-- 3.WHILE语句
DELIMITER $$
CREATE PROCEDURE proc_even()
    BEGIN
        DECLARE i, sum INT DEFAULT 0;
        WHILE i<=10 DO
            IF i%2=0
                THEN SET sum=sum+i;
            END IF;
            SET i=i+1;
         END WHILE;
         SELECT i, sum;
     END
     $$
DELIMITER ;
CALL proc_even();
-- ----------------------------
-- 10.4.3 跳转语句
-- ----------------------------
DELIMITER $$
CREATE PROCEDURE proc_jump()
    BEGIN
        DECLARE num, sum INT DEFAULT 0;
        my_loop: LOOP
            SET num=num+2;
            SET sum=sum+num;
            IF num<10
                THEN ITERATE my_loop;
            ELSE SELECT sum;LEAVE my_loop;
            END IF;
        END LOOP my_loop;
     END
     $$
DELIMITER ;
CALL proc_jump();

-- ----------------------------
-- 10.5.2 游标的基本操作
-- ----------------------------
DELIMITER $$
CREATE PROCEDURE sh_goods_proc_cursor()
    BEGIN
        DECLARE mark, cur_id, cur_num INT DEFAULT 0;
        # 定义游标
        DECLARE cur CURSOR FOR
        SELECT id, stock FROM sh_goods WHERE score=5;
        # 自定义错误处理程序，结束游标的遍历
        DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET mark=1;
        # 打开游标
        OPEN cur;
        # 遍历游标
        REPEAT
             # 利用游标获取一行记录
             FETCH cur INTO cur_id, cur_num;
             # 处理游标检索的数据
             IF cur_num>=0 && cur_num<=400 THEN
                 SET cur_num=1500;
                 UPDATE sh_goods SET stock=cur_num WHERE id=cur_id;
             END IF;
        UNTIL mark END REPEAT;
        # 关闭游标
        CLOSE cur;
    END
    $$
DELIMITER ;
SELECT id, stock FROM sh_goods WHERE score=5;
CALL sh_goods_proc_cursor();
SELECT id, stock FROM sh_goods WHERE score=5;
-- ----------------------------
-- 10.6.2 触发器的基本操作
-- ----------------------------
-- 1.创建触发器
DELIMITER $$
CREATE TRIGGER insert_tri BEFORE INSERT
    ON sh_user_shopcart FOR EACH ROW
    BEGIN
        DECLARE stocks INT DEFAULT 0;
        SELECT stock INTO stocks FROM sh_goods WHERE id=new.goods_id;
        IF stocks<=new.goods_num THEN
           SET new.goods_num=stocks;
           UPDATE sh_goods SET stock=0 WHERE id=new.goods_id;
        ELSE
           UPDATE sh_goods SET stock=stocks-new.goods_num WHERE id=new.goods_id;
        END IF;
    END;
    $$
DELIMITER ;
-- 2.查看触发器
SHOW TRIGGERS\G
SELECT * FROM information_schema.triggers WHERE trigger_name='insert_tri'\G
-- 3.执行触发器
SELECT id, stock FROM sh_goods WHERE id=5;
INSERT INTO sh_user_shopcart (user_id, goods_id, goods_num, goods_price) VALUES (3, 5, 2000, 1999.00);
SELECT id, stock FROM sh_goods WHERE id=5;
SELECT id, user_id, goods_id, goods_num, goods_price FROM sh_user_shopcart;
-- 4.删除触发器
DROP TRIGGER IF EXISTS insert_tri;
SELECT * FROM information_schema.triggers WHERE trigger_name= 'insert_tri';
-- ----------------------------
-- 10.7.2 事件的基本操作
-- ----------------------------
-- 1. 查看事件调度器的状态
SHOW VARIABLES LIKE 'event_scheduler';
SET GLOBAL event_scheduler=OFF;
-- 2.创建事件
CREATE EVENT insert_data_event ON SCHEDULE AT CURRENT_TIMESTAMP + INTERVAL 1 MINUTE +INTERVAL 20 SECOND DO INSERT INTO sh_goods_category(id, name) VALUES (50, '食品');

DELIMITER $$
CREATE PROCEDURE delete_proc()
    BEGIN
        DELETE FROM sh_goods
        WHERE TO_DAYS(NOW())-TO_DAYS(update_time)>=30 AND is_on_sale=0;
    END
    $$
DELIMITER ;

CREATE EVENT IF NOT EXISTS delete_event ON SCHEDULE EVERY 1 DAY ENDS CURRENT_TIMESTAMP + INTERVAL 1 YEAR ON COMPLETION PRESERVE DO CALL delete_proc();
-- 3.查看事件
SHOW EVENTS\G
-- 4.修改事件
ALTER EVENT delete_event ON SCHEDULE AT CURRENT_TIMESTAMP ON COMPLETION PRESERVE RENAME TO d_event DO CALL delete_proc();
5.删除事件
DROP EVENT d_event;
SELECT * FROM information_schema.events WHERE EVENT_NAME='d_event';
-- ----------------------------------
-- 10.8.2 预处理SQL语句的基本操作
-- ----------------------------------
-- 1.创建预处理语句
PREPARE stmt FROM 'SELECT name, price FROM sh_goods WHERE id=?';

SET @sql='SELECT name, price FROM sh_goods WHERE id=?';
PREPARE stmt FROM @sql;

-- 2.执行预处理语句
SET @id=3;
EXECUTE stmt USING @id;
-- 3.释放预处理语句
DEALLOCATE PREPARE stmt;
EXECUTE stmt USING @id;
-- -------------------------------
-- 10.9 动手实践:数据库编程实战
-- -------------------------------
#创建存储过程
DELIMITER $$
CREATE PROCEDURE page_proc(IN curp INT, IN per_page INT)
BEGIN
# ① 定义变量
DECLARE total_records, total_page, start INT;
# ② 从指定的数据表中获取总记录数
SELECT COUNT(*) INTO total_records FROM sh_goods;
# ③ 根据total_records和per_page计算总页数
SET total_page=CEIL(total_records/per_page);
# ④ 计算记录的偏移量
SET start=(curp-1)*per_page;
# ⑤ 根据分页获取数据
SET @sql_stmt=CONCAT('SELECT * FROM sh_goods LIMIT ', start,'\,' , per_page);
PREPARE paging FROM @sql_stmt;
EXECUTE paging;
DEALLOCATE PREPARE paging;
END
$$
DELIMITER ;
#调用存储过程
CALL page_proc(3,1);
CALL page_proc(2,4);
CALL page_proc(50,1);




