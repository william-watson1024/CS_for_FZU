-- ----------------------------
-- 3.1.1 数值类型
-- ----------------------------
-- 1.整数类型
USE dms;
CREATE TABLE my_int (
     int_1 INT,
     int_2 INT UNSIGNED,
     int_3 TINYINT,
     int_4 TINYINT UNSIGNED
);
INSERT INTO my_int VALUES (1000, 1000, 100, 100);
INSERT INTO my_int VALUES (1000, -1000, 100, 100);
-- 2.浮点数类型
CREATE TABLE my_float (
     f1 FLOAT,
     f2 FLOAT
);
INSERT INTO my_float VALUES (111111, 1.11111);
INSERT INTO my_float VALUES (1111111, 1.111111);
INSERT INTO my_float VALUES (1111114, 1111115);
INSERT INTO my_float VALUES (11111149, 11111159);
SELECT * FROM my_float;
-- 3.定点数类型
CREATE TABLE my_decimal (
     d1 DECIMAL(4,2),
     d2 DECIMAL(4,2)
);
INSERT INTO my_decimal VALUES (1.234, 1.235);
SHOW WARNINGS;
SELECT * FROM my_decimal;
INSERT INTO my_decimal VALUES (99.99, 99.999);
-- 4.BIT（位）类型
SELECT ASCII('A');
SELECT BIN(65), LENGTH(BIN(65));
CREATE TABLE my_bit (b BIT(7));
INSERT INTO my_bit VALUES (65);
SELECT * FROM my_bit;
SELECT BIN(b) FROM my_bit;
-- ----------------------------
-- 3.1.2 日期和时间类型
-- ----------------------------
-- 1.YEAR类型
CREATE TABLE my_year (y YEAR);
INSERT INTO my_year VALUES (2022), ('22'), (22);
SELECT * FROM my_year;
-- 2.DATE类型
CREATE TABLE my_date (d DATE);
INSERT INTO my_date VALUES ('2022-01-02');
INSERT INTO my_date VALUES (CURRENT_DATE);
INSERT INTO my_date VALUES (NOW());
SELECT * FROM my_date;
-- 3.TIME类型
CREATE TABLE my_time (t TIME);
INSERT INTO my_time VALUES ('345454');
INSERT INTO my_time VALUES ('2 11:30:50');
INSERT INTO my_time VALUES (CURRENT_TIME);
INSERT INTO my_time VALUES (NOW());
SELECT * FROM my_time;
-- 4.DATETIME类型
CREATE TABLE my_datetime (d DATETIME);
INSERT INTO my_datetime VALUES ('2022-01-22 09:01:23');
INSERT INTO my_datetime VALUES (NOW());
SELECT * FROM my_datetime;
-- 5.TIMESTAMP类型
CREATE TABLE my_timestamp (t TIMESTAMP);
INSERT INTO my_timestamp VALUES (CURRENT_TIMESTAMP);
SELECT * FROM my_timestamp;
-- ----------------------------
-- 3.1.3 字符串类型
-- ----------------------------
-- 2.BINARY和VARBINARY
CREATE TABLE my_binary (
     f1 BINARY,
     f2 BINARY(3),
     f3 VARBINARY(10)
);
INSERT INTO my_binary (f1) VALUES ('我');
INSERT INTO my_binary (f1, f2) VALUES ('a', 'a');
INSERT INTO my_binary (f2) VALUES ('我');
INSERT INTO my_binary (f1, f2) VALUES ('a', 'abc');
INSERT INTO my_binary (f2, f3) VALUES ('ab', 'ab');
-- 4.BLOB系列
CREATE TABLE my_blob (
     id INT,
     img MEDIUMBLOB
);
INSERT INTO my_blob (id) VALUES (9001);
SELECT * FROM my_blob;
-- 5.ENUM类型
CREATE TABLE my_enum (gender ENUM('male', 'female'));
INSERT INTO my_enum VALUES ('male'), ('female');
SELECT * FROM my_enum WHERE gender='female';
INSERT INTO my_enum VALUES('m');
-- 6.SET类型
CREATE TABLE my_set (hobby SET('book', 'game', 'code'));
INSERT INTO my_set VALUES (''), ('book'), ('book,code');
SELECT * FROM my_set WHERE hobby='book,code';
-- 多学一招：JSON数据类型
CREATE TABLE my_json (j1 JSON, j2 JSON);
INSERT INTO my_json VALUES ('{"k1": "value", "k2": 10}', '["run", "sing"]');
SELECT * FROM my_json;

