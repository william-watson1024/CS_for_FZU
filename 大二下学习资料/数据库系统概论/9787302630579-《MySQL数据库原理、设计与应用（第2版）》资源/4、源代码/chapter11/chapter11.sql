-- ----------------------------
-- 11.1.3 InnoDB存储引擎
-- ----------------------------
-- 1.存储格式
SHOW VARIABLES LIKE 'innodb_file_per_table';
SET GLOBAL innodb_file_per_table=OFF;
SHOW VARIABLES LIKE 'innodb_file_per_table';
-- 2.表空间设置
# 查看表空间的最后一个数据文件
SHOW VARIABLES LIKE 'innodb_data_file_path';
# 查看自动扩展的空间大小
SHOW VARIABLES LIKE 'innodb_autoextend_increment';

SHOW VARIABLES LIKE 'innodb_data_file_path';
-- ----------------------------
-- 11.2.3 创建索引
-- ----------------------------
-- 1.创建数据表的同时创建索引
CREATE TABLE index01 (
     id INT,
     indexno INT,
     name VARCHAR(20),
     introduction VARCHAR(200),
     PRIMARY KEY (id),        -- 创建主键索引
     UNIQUE INDEX (indexno),  -- 创建唯一索引
     INDEX (name),            -- 创建普通索引
     FULLTEXT (introduction)  -- 创建全文索引
);
SHOW CREATE TABLE index01\G

CREATE TABLE index_multi (
    id INT NOT NULL,
    name VARCHAR(20) NOT NULL,
    INDEX multi (id, name)
);
SHOW CREATE TABLE index_multi\G
-- 2.给已存在的数据表创建索引
CREATE UNIQUE INDEX unique_index ON sh_goods (id);
SHOW CREATE TABLE sh_goods\G
-- 3.修改数据表的同时创建索引
ALTER TABLE sh_goods ADD INDEX name_index (name), ADD FULLTEXT INDEX ft_index (content);
SHOW WARNINGS;
SHOW CREATE TABLE sh_goods\G
ALTER TABLE sh_goods ADD INDEX multi (name, price, keyword);
-- 多学一招：前缀索引
# 创建temp数据表
CREATE TABLE IF NOT EXISTS mydb.temp(
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(120) NOT NULL,
    pid INT UNSIGNED NOT NULL
);
# 创建存储过程
DELIMITER $$
    CREATE PROCEDURE mydb.temp(in max_num INT)
    BEGIN
       DECLARE i INT DEFAULT 0;
       REPEAT
           SET i=i+1;
           INSERT INTO mydb.temp (name, pid) VALUES
           (rand_str(5), FLOOR(1+RAND()*10));
           UNTIL i=max_num
       END REPEAT;
     END
     $$
