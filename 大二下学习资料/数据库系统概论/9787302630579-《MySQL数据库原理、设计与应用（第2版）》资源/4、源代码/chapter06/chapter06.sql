-- ----------------------------
-- 6.1 联合查询
-- ----------------------------
USE shop;
SELECT id, name, price FROM sh_goods WHERE category_id=9 UNION SELECT id, name, keyword FROM sh_goods WHERE category_id=6;
# 使用联合查询对sh_goods表中category_id为3的商品按价格升序排序，其他类型的产品按价格降序排序
(SELECT id, name, price, category_id  FROM sh_goods
 WHERE category_id=3 ORDER BY price LIMIT 3)
UNION (SELECT id, name, price, category_id FROM sh_goods WHERE category_id<>3 ORDER BY price DESC LIMIT 7);
-- ----------------------------
-- 6.2.1 交叉连接查询
-- ----------------------------
SELECT c.id cid, c.name cname, g.id gid, g.name gname FROM sh_goods_category c CROSS JOIN sh_goods g ORDER BY c.id, g.id;
-- ----------------------------
-- 6.2.2 内连接查询
-- ----------------------------
SELECT g.id gid, g.name gname, c.id cid, c.name cname FROM sh_goods_category c JOIN sh_goods g ON g.category_id=c.id;
-- 多学一招：自连接查询
SELECT DISTINCT g1.id, g1.name FROM sh_goods g1 JOIN sh_goods g2 ON g2.name='钢笔T1616' AND g2.category_id=g1.category_id;
-- ----------------------------
-- 6.2.3 外连接查询
-- ----------------------------
-- 1.左外连接查询
SELECT g.name gname, g.score gscore, c.name cname FROM sh_goods g LEFT JOIN sh_goods_category c ON g.category_id=c.id AND g.score=5 ORDER BY g.score;
-- 2.右外连接查询
SELECT g.name gname, g.score gscore, c.name cname FROM sh_goods g RIGHT JOIN sh_goods_category c ON g.category_id=c.id AND g.score=5 ORDER BY g.score DESC;
-- 多学一招：USING关键字
SELECT DISTINCT g1.id, g1.name FROM sh_goods g1 JOIN sh_goods g2 USING(category_id) WHERE g2.name='钢笔T1616';
-- ----------------------------
-- 6.3.1 子查询的分类
-- ----------------------------
-- 1.标量子查询
SELECT name FROM sh_goods_category WHERE id=(SELECT category_id FROM sh_goods WHERE name='钢笔T1616');
-- 2.列子查询
SELECT name FROM sh_goods_category WHERE id IN(SELECT DISTINCT category_id FROM sh_goods);
-- 3.行子查询
SELECT id, name, price, score, content FROM sh_goods WHERE (price, score)=(SELECT MAX(price), MIN(score) FROM sh_goods);
-- 4.表子查询
SELECT a.id, a.name, a.price, a.category_id FROM sh_goods a, (SELECT category_id, MAX(price) max_price FROM sh_goods GROUP BY category_id) b WHERE a.category_id=b.category_id AND a.price=b.max_price;
-- 5.EXISTS子查询
UPDATE sh_goods SET name='电饭煲', price=400, category_id=(SELECT id FROM sh_goods_category WHERE name='厨具') WHERE EXISTS(SELECT id FROM sh_goods_category WHERE name='厨具') AND id=5;
-- ----------------------------
-- 6.3.2 子查询关键字
-- ----------------------------
-- 1.ANY关键字结合子查询
SELECT name FROM sh_goods_category WHERE id= ANY(SELECT DISTINCT category_id FROM sh_goods WHERE price<200);
SELECT name FROM sh_goods_category WHERE id<> ANY(SELECT DISTINCT category_id FROM sh_goods WHERE price<200);
-- 2.ALL关键字结合子查询
SELECT id, name, price, keyword FROM sh_goods WHERE category_id=3 AND price< ALL(SELECT DISTINCT price FROM sh_goods WHERE category_id=8);
-- ----------------------------
-- 6.4.2 添加外键约束
-- ----------------------------
-- 1.创建数据表时添加外键约束
CREATE TABLE mydb.department (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '部门编号',
    name VARCHAR(50) NOT NULL COMMENT '部门名称'
) COMMENT '部门表';
CREATE TABLE mydb.employees (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '员工编号',
    name VARCHAR(120) NOT NULL COMMENT '员工姓名',
    dept_id INT UNSIGNED NOT NULL COMMENT '部门编号',
    CONSTRAINT FK_ID FOREIGN KEY(dept_id) REFERENCES department(id)
    ON DELETE RESTRICT ON UPDATE CASCADE
) COMMENT '员工表';
-- 2.修改数据表时添加外键约束
DROP TABLE mydb.employees;
CREATE TABLE mydb.employees (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '员工编号',
    name VARCHAR(120) NOT NULL COMMENT '员工姓名',
    dept_id INT UNSIGNED NOT NULL COMMENT '部门编号'
) COMMENT '员工表';
ALTER TABLE mydb.employees ADD CONSTRAINT FK_ID FOREIGN KEY(dept_id) REFERENCES department(id) ON DELETE RESTRICT ON UPDATE CASCADE;
DESC mydb.employees dept_id;
SHOW CREATE TABLE mydb.employees\G
-- ----------------------------
-- 6.4.3 关联表操作 
-- ----------------------------
-- 1.添加数据
INSERT INTO mydb.employees (name, dept_id) VALUES ('Tom', 3);
INSERT INTO mydb.department (id, name) VALUES (3, '研发部');
INSERT INTO mydb.employees (name, dept_id) VALUES ('Tom', 3);
-- 2.更新数据
UPDATE mydb.department SET id=1 WHERE name='研发部';
SELECT * FROM mydb.department;
SELECT * FROM mydb.employees;
-- 3.删除数据
DELETE FROM mydb.department WHERE id=1;
DELETE FROM mydb.employees WHERE dept_id=1;
DELETE FROM mydb.department WHERE id=1;
-- ----------------------------
-- 6.4.4 删除外键约束
-- ----------------------------
ALTER TABLE mydb.employees DROP FOREIGN KEY FK_ID;
DESC mydb.employees dept_id;
ALTER TABLE mydb.employees DROP KEY FK_ID;
-- ----------------------------
-- 6.5 动手实践:多表查询练习
-- ----------------------------
#查询sh_goods_attr表中category_id为6所对应的商品的属性信息，将属性按照层级进行升序排列
SELECT a.sort sort1, a.name name1, b.sort sort2, b.name name2 FROM sh_goods_attr a JOIN sh_goods_attr b ON a.id=b.parent_id WHERE a.category_id=6 ORDER BY a.sort, b.sort;
#查询sh_goods_attr_value表中goods_id为5的商品所具有的属性信息，显示属性名称和属性值
SELECT b.name, a.attr_value FROM sh_goods_attr_value a JOIN sh_goods_attr b ON a.attr_id=b.id WHERE a.goods_id=5;
#查询sh_goods_attr表中parent_id为1的属性包含的所有子属性值
SELECT attr_value FROM sh_goods_attr_value WHERE attr_id IN (SELECT id FROM sh_goods_attr WHERE parent_id=1);
#查询拥有属性值个数大于1的商品的id和name
SELECT id, name FROM sh_goods WHERE id IN (SELECT goods_id FROM sh_goods_attr_value GROUP BY goods_id HAVING COUNT(id)>1);