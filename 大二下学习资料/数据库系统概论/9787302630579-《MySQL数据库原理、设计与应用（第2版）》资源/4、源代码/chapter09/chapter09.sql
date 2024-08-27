-- ----------------------------
-- 9.2.1 事务的基本操作
-- ----------------------------
# 选择shop数据库
USE shop;
# 查看用户数据
SELECT name, money FROM sh_user;
# 开启事务
START TRANSACTION;
# Alex的金额减少100元
UPDATE sh_user SET money=money-100 WHERE name='Alex';
# Bill的金额增加100元
UPDATE sh_user SET money=money+100 WHERE name='Bill';
# 提交事务
COMMIT;
SELECT name, money FROM sh_user;
# 开启事务
START TRANSACTION;
# 将Bill的金额扣除100元
UPDATE sh_user SET money=money-100 WHERE name='Bill';
# 查询Bill的金额
SELECT name, money FROM sh_user WHERE name='Bill';
# 回滚事务
ROLLBACK;
# 查询Bill的金额
SELECT name, money FROM sh_user WHERE name='Bill';
多学一招：设置事务的自动提交方式
SELECT @@autocommit;
SET AUTOCOMMIT=0;
-- ----------------------------
-- 9.2.2 事务的保存点
-- ----------------------------
SELECT name, money FROM sh_user WHERE name ='Alex';
# 开启事务
START TRANSACTION;
# Alex的金额扣除100元
UPDATE sh_user SET money=money-100 WHERE name='Alex';
# 创建保存点s1
SAVEPOINT s1;
# Alex的金额再扣除50元
UPDATE sh_user SET money=money-50 WHERE name='Alex';
# 回滚到保存点s1
ROLLBACK TO SAVEPOINT s1;
# 查询Alex的金额
SELECT name, money FROM sh_user WHERE name='Alex';
# 回滚事务
ROLLBACK;
# 查看Alex的金额
SELECT name, money FROM sh_user WHERE name='Alex';
-- ----------------------------
-- 9.4.2 查看隔离级别
-- ----------------------------
SELECT @@transaction_isolation;
-- ----------------------------
-- 9.4.3 修改隔离级别
-- ----------------------------
# 修改事务隔离级别
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
# 查看是否修改成功
SELECT @@session.transaction_isolation;
# 修改事务隔离级别
SET SESSION TRANSACTION ISOLATION LEVEL REPEATABLE READ;
# 查看是否修改成功
SELECT @@session.transaction_isolation;
-- ----------------------------
-- 9.4.4 使用隔离级别
-- ----------------------------
-- 1.脏读
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
SELECT name, money FROM sh_user WHERE name='Bill'; 
# 客户端A
START TRANSACTION;
UPDATE sh_user SET money=money-100 WHERE name='Alex';
UPDATE sh_user SET money=money+100 WHERE name='Bill';
# 客户端B
SELECT name, money FROM sh_user WHERE name='Bill';
# 避免客户端B的脏读，可以将客户端B的事务隔离级别设置为READ COMMITTED
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED;
SELECT name, money FROM sh_user WHERE name='Bill';
# 客户端A
ROLLBACK;
-- 2.不可重复读
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED;
START TRANSACTION;
SELECT name, money FROM sh_user WHERE name='Alex';
# 客户端A
UPDATE sh_user SET money=money-100 WHERE name='Alex';
# 客户端B
SELECT name, money FROM sh_user WHERE name='Alex';
# 避免客户端B的不可重复读的问题，将客户端B的事务隔离级别设置为REPEATABLE READ
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL REPEATABLE READ;
START TRANSACTION;
SELECT name, money FROM sh_user WHERE name='Alex';
# 客户端A
UPDATE sh_user SET money=money+100 WHERE name='Alex';
# 客户端B
SELECT name, money FROM sh_user WHERE name='Alex';
COMMIT;
-- 3.幻读
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL REPEATABLE READ;
START TRANSACTION;
SELECT id, name, money FROM sh_user;
# 客户端A
INSERT INTO sh_user (id, name, money) VALUES (3, 'Tom', 1000);
# 客户端B
INSERT INTO sh_user (id, name, money) VALUES (3, 'Tom', 1000);
SELECT id, name, money FROM sh_user;
COMMIT;
# 避免客户端B的幻读问题，将客户端B的事务隔离级别设置为SERIALIZABLE
# 客户端B
SET SESSION TRANSACTION ISOLATION LEVEL SERIALIZABLE;
START TRANSACTION;
SELECT id, name, money FROM sh_user;
# 客户端A
INSERT INTO sh_user (id, name, money) VALUES (4, 'Bob', 1000);
# 客户端B
COMMIT;
# 查看锁等待超时时间
SELECT @@innodb_lock_wait_timeout;
-- ----------------------------
-- 9.5 动手实践：事务的应用
-- ----------------------------
#查看sh_order_goods订单商品表。
SELECT id, order_id, goods_id, goods_num FROM sh_order_goods;
#开启事务
START TRANSACTION;
#向sh_order_goods订单商品表添加一个id为4的商品，数量为1
INSERT INTO sh_order_goods (order_id, goods_id, goods_num) VALUES (1, 4, 1);
UPDATE sh_goods SET stock=stock-1 WHERE id=4;
#查询id为4的商品库存
SELECT stock FROM sh_goods WHERE id=4;
#回滚事务
ROLLBACK;
#查看sh_order_goods订单商品表
SELECT id, order_id, goods_id, goods_num FROM sh_order_goods;