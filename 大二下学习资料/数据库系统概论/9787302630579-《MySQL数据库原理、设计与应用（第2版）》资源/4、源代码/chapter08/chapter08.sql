-- ----------------------------
-- 8.2.1 创建视图
-- ----------------------------
-- 1.创建基于单表的视图
USE shop;
CREATE VIEW view_goods AS SELECT id, name, price FROM sh_goods;
SELECT * FROM view_goods LIMIT 3;
-- 2.创建基于多表的视图
CREATE VIEW view_goods_cate AS SELECT g.id, g.name, c.name category_name FROM sh_goods g LEFT JOIN sh_goods_category c ON g.category_id=c.id;
SELECT * FROM view_goods_cate LIMIT 3;
-- 多学一招：创建视图时自定义字段列表
CREATE VIEW view_goods_promo (sn, title, promotion_price) AS SELECT id, name, price*0.8 FROM sh_goods;
SELECT * FROM view_goods_promo WHERE sn<=3;
-- 多学一招：视图安全控制
CREATE USER shop_test;
CREATE VIEW view_goods_t1 AS SELECT id, name FROM sh_goods LIMIT 1;
CREATE DEFINER='shop_test' VIEW view_goods_t2 AS SELECT id, name FROM sh_goods LIMIT 1;
CREATE SQL SECURITY INVOKER VIEW view_goods_t3 AS SELECT id, name FROM sh_goods LIMIT 1;
GRANT SELECT ON view_goods_t1 TO 'shop_test';
GRANT SELECT ON view_goods_t2 TO 'shop_test';
GRANT SELECT ON view_goods_t3 TO 'shop_test';
# 选择shop数据库
USE shop;
# 查询视图view_goods_t1
SELECT * FROM view_goods_t1;
# 查询视图view_goods_t2
SELECT * FROM view_goods_t2;
# 查询视图view_goods_t3
SELECT * FROM view_goods_t3;
-- ----------------------------
-- 8.2.2 查看视图 
-- ----------------------------
-- 1.查看视图的字段信息
DESC view_goods_cate;
-- 2.查看视图状态信息
SHOW TABLE STATUS LIKE 'view_goods_cate'\G
-- 3.查看视图的创建语句
SHOW CREATE VIEW view_goods_cate\G
-- ----------------------------
-- 8.2.3 修改视图
-- ----------------------------
-- 1.使用CREATE OR REPLACE VIEW语句修改视图
DESC view_goods;
CREATE OR REPLACE VIEW view_goods AS SELECT id, name FROM sh_goods;
DESC view_goods;
-- 2.使用ALTER VIEW语句修改视图
ALTER VIEW view_goods AS SELECT id FROM sh_goods;
DESC view_goods;
-- ----------------------------
-- 8.2.4 删除视图
-- ----------------------------
# 删除视图
DROP VIEW view_goods;
# 检查视图是否已被删除
SELECT * FROM view_goods;
-- ----------------------------
-- 8.3.1 添加数据
-- ----------------------------
# 创建视图view_category
CREATE VIEW view_category AS SELECT id, name FROM sh_goods_category;
# 向视图中添加数据 
INSERT INTO view_category VALUES (17, '图书');
# 查询添加后的数据 
SELECT id, name FROM sh_goods_category WHERE id=17;
CREATE VIEW view_cate_t1 AS SELECT id, name FROM sh_goods_category WHERE id<30;
CREATE VIEW view_cate_t2 AS SELECT id, name FROM view_cate_t1 WHERE id>20 WITH CHECK OPTION;  
INSERT INTO view_cate_t2 VALUES (17, 'test');
INSERT INTO view_cate_t2 VALUES (21, 'test');
INSERT INTO view_cate_t2 VALUES (30, 'test');
CREATE VIEW view_cate_t3 AS SELECT id, name FROM view_cate_t1 WHERE id>20 WITH LOCAL CHECK OPTION;
INSERT INTO view_cate_t3 VALUES (30, 'test');
-- ----------------------------
-- 8.3.2 修改数据
-- ----------------------------
# 修改数据
UPDATE view_category SET name='家电' WHERE id=17;
# 查询修改后的数据
SELECT id, name FROM sh_goods_category WHERE id=17;
-- ----------------------------
-- 8.3.3 删除数据
-- ----------------------------
# 删除数据
DELETE FROM view_category WHERE id=17 OR id=21 OR id=30;
# 查询数据是否已经删除
SELECT id, name FROM sh_goods_category WHERE id=17;
-- ----------------------------
-- 8.4 动手实践：视图的应用
-- ----------------------------
#创建sh_view_cate_attr视图
CREATE VIEW sh_view_cate_attr AS
SELECT a.sort sort1, a.name attr1, b.sort sort2, b.name attr2,
b.category_id FROM sh_goods_attr a
JOIN sh_goods_attr b ON a.id=b.parent_id
WHERE b.parent_id!=0 ORDER BY a.sort ASC, b.sort ASC;
#查询sh_view_cate_attr视图
SELECT * FROM sh_view_cate_attr WHERE category_id=6;
#创建sh_view_goods_attr视图
CREATE VIEW sh_view_goods_attr AS
SELECT b.name attr1, a.name attr2, c.attr_value, c.goods_id
FROM sh_goods_attr a
JOIN sh_goods_attr b ON a.parent_id=b.id
JOIN sh_goods_attr_value c ON a.id=c.attr_id
WHERE a.parent_id !=0 ORDER BY b.sort ASC, a.sort ASC;
#查询sh_view_goods_attr视图
SELECT * FROM sh_view_goods_attr WHERE goods_id=5;
