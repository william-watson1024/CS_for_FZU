-- ----------------------------
-- 5.1.1 复制表结构和数据
-- ----------------------------
-- 1.复制已有的表结构
USE shop;
CREATE TABLE mydb.my_goods (LIKE sh_goods);
SHOW CREATE TABLE mydb.my_goods;
-- 2.复制已有的表数据
INSERT INTO mydb.my_goods SELECT * FROM sh_goods;
INSERT INTO mydb.my_goods SELECT * FROM sh_goods;
INSERT INTO mydb.my_goods (category_id, name, keyword, content, price, stock, score, comment_count) SELECT category_id, name, keyword, content, price, stock, score, comment_count FROM sh_goods;
-- 多学一招：临时表
ALTER TABLE mydb.tmp_table2 RENAME TO mydb.tmp_table3;
DESC mydb.tmp_table3;
-- ----------------------------
-- 5.1.2 解决主键冲突
-- ----------------------------
INSERT INTO mydb.my_goods (id, name, content, keyword) VALUES (20, '橡皮', '修正书写错误', '文具'); 
-- 1. 主键冲突更新
INSERT INTO mydb.my_goods (id, name, content, keyword) VALUES (20, '橡皮', '修正书写错误', '文具') ON DUPLICATE KEY UPDATE name='橡皮', content='修正书写错误', keyword='文具';
SELECT name, content, keyword FROM mydb.my_goods WHERE id=20;
-- 2. 主键冲突替换
REPLACE INTO mydb.my_goods (id, name, content, keyword) VALUES (20, '橡皮', '修正书写错误', '文具');
SELECT name, content, keyword FROM mydb.my_goods WHERE id=20;
-- ----------------------------
-- 5.1.3 清空数据
-- ----------------------------
TRUNCATE TABLE mydb.my_goods;
INSERT INTO mydb.my_goods (name, content, keyword) VALUES ('香蕉', '一种富含钾元素的水果', '水果');
SELECT id, name, content, keyword FROM mydb.my_goods;
DELETE FROM mydb.my_goods;
INSERT INTO mydb.my_goods (name, content, keyword) VALUES ('苹果', '一种很有营养的水果', '水果');
SELECT id, name, content, keyword FROM mydb.my_goods;
-- ----------------------------
-- 5.1.4 去除查询结果中的重复记录
-- ----------------------------
SELECT keyword FROM sh_goods;
SELECT DISTINCT keyword FROM sh_goods;
-- ----------------------------
-- 5.2.1 排序
-- ----------------------------
SELECT category_id, keyword, name, price FROM sh_goods ORDER BY category_id, price DESC;
SELECT category_id, keyword, name, price FROM sh_goods ORDER BY CONVERT(keyword USING gbk) DESC;
-- 多学一招：按指定顺序排序
SELECT category_id, keyword, name, price FROM sh_goods ORDER BY FIELD(keyword, '办公', '服装', '电子产品');
-- ----------------------------
-- 5.2.2 限量
-- ----------------------------
-- 1. 获取限量查询记录
SELECT id, name, price FROM sh_goods ORDER BY price;
SELECT id, name, price FROM sh_goods ORDER BY price LIMIT 1;
-- 2.获取指定区间的记录
SELECT id, name, price FROM sh_goods ORDER BY price LIMIT 0, 5;
-- 多学一招：对修改或删除操作进行排序和限量
UPDATE sh_goods SET stock=500 ORDER BY price LIMIT 2;
SELECT id, name, price, stock FROM sh_goods ORDER BY price LIMIT 2;
-- ----------------------------
-- 5.3.1 分组
-- ----------------------------
SELECT keyword FROM sh_goods GROUP BY keyword;
-- ----------------------------
-- 5.3.2 聚合函数
-- ----------------------------
-- 4. MAX()函数和MIN()函数
SELECT MAX(price), MIN(price) FROM sh_goods;
-- 5. JSON_ARRAYAGG()函数和JSON_OBJECTAGG()函数
SELECT JSON_ARRAYAGG(id) AS '[编号]', JSON_OBJECTAGG(id, name) AS '{编号：名称}' FROM sh_goods\G
-- ----------------------------
-- 5.3.3 分组并使用聚合函数
-- ----------------------------
SELECT category_id, MAX(price) FROM sh_goods GROUP BY category_id;
-- ----------------------------
-- 5.3.4 分组后进行条件筛选
-- ----------------------------
SELECT score, comment_count, GROUP_CONCAT(id) FROM sh_goods GROUP BY score, comment_count HAVING COUNT(*)=2;
-- 多学一招：在查询中使用别名
SELECT category_id cid, MIN(price) min_price FROM sh_goods GROUP BY cid HAVING cid=3 OR cid=6;
-- ----------------------------
-- 5.3.5 回溯统计
-- ----------------------------
SELECT category_id, COUNT(*) FROM sh_goods GROUP BY category_id WITH ROLLUP;
SELECT score, comment_count, COUNT(*) FROM sh_goods GROUP BY score, comment_count WITH ROLLUP;
-- ----------------------------
-- 5.4.1 算术运算符
-- ----------------------------
-- 1.无符号的加减乘法运算
SELECT id, id+1, id-1, id*2 FROM sh_goods LIMIT 5;
-- 2.无符号的减法运算
SELECT id-2 FROM sh_goods LIMIT 5;
SELECT CAST(id AS SIGNED)-2 FROM sh_goods LIMIT 5;
-- 3.含有精度的运算
SELECT name, price, stock, price*0.75, stock+850.00 FROM sh_goods WHERE score=5;
-- 4.除法运算
SHOW VARIABLES LIKE 'div_precision_increment';
SELECT name, stock, stock/5 FROM sh_goods WHERE stock>200;
-- 5.NULL参与算术运算
SELECT NULL+1, 3-NULL, 7*NULL, 2/NULL, NULL/3;
-- 6.DIV运算符
SELECT 9/5, 9 DIV 5, 0.6/1.2, 0.6 DIV 1.2;
-- 7.MOD运算符
SELECT 9 MOD 5, -9 MOD 5, 9 MOD -5, -9 MOD -5;
-- ----------------------------
-- 5.4.2 比较运算符
-- ----------------------------
SELECT '5'>=5, 3.0<>3;
SELECT 0=NULL, NULL>1, NULL<2, NULL>=3, NULL<=4, NULL<>5, NULL!=6;
SELECT NULL=NULL, NULL=1, NULL<=>NULL, NULL<=>1;
-- 1.BETWEEN…END…与NOT BETWEEN…END…
SELECT id, name, price FROM sh_goods WHERE price BETWEEN 2000 AND 6000;
SELECT id, name, price FROM sh_goods WHERE price NOT BETWEEN 2000 AND 6000;
-- 2.IS NULL与IS NOT NULL
SELECT id, name, price, keyword FROM sh_goods WHERE keyword IS NOT NULL ORDER BY price DESC LIMIT 2;
-- 3.LIKE与NOT LIKE
SELECT id, name, price, content FROM sh_goods WHERE name LIKE '%笔%';
-- 4.REGEXP
SELECT id, name, content FROM sh_goods WHERE content REGEXP '人|必备';
-- ----------------------------
-- 5.4.3 逻辑运算符
-- ----------------------------
-- 1.NOT
SELECT NOT 10, NOT 0, NOT NULL, NOT 1;
-- 2.AND
SELECT 1 AND NULL, NULL AND 1, 0 AND NULL, 1 AND 0, 1 AND 1;
SELECT id, name, price FROM sh_goods WHERE keyword='电子产品' AND score=5;
-- 3.OR
SELECT 1 OR NULL, 0 OR NULL, 1 OR 0, 1 OR 1, 0 OR 0;
SELECT id, name, price, score FROM sh_goods WHERE score=4.5 OR price<10;
-- 4.XOR
SELECT 1 XOR 1, 1 XOR 0, 1 XOR NULL, 1 XOR 1 XOR 1;
-- ----------------------------
-- 5.4.4 赋值运算符
-- ----------------------------
SELECT id, name, stock FROM sh_goods WHERE score=4.5;
-- ----------------------------
-- 5.4.5 位运算符
-- ----------------------------
SELECT 1&10, 1|10, 1^10, 1<<2, 1>>2, 10&~1;
-- ----------------------------
-- 5.4.6 运算符优先级
-- ----------------------------
SELECT (2+4)*3, 2+4*3;
-- --------------------------------
-- 5.5 动手实践:商品评论表的操作
-- --------------------------------
#查询商品id等于9且有效的评论内容
SELECT id, content FROM sh_goods_comment WHERE goods_id=9 AND is_show=1;
#查询每个用户评论的商品数量
SELECT user_id, COUNT(goods_id) FROM sh_goods_comment GROUP BY user_id;
#查询最新发布的4条有效商品评论内容
SELECT id, content, user_id, goods_id FROM sh_goods_comment WHERE is_show=1 ORDER BY create_time DESC LIMIT 4;
#查询评论过两种以上不同商品的用户id及对应的商品id
SELECT user_id, GROUP_CONCAT(goods_id) FROM sh_goods_comment GROUP BY user_id HAVING COUNT(DISTINCT goods_id)>=2;
#结合sh_goods表和sh_goods_comment表，查询没有任何评论信息的商品id和name
SELECT DISTINCT goods_id FROM sh_goods_comment;
SELECT id, name FROM sh_goods WHERE id <> 8 AND id <> 10 AND id <> 9 AND id <> 4 AND id <> 7 AND id <> 5;
#结合sh_goods表和sh_goods_comment表，查询商品评分为5星的商品评论信息
SELECT id FROM sh_goods WHERE score=5;
SELECT id, content FROM sh_goods_comment WHERE goods_id = 3 OR goods_id = 5;