DELIMITER ;
# 调用存储过程，插入2000条测试数据
CALL mydb.temp(2000);
# 不设置长度计算比值
SELECT COUNT(DISTINCT name)/COUNT(name) FROM mydb.temp;
# 设置长度计算比值
SELECT COUNT(DISTINCT LEFT(name, 1))/COUNT(name) FROM mydb.temp;
SELECT COUNT(DISTINCT LEFT(name, 2))/COUNT(name) FROM mydb.temp;
SELECT COUNT(DISTINCT LEFT(name, 3))/COUNT(name) FROM mydb.temp;
SELECT COUNT(DISTINCT LEFT(name, 4))/COUNT(name) FROM mydb.temp;
SELECT COUNT(DISTINCT LEFT(name, 5))/COUNT(name) FROM mydb.temp;
SELECT COUNT(DISTINCT LEFT(name, 6))/COUNT(name) FROM mydb.temp;
ALTER TABLE temp ADD INDEX (name(5));
-- ----------------------------
-- 11.2.4 查看索引
-- ----------------------------
SHOW INDEX FROM sh_goods\G
-- 多学一招： 分析SQL语句是否使用索引
EXPLAIN SELECT name FROM sh_goods WHERE name='%笔'\G
-- ----------------------------
-- 11.2.5 删除索引
-- ----------------------------
-- 1.使用ALTER TABLE语句删除索引
ALTER TABLE sh_goods DROP INDEX ft_index;
SHOW CREATE TABLE sh_goods\G
-- 2.使用DROP INDEX语句删除索引
DROP INDEX name_index ON sh_goods;
SHOW CREATE TABLE sh_goods\G
-- 脚下留心：删除主键索引
DROP INDEX `PRIMARY` ON sh_goods;
-- ----------------------------
-- 11.3.2 表级锁
-- ----------------------------
-- 2.添加“显式”表级锁
CREATE TABLE mydb.table_lock (id int)ENGINE=MyISAM;
INSERT INTO mydb.table_lock VALUES (1),(2);
LOCK TABLE mydb.table_lock READ;
# 在客户端A中执行查询操作
SELECT * FROM mydb.table_lock\G
# 在客户端A中执行更新操作
UPDATE mydb.table_lock SET id=3 WHERE id=1;
# 在客户端A中查看其他未锁定的数据表
SELECT * FROM mydb.index01\G
# 在客户端B中执行查询操作
SELECT * FROM mydb.table_lock\G
# 在客户端B中执行更新操作
UPDATE mydb.table_lock SET id=3 WHERE id=1;
# 在客户端A中释放锁
UNLOCK TABLES;
# 客户端B中会立即执行客户端B的更新的操作
UPDATE mydb.table_lock SET id=3 WHERE id=1;
# 客户端A
LOCK TABLE mydb.table_lock WRITE;
UPDATE mydb.table_lock SET id=1 WHERE id=2;
SELECT * FROM mydb.table_lock\G
# 客户端B
# 执行查询操作
SELECT * FROM mydb.table_lock;
# 执行更新操作
UPDATE mydb.table_lock SET id=1 WHERE id=2;
# 客户端A
UNLOCK TABLES;
# 客户端B
SELECT * FROM mydb.table_lock;
-- 多学一招：添加并发读锁
# 在客户端A中添加并发读锁
LOCK TABLE mydb.table_lock READ LOCAL;
# 在客户端B中插入数据
INSERT INTO mydb.table_lock VALUES (4);
# 在客户端A中释放锁
UNLOCK TABLES;
# 在客户端A中删除id为4的记录
DELETE FROM mydb.table_lock WHERE id=4;
# 在客户端A中添加并发读锁
LOCK TABLE mydb.table_lock READ LOCAL;
# 在客户端B中插入数据
INSERT INTO mydb.table_lock VALUES (4);
-- ----------------------------
-- 11.3.3 行级锁
-- ----------------------------
-- 1.添加“隐式”行级锁
CREATE TABLE mydb.row_lock (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(60) NOT NULL,
    cid INT UNSIGNED,
    KEY cid (cid)
);
INSERT INTO mydb.row_lock (name, cid) VALUES ('铅笔', 3),('风扇', 6), ('绿萝', 1), ('书包', 9), ('纸巾', 20);
# 客户端A
# 开启事务
START TRANSACTION;
# 修改cid等于3的name值
UPDATE mydb.row_lock SET name='cc' WHERE cid=3;
# 客户端B
# 开启事务
START TRANSACTION;
# 删除cid等于2的记录
DELETE FROM mydb.row_lock WHERE cid=2;
# 删除cid等于3的记录
DELETE FROM mydb.row_lock WHERE cid=3;
ROLLBACK;

-- 2.添加“显式”行级锁

# 客户端A
# 开启事务
START TRANSACTION;
# 添加行级排他锁
SELECT * FROM mydb.row_lock WHERE cid=3 FOR UPDATE;