-- ----------------------------
-- 3.2.1 设置默认值约束
-- ----------------------------
CREATE TABLE my_default (
     name VARCHAR(10),
     age TINYINT UNSIGNED DEFAULT 18
);
DESC my_default;
INSERT INTO my_default VALUES ();
SELECT * FROM my_default;
INSERT INTO my_default (name) VALUES ('a');
SELECT * FROM my_default;
INSERT INTO my_default VALUES ('b', NULL);
SELECT * FROM my_default;
INSERT INTO my_default VALUES ('c', DEFAULT);
SELECT * FROM my_default;
ALTER TABLE my_default MODIFY age TINYINT UNSIGNED;
DESC my_default;
-- ----------------------------
-- 3.2.2 设置非空约束
-- ----------------------------
CREATE TABLE my_not_null (
     n1 INT,
     n2 INT NOT NULL,
     n3 INT NOT NULL DEFAULT 18
);
DESC my_not_null;
INSERT INTO my_not_null VALUES ();
INSERT INTO my_not_null VALUES (NULL, NULL, NULL);
INSERT INTO my_not_null VALUES (NULL, 20, NULL);
INSERT INTO my_not_null (n2) VALUES (20);
SELECT * FROM my_not_null;
-- ----------------------------
-- 3.2.3 设置唯一约束
-- ----------------------------
-- 创建数据表时为单个字段添加唯一约束
CREATE TABLE my_unique1 (
     id INT UNIQUE,
     username VARCHAR(10) UNIQUE
);
CREATE TABLE my_unique2 (
     id INT,
     username VARCHAR(10),
     UNIQUE (id),
     UNIQUE (username)
);
DESC my_unique1;
DESC my_unique2;
INSERT INTO my_unique1 (id) VALUES (1);
INSERT INTO my_unique1 (id) VALUES (2);
INSERT INTO my_unique1 (id) VALUES (1);
SELECT * FROM my_unique1;
CREATE TABLE my_unique3 (id INT);
ALTER TABLE my_unique3 ADD UNIQUE(id);
SHOW CREATE TABLE my_unique3\G
ALTER TABLE my_unique3 DROP INDEX id;
SHOW CREATE TABLE my_unique3\G
-- 创建数据表时为多个字段添加唯一约束
CREATE TABLE my_unique4 (
     id INT,
     username VARCHAR(10),
     UNIQUE (id, username)
);
INSERT INTO my_unique4 VALUES (1, '小明');
INSERT INTO my_unique4 VALUES (1, '小红');
SELECT * FROM my_unique4;
INSERT INTO my_unique4 VALUES (1, '小红');

-- ----------------------------
-- 3.2.4 设置主键约束
-- ----------------------------
-- 创建数据表时为单字段设置主键约束
CREATE TABLE my_primary (
     id INT PRIMARY KEY,
     username VARCHAR(20)
);
DESC my_primary;
INSERT INTO my_primary VALUES (1, 'Tom');
INSERT INTO my_primary VALUES (NULL, 'Jack');
INSERT INTO my_primary VALUES (1, 'Alex');
ALTER TABLE my_primary DROP PRIMARY KEY;
DESC my_primary;
ALTER TABLE my_primary MODIFY id INT;
DESC my_primary;
-- 为现有数据表中的单字段添加主键约束
ALTER TABLE my_primary ADD PRIMARY KEY (id);
DESC my_primary;
-- ----------------------------
-- 3.3 自动增长
-- ----------------------------
CREATE TABLE my_auto (
     id INT PRIMARY KEY AUTO_INCREMENT,
     username VARCHAR(20)
);
DESC my_auto;
INSERT INTO my_auto (username) VALUES('a');
SELECT * FROM my_auto;
INSERT INTO my_auto VALUES (NULL, 'b');
SELECT * FROM my_auto;
INSERT INTO my_auto VALUES (5, 'c');
SELECT * FROM my_auto;
INSERT INTO my_auto VALUES (0, 'd');
SELECT * FROM my_auto;
INSERT INTO my_auto VALUES (DEFAULT, 'e');
SELECT * FROM my_auto;
SHOW CREATE TABLE my_auto\G
ALTER TABLE my_auto AUTO_INCREMENT=10;
ALTER TABLE my_auto MODIFY id INT;
ALTER TABLE my_auto MODIFY id INT AUTO_INCREMENT;
-- 多学一招：查看系统变量的语句
SHOW VARIABLES LIKE 'auto_inc%';
-- ----------------------------
-- 3.4.1 字符集概述
-- ----------------------------
SHOW CHARACTER SET;
SHOW CHARACTER SET LIKE 'utf%';
-- ----------------------------
-- 3.4.2 校对集概述
-- ----------------------------
SHOW COLLATION;
SHOW COLLATION WHERE `Default` = 'Yes';
-- ----------------------------
-- 3.4.3 字符集与校对集的设置
-- ----------------------------
SHOW VARIABLES LIKE 'character%';
-- ----------------------------
-- 3.5 动手实践:设计用户表
-- ----------------------------
#在mydb数据库中创建用户表user
CREATE TABLE mydb.user (
    id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '用户id',
    username VARCHAR(20) UNIQUE NOT NULL COMMENT '用户名',
    mobile CHAR(11) NOT NULL COMMENT '手机号码',
    gender ENUM('男', '女', '保密') NOT NULL COMMENT '性别',
    reg_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '注册时间',
    level TINYINT UNSIGNED NOT NULL COMMENT '会员等级'
) COMMENT '用户表';
#添加数据
INSERT INTO mydb.user VALUES (NULL, '小明', '12311111111', '男', '2022-06-14 11:11:11', 1);
#查询数据
SELECT * FROM mydb.user;