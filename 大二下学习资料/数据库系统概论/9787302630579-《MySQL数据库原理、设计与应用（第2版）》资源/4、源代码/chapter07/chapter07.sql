-- ----------------------------
-- 7.1 用户与权限概述
-- ----------------------------
-- 1.用户字段
SELECT Host, User FROM mysql.user;
-- 2.用户身份验证字段
SELECT plugin, authentication_string FROM mysql.user WHERE User='root';
-- 3.安全连接字段
SHOW VARIABLES LIKE 'have_openssl';
-- ----------------------------
-- 7.2.1 创建用户
-- ----------------------------
-- 1.创建用户时不设置任何选项
CREATE USER 'test1'@'localhost';
CREATE USER 'test2';
SELECT Host, User FROM mysql.user;
-- 2.创建用户时设置用户身份验证选项
CREATE USER 'test3'@'localhost' IDENTIFIED BY '123456';
SELECT plugin, authentication_string FROM mysql.user WHERE user='test3';
CREATE USER 'test4'@'localhost' IDENTIFIED WITH 'mysql_native_password' BY '123456';
SELECT plugin, authentication_string FROM mysql.user WHERE user='test4';
-- 3.创建用户时设置资源操作选项
CREATE USER 'test5'@'localhost' IDENTIFIED BY '555555' WITH MAX_UPDATES_PER_HOUR 10;
SELECT max_updates FROM mysql.user WHERE user='test5';
-- 4.创建用户时设置密码管理选项
CREATE USER 'test6'@'localhost' IDENTIFIED BY '666666' PASSWORD EXPIRE INTERVAL 180 DAY;
CREATE USER 'test7'@'localhost' IDENTIFIED BY '777777' PASSWORD EXPIRE;
SHOW DATABASES;
-- 5.创建用户时设置账户锁定选项
CREATE USER 'test8'@'localhost' IDENTIFIED BY '888888' ACCOUNT LOCK;
SELECT account_locked FROM mysql.user WHERE user='test8';
-- ----------------------------
-- 7.2.2 修改用户 
-- ----------------------------
-- 1.修改用户身份验证选项
ALTER USER 'test1'@'localhost' IDENTIFIED BY '123456';
ALTER USER CURRENT_USER() IDENTIFIED BY '123456';
SELECT authentication_string FROM mysql.user  WHERE user='test1' AND plugin='caching_sha2_password';
ALTER USER 'test1'@'localhost' IDENTIFIED WITH sha256_password BY '123456';
SELECT authentication_string FROM mysql.user  WHERE user='test1' AND plugin='sha256_password';
-- 多学一招：修改登录密码
SET PASSWORD FOR 'test1'@'localhost' = '123456';
-- 多学一招：root用户密码丢失找回
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '123456';
-- 2.修改资源控制选项
ALTER USER 'test1'@'localhost' WITH max_user_connections 2;
-- 3.修改账户锁定选项
ALTER USER 'test8'@'localhost' ACCOUNT UNLOCK;
-- 多学一招：为用户重命名
RENAME USER 'test8'@'localhost' TO 'test88'@'localhost';
-- ----------------------------
-- 7.2.3 删除用户
-- ----------------------------
DROP USER IF EXISTS 'test88'@'localhost';
-- ----------------------------
-- 7.3.1 授予权限
-- ----------------------------
GRANT SELECT, INSERT (name, price) ON shop.sh_goods TO 'test1'@'localhost';
# 在mysql.tables_priv数据表中查看表权限
SELECT db,table_name,table_priv,column_priv FROM mysql.tables_priv WHERE user ='test1';
# 在mysql.columns_priv数据表中查看列权限
SELECT db,table_name,column_name,column_priv FROM mysql.columns_priv WHERE user='test1';
-- ----------------------------
-- 7.3.2 查看权限 
-- ----------------------------
SHOW GRANTS;
SHOW GRANTS FOR 'test1'@'localhost';
-- ----------------------------
-- 7.3.3 回收权限
-- ----------------------------
REVOKE INSERT (name, price) ON shop.sh_goods FROM 'test1'@'localhost';
INSERT INTO shop.sh_goods(name, price) VALUES('test', 23);
-- -------------------------------
-- 7.4 动手实践：用户与权限练习
-- -------------------------------
#创建shop用户
CREATE USER IF NOT EXISTS 'shop'@'192.168.1.%' IDENTIFIED BY '123456' PASSWORD EXPIRE;
#查看数据库
SHOW DATABASES;
#使用root用户修改shop用户的登录密码
ALTER USER 'shop'@'192.168.1.%' IDENTIFIED BY '2c5-q8h';
#使用shop用户登录MySQL，查看所有数据库
SHOW DATABASES;
#使用root用户给shop用户授予查看shop.sh_goods表的权限
GRANT SELECT ON shop.sh_goods TO 'shop'@'192.168.1.%';
#使用shop用户登录MySQL，查看所有数据库
SHOW DATABASES;
#查看shop用户的权限
SHOW GRANTS FOR 'shop'@'192.168.1.%';
#使用shop用户删除sh_goods数据表
DROP TABLE shop.sh_goods;
#使用root用户回收shop用户对shop.sh_goods表的查看权限
REVOKE SELECT ON shop.sh_goods FROM 'shop'@'192.168.1.%';
#使用shop用户登录客户端，查询shop.sh_goods表
SELECT * FROM shop.sh_goods;
#使用root用户删除用户的方式回收授予此用户的所有权限
DROP USER IF EXISTS 'shop'@'192.168.1.%';