# 客户端B
# 开启事务
START TRANSACTION;
# 添加隐式行级排他锁
UPDATE mydb.row_lock SET name='lili' WHERE cid=2;
LOCK TABLE mydb.row_lock READ;
ROLLBACK;

# 客户端A
START TRANSACTION;
SELECT * FROM mydb.row_lock WHERE cid=3 FOR UPDATE;

# 客户端B
INSERT INTO mydb.row_lock (name, cid) VALUES ('电视', 1);
INSERT INTO mydb.row_lock (name, cid) VALUES ('电视', 2);
INSERT INTO mydb.row_lock (name, cid) VALUES ('电视', 5);
INSERT INTO mydb.row_lock (name, cid) VALUES ('电视', 6);
-- 多学一招：查看InnoDB表的锁
SHOW VARIABLES LIKE 'innodb_status_output_locks';
SET GLOBAL innodb_status_output_locks=ON;
SHOW ENGINE INNODB STATUS\G
-- ----------------------------
-- 11.5.2 创建分区
-- ----------------------------
CREATE TABLE mydb.p_list(
    id INT AUTO_INCREMENT COMMENT 'ID 编号',
    name VARCHAR(50) COMMENT '姓名',
    dpt INT COMMENT '部门编号',
    KEY(id)
)
PARTITION BY LIST(dpt)(
    PARTITION p1 VALUES IN(1,3),
    PARTITION p2 VALUES IN(2,4)
);

USE mydb;
SHOW TABLE STATUS LIKE 'p_list'\G
CREATE TABLE mydb.p_hash(
    id INT AUTO_INCREMENT,
    name VARCHAR(50),
    dpt INT,
    KEY(id)
) ENGINE=INNODB
PARTITION BY HASH(dpt)PARTITIONS 3;
-- ----------------------------
-- 11.5.3 增加分区
-- ----------------------------
# 给p_list数据表添加分区
ALTER TABLE mydb.p_list ADD PARTITION (
    PARTITION new1 values IN (5, 6),
    PARTITION new2 values IN (7, 8)
);
# 给p_hash数据表添加分区
ALTER TABLE mydb.p_hash ADD PARTITION PARTITIONS 1;
-- ----------------------------
-- 11.5.4 删除分区
-- ----------------------------
INSERT INTO mydb.p_list (name, dpt) VALUES ('Tom', 5), ('Lucy', 6), ('Lily', 7), ('Jim', 8);
ALTER TABLE mydb.p_list DROP PARTITION new1;
SELECT * FROM mydb.p_list;
-- ----------------------------
-- 11.6 整理数据碎片
-- ----------------------------
# 创建my_optimize数据表
CREATE TABLE mydb.my_optimize (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20) NOT NULL DEFAULT ''
);
# 添加数据
INSERT INTO mydb.my_optimize (name) VALUES ('TOM'), ('JIMMY'), ('LUCK'), ('CAKE');
INSERT INTO mydb.my_optimize (name) SELECT name FROM mydb.my_optimize;
DELETE FROM mydb.my_optimize WHERE name='LUCK';
OPTIMIZE TABLE mydb.my_optimize\G
-- ----------------------------
-- 11.7.1 慢查询日志
-- ----------------------------
SHOW VARIABLES LIKE 'slow_query%';
SET GLOBAL slow_query_log=ON;
SHOW VARIABLES LIKE 'long_query_time';
SELECT sleep(10);
-- ------------------------------------------------
-- 11.7.2 通过performance_schema进行查询分析
-- ------------------------------------------------
SELECT * from performance_schema.setup_actors;
UPDATE performance_schema.setup_actors SET ENABLED='NO', HISTORY='NO' WHERE HOST='%' AND USER='%';
# 创建test_user用户
CREATE USER 'test_user'@'localhost' IDENTIFIED BY '123456';
# 授予test_user用户权限
GRANT SELECT ON shop.* TO 'test_user'@'localhost';
# 向setup_actors添加一条新记录
INSERT INTO performance_schema.setup_actors (HOST,USER,ROLE,ENABLED,HISTORY) VALUES('localhost','test_user','%','YES','YES');
# 查看setup_actors数据表中的记录
SELECT * FROM performance_schema.setup_actors;

