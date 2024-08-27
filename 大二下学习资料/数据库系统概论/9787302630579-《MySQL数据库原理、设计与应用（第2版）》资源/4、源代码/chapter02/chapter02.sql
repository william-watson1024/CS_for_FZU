-- ----------------------------
-- 2.1.1 创建数据库
-- ----------------------------
CREATE DATABASE test;

-- ----------------------------
-- 2.1.2 查看数据库
-- ----------------------------
-- 1.查看所有数据库
SHOW DATABASES;
-- 2.查看指定数据库的创建信息
SHOW CREATE DATABASE test;

-- ----------------------------
-- 2.1.3 修改数据库
-- ----------------------------
CREATE DATABASE dms CHARACTER SET gbk;
ALTER DATABASE dms CHARACTER SET utf8mb4;
SHOW CREATE DATABASE dms；

-- ----------------------------
-- 2.1.4 选择数据库
-- ----------------------------
USE test;
SELECT DATABASE();

-- ----------------------------
-- 2.1.5 删除数据库
-- ----------------------------
DROP DATABASE test;
SHOW DATABASES LIKE 'test';

-- ----------------------------
-- 2.2.1 创建数据表
-- ----------------------------
SHOW ENGINES;
CREATE DATABASE school;
USE school;
CREATE TABLE student (
     id INT COMMENT '学号',
     name VARCHAR(20) COMMENT '姓名'
) COMMENT '学生表';

-- ----------------------------
-- 2.2.2 查看数据表
-- ----------------------------
-- 1.查看数据库中存在的数据表
USE school;
SHOW TABLES;
-- 2.查看数据表的相关信息
SHOW TABLE STATUS LIKE 'student'\G
-- 3.查看数据表的创建语句
SHOW CREATE TABLE student\G

-- ----------------------------
-- 2.2.3 查看表结构
-- ----------------------------
-- 1.使用DESC语句查看表结构
DESC student;
-- 2.使用SHOW COLUMNS语句查看表结构
SHOW FULL COLUMNS FROM student;

-- ----------------------------
-- 2.2.4 修改数据表
-- ----------------------------
-- 1.修改数据表的名称
ALTER TABLE student RENAME TO stu;
SHOW TABLES;
-- 2.修改字段名
ALTER TABLE stu RENAME COLUMN id TO stuno;
DESC stu;
-- 3.修改字段数据类型
ALTER TABLE stu MODIFY name CHAR(14) COMMENT '姓名';
DESC stu;
-- 4.添加指定字段
ALTER TABLE stu ADD gender CHAR(1) COMMENT '性别';
DESC stu;
-- 5.修改字段排列位置
ALTER TABLE stu CHANGE name name CHAR(14)  AFTER gender;
DESC stu;
-- 6.删除指定字段
ALTER TABLE stu DROP gender;
DESC stu;

-- ----------------------------
-- 2.2.5 删除数据表
-- ----------------------------
DROP TABLE stu;
SHOW TABLES;

-- ----------------------------
-- 2.3.1 添加数据
-- ----------------------------
-- 1.添加单条数据
-- 创建教师表
CREATE TABLE teacher (
     teacherno INT COMMENT '教师编号',
     tname VARCHAR(8) COMMENT '姓名',
     gender VARCHAR(2) COMMENT '性别',
     title VARCHAR(12) COMMENT '职称',
     birth VARCHAR(16) COMMENT '出生年月',
     sal INT COMMENT '基本工资'
) COMMENT '教师表';
-- 向教师表中添加一条数据
INSERT INTO teacher (teacherno, gender, title, birth, tname, sal) 
VALUES (1001, '男', '教授', '1976-01-02', '王志明', 9000);
-- 省略所有字段名的方式添加数据
INSERT INTO teacher VALUES (1002, '王丹', '女', '讲师', '1980-07-12', 5000);
-- 向部分字段添加数据
INSERT INTO teacher (teacherno, tname, title, birth, sal) VALUES (1003, '李庆', '讲师', '1982-08-22', 5500);
-- 使用INSERT语句的SET子句向教师表添加一条数据
INSERT INTO teacher SET teacherno=1004, gender='女',birth='1993-12-02', tname='王红', title='助教';
-- 2.添加多条数据
INSERT INTO teacher VALUES
(1005, '张贺', '男', '讲师', '1978-03-06', 6400),
(1006, '韩芳', '女', '教授', '1971-04-21', 9200),
(1007, '刘阳', '男', '讲师', '1973-09-04', 5800);

-- ----------------------------
-- 2.3.2 查询数据
-- ----------------------------
-- 1.查询数据表中指定字段
SELECT tname FROM teacher;
-- 2.查询数据表中所有数据
SELECT * FROM teacher;

-- ----------------------------
-- 2.3.3 修改数据
-- ----------------------------
-- 1.修改数据表中部分记录的字段数据
UPDATE teacher SET sal=4800 WHERE tname='王红';
SELECT * FROM teacher WHERE tname='王红';
-- 2.修改数据表中所有记录的字段数据
UPDATE teacher SET sal=sal+500;
SELECT * FROM teacher;

-- ----------------------------
-- 2.3.4 删除数据
-- ----------------------------
-- 1.删除数据表中部分记录的数据
DELETE FROM teacher WHERE tname='刘阳';
SELECT * FROM teacher WHERE tname='刘阳';
-- 2.删除数据表中全部记录的数据
DELETE FROM teacher;
SELECT * FROM teacher;

-- --------------------------------------
-- 2.4 动手实践：电子杂志订阅表的操作
-- --------------------------------------
1.创建数据库
# 创建数据库
CREATE DATABASE mydb;
# 选择数据库
USE mydb;
2.创建电子杂志订阅表
CREATE TABLE subscribe (
 id INT COMMENT '编号',
 email VARCHAR(60) COMMENT '订阅邮件的邮箱地址',
 status INT COMMENT '订阅确认状态（0：未确认，1：已确认）',
 code VARCHAR(10) COMMENT '邮箱确认的验证码'
) COMMENT '电子杂志订阅表';
3.添加数据
INSERT INTO subscribe VALUES
(1, 'tom123@mail.test', 1, 'TRBXPO'),
(2, 'lucy123@mail.test', 1, 'LOICPE'),
(3, 'lily123@mail.test', 0, 'JIXDAMI'),
(4, 'jimmy123@mail.test', 0, 'QKOLPH'),
(5, 'joy123@mail.test', 1, 'JSMWNL');
#验证数据是否添加成功
SELECT * FROM subscribe;
4.查询数据
SELECT * FROM subscribe WHERE status=1;
5.修改数据
UPDATE subscribe SET status=1 WHERE id=4;
SELECT * FROM subscribe WHERE id=4;
6.删除数据
DELETE FROM subscribe WHERE id=5;
SELECT * FROM subscribe WHERE id=5;