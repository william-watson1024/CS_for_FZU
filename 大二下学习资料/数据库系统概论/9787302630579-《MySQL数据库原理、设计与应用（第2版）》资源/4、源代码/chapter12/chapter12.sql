-- ----------------------------
-- 12.1.1 使用APT安装MySQL
-- ----------------------------
-- 4.登录MySQL服务器并设置登录密码
ALTER USER 'root'@'localhost'  IDENTIFIED WITH 'caching_sha2_password' BY '123456';

-- ----------------------------
-- 12.1.2 编译安装MySQL
-- ----------------------------

-- 10.登录MySQL
ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
exit;
-- 多学一招：创建远程登录用户
CREATE DATABASE mydb;
CREATE USER 'mydb'@'192.168.48.1' IDENTIFIED BY '123456';
GRANT ALL PRIVILEGES ON mydb.* TO 'mydb'@'192.168.48.1';
exit;
SHOW DATABASES;
-- ----------------------------
-- 12.3.1 数据备份
-- ----------------------------
CREATE DATABASE IF NOT EXISTS test1;
CREATE TABLE test1.goods (id INT, name VARCHAR(32));
INSERT INTO test1.goods VALUES (1, 'book'),(2, 'apple');
exit;
-- ----------------------------
-- 12.3.2 数据还原
-- ----------------------------
-- 1.使用mysql命令还原数据
CREATE DATABASE test2;
exit;
SELECT id, name FROM goods;
-- 2.使用source命令还原数据
CREATE DATABASE test3;
USE test3;
source ~/test.sql
SELECT id, name FROM goods;
-- ----------------------------
-- 12.3.3 二进制日志
-- ----------------------------
-- 1.查看二进制日志状态
SHOW VARIABLES LIKE 'log_bin%';
-- 2.查看二进制日志文件
SHOW BINARY LOGS;
-- ----------------------------
-- 12.3.3 二进制日志
-- ----------------------------
-- 2.查看二进制日志文件
SHOW VARIABLES LIKE 'log_bin%';
SHOW BINARY LOGS;
-- 3.查看二进制日志内容
SHOW MASTER STATUS\G
-- 4.暂停二进制日志
SET sql_log_bin=0;
SET sql_log_bin=1;
-- 5.删除二进制日志
RESET MASTER;
PURGE MASTER LOGS TO 'binlog.000002';
PURGE MASTER LOGS BEFORE '20220801';
-- ----------------------------
-- 12.4 多实例部署
-- ----------------------------
-- 4.登录并设置密码
ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
-- ----------------------------
-- 12.5.3 实现主从复制
-- ----------------------------
-- 2.在主服务器中创建用户
# 创建slave 用户
CREATE USER 'slave'@'127.0.0.1' IDENTIFIED BY '123456';
# 为用户赋予REPLICATION SLAVE 权限
GRANT REPLICATION SLAVE ON *.* TO 'slave'@'127.0.0.1';
-- 3.查看主服务器当前的二进制日志状态
SHOW MASTER STATUS;
-- 4.从服务器同步数据
# 指定主服务器的信息
CHANGE REPLICATION SOURCE TO SOURCE_HOST='127.0.0.1',  SOURCE_PORT=3307, SOURCE_LOG_FILE='binlog.000001',  SOURCE_LOG_POS=1027, GET_SOURCE_PUBLIC_KEY=1;
# 使用slave 用户开始同步
START REPLICA USER='slave' PASSWORD='123456';
-- 5.查看从服务器的同步状态
SHOW REPLICA STATUS\G
-- 6.测试主从复制
CREATE DATABASE mydb;
CREATE TABLE mydb.test (id INT);
INSERT INTO mydb.test VALUES (1);
SELECT * FROM mydb.test;
# 在从服务器中写入数据
INSERT INTO mydb.test VALUES (2);
# 在主服务器中读取数据
SELECT * FROM mydb.test;
# 将主服务器中的test数据表删除
DROP TABLE mydb.test;
-- ----------------------------
-- 12.6 动手实践：读写分离
-- ----------------------------
SHOW DATABASES;
# 切换至MYDB_RW数据库
USE MYDB_RW;
# 创建test数据表插入测试数据
CREATE TABLE mydb.test (id INT, name VARCHAR(10));
INSERT INTO mydb.test VALUES (1,'TOM'),(2,'SUN');
UPDATE mydb.test SET name='SUN1' WHERE id=2;
# 查看主数据库中的数据
SELECT * FROM mydb.test;
# 查看从数据库中的数据
SELECT * FROM mydb.test;
#在MyCat服务器中查询test数据表中的数据
SELECT * FROM mydb.test;