UPDATE performance_schema.setup_instruments SET ENABLED= 'YES', TIMED= 'YES' WHERE NAME LIKE '%stage/%';

UPDATE performance_schema.setup_consumers SET ENABLED = 'YES' WHERE NAME LIKE '%events_statements_%';

UPDATE performance_schema.setup_consumers SET ENABLED = 'YES' WHERE NAME LIKE '%events_stages_%';

SELECT * FROM sh_goods WHERE id=1;
SELECT EVENT_ID, TRUNCATE(TIMER_WAIT/1000000000000,6) as Duration,  SQL_TEXT FROM performance_schema.events_statements_history_long  WHERE SQL_TEXT like '%1%';

SELECT event_name AS Stage, TRUNCATE(TIMER_WAIT/1000000000000,6) AS  Duration FROM performance_schema.events_stages_history_long WHERE NESTING_EVENT_ID=76;
-- -------------------------------
-- 11.8 动手实践:数据库优化实战
-- -------------------------------
#创建用户表my_user
CREATE TABLE IF NOT EXISTS mydb.my_user(
id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '用户编号',
name VARCHAR(120) NOT NULL COMMENT '用户名',
pid INT UNSIGNED NOT NULL COMMENT '部门编号');
# 创建自定义函数
DELIMITER $$
CREATE FUNCTION mydb.rand_str (len INT)
    RETURNS VARCHAR(50) DETERMINISTIC
    BEGIN
    DECLARE chars_str VARCHAR(100) DEFAULT 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    DECLARE res VARCHAR(50) DEFAULT '';
    DECLARE i INT DEFAULT 0;
    WHILE i<len DO
    SET res=CONCAT(res, SUBSTRING(chars_str, FLOOR(1+RAND()*52), 1));
    SET i=i+1;
    END while;
    RETURN res;
    END
    $$
DELIMITER ;
# 创建存储过程
DELIMITER $$
CREATE PROCEDURE mydb.my_user_pro (in max_num INT)
    BEGIN
        DECLARE i INT DEFAULT 0;
        REPEAT
            SET i=i+1;
            INSERT INTO mydb.my_user (name, pid) VALUES
            (rand_str(5), FLOOR(1+RAND()*10));
            UNTIL i=max_num
        END REPEAT;
    END
    $$
DELIMITER ;
#调用my_user_pro存储过程
CALL mydb.my_user_pro(2000000);
SET GLOBAL long_query_time=0.5;
SHOW VARIABLES LIKE 'long_query_time';
SELECT * FROM my_user WHERE name LIKE '%ab%';
SELECT COUNT(*) FROM my_user;
SELECT * FROM my_user LIMIT 90000, 10;
SELECT * FROM my_user WHERE pid=2;
#添加索引
ALTER TABLE mydb.my_user ADD INDEX (pid);
SELECT * FROM my_user WHERE pid=2;
SELECT * FROM mydb.my_user LIMIT 90000, 10;
SELECT * FROM mydb.my_user LIMIT 900000, 10;
SELECT EVENT_ID, TRUNCATE(TIMER_WAIT/1000000000000,6) as Duration, SQL_TEXT FROM performance_schema.events_statements_history_long WHERE SQL_TEXT like '%90000%';
SELECT * FROM mydb.my_user WHERE id>90000 ORDER BY id LIMIT 10;
SELECT * FROM mydb.my_user WHERE id>900000 ORDER BY id LIMIT 10;
SELECT EVENT_ID, TRUNCATE(TIMER_WAIT/1000000000000,6) as Duration, SQL_TEXT FROM performance_schema.events_statements_history_long WHERE SQL_TEXT like '%90000%';
