-- ----------------------------
-- 4.4 动手实践:电子商务网站
-- ----------------------------
# 创建数据库
CREATE DATABASE shop;
# 选择数据库
USE shop;
#创建商品分类表
CREATE TABLE sh_goods_category (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '分类id',
     parent_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '上级分类id',
     name VARCHAR(100) DEFAULT '' COMMENT '分类名称',
     sort INT NOT NULL DEFAULT 0 COMMENT '排序值',
     is_show TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否显示',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '商品分类表';
#添加测试数据
INSERT INTO sh_goods_category (id, parent_id, name) VALUES (1, 0, '办公'), (2, 1, '耗材'), (3, 2, '文具'), (4, 0, '电子产品'), (5, 4, '通讯'), (6, 5, '手机'), (7, 4, '影音'), (8, 7, '音箱'), (9, 7, '耳机'), (10, 4, '计算机'), (11, 10, '台式计算机'), (12, 10, '笔记本计算机'), (13, 0, '服装'), (14, 13, '女装'), (15, 14, '风衣'), (16, 14, '毛衣');
#创建商品表
CREATE TABLE sh_goods (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '商品id',
     category_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '分类id',
     spu_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'SPU id',
     sn VARCHAR(20) NOT NULL DEFAULT '' COMMENT '编号',
     name VARCHAR(120) NOT NULL DEFAULT '' COMMENT '商品名称',
     keyword VARCHAR(255) NOT NULL DEFAULT '' COMMENT '关键词',
     picture VARCHAR(255) NOT NULL DEFAULT '' COMMENT '图片',
     description VARCHAR(255) NOT NULL DEFAULT '' COMMENT '描述',
     content TEXT NOT NULL COMMENT '详情',
     score DECIMAL(3,2) NOT NULL DEFAULT 0 COMMENT '评分',
     price DECIMAL(10,2) NOT NULL DEFAULT 0 COMMENT '价格',
     stock INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '库存',
     is_on_sale TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否上架',
     is_del TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否删除',
     is_free_shipping TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否包邮',
     sell_count INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '销量计数',
     comment_count INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '评论计数',
     on_sale_time DATETIME DEFAULT NULL COMMENT '上架时间',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '商品表';
#添加测试数据
INSERT INTO sh_goods (id, category_id, name, keyword, content, price, stock, score, comment_count) VALUES (1, 3, '2H铅笔S30804', '办公', '考试专用', 0.5, 500, 4.9, 40000), (2, 3, '钢笔T1616', '办公', '练字必不可少', 15, 300, 3.9, 500), (3, 3, '碳素笔GP1008', '办公', '平时使用', 1, 500, 5, 98000), (4, 12, '超薄笔记本Pro12', '电子产品', '轻小便携', 5999, 0, 2.5, 200), (5, 6, '华为P50智能手机', '电子产品', '人人必备', 1999, 0, 5, 98000), (6, 8, '桌面音箱BMS10', '电子产品', '扩音装备', 69, 750, 4.5, 1000), (7, 9, '头戴耳机Star Y360', '电子产品', '独享个人世界', 109, 0, 3.9, 500), (8, 11, '办公计算机 天逸510Pro', '电子产品', '适合办公', 2000, 0, 4.8, 6000), (9, 15, '收腰风衣中长款', '服装', '春节潮流单品', 299, 0, 4.9, 40000), (10, 16, '薄毛衣联名款', '服装', '居家旅行必备', 48, 0, 4.8, 98000);
#创建商品SPU表
CREATE TABLE sh_goods_spu (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT 'SPU id',
     name VARCHAR(80) NOT NULL DEFAULT '' COMMENT 'SPU名称'
) COMMENT '商品SPU表';
#创建商品规格表
CREATE TABLE sh_goods_spec (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '规格id',
     name VARCHAR(80) NOT NULL DEFAULT '' COMMENT '规格名称'
) COMMENT '商品规格表';
#创建商品规格项表
CREATE TABLE sh_goods_spec_item (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '规格项id',
     spec_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '规格id',
     name VARCHAR(80) NOT NULL DEFAULT '' COMMENT '规格项名称',
     description VARCHAR(255) NOT NULL DEFAULT '' COMMENT '描述',
     picture VARCHAR(255) NOT NULL DEFAULT '' COMMENT '可选图'
) COMMENT '商品规格项表';
#创建商品规格组合表
CREATE TABLE sh_goods_spec_set (
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT 'SKU id',
     spec_item_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '规格项id'
) COMMENT '商品规格组合表';
#添加测试数据
INSERT INTO sh_goods_spu (id, name) VALUES (1, '新款智能手机');
INSERT INTO sh_goods_spec (id, name) VALUES (1, '网络'), (2, '颜色'), (3, '内存');
INSERT INTO sh_goods_spec_item (id, spec_id, name) VALUES (1, 1, '移动'), (2, 1, '电信'), (3, 2, '白色'), (4, 2, '黑色'), (5, 3, '4GB'), (6, 3, '6GB');
INSERT INTO sh_goods_spec_set (goods_id, spec_item_id) VALUES (5, 2), (5, 3), (5, 5);
#创建商品属性表
CREATE TABLE sh_goods_attr (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '属性id',
     parent_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '上级属性id',
     category_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品分类id',
     name VARCHAR(80) NOT NULL DEFAULT '' COMMENT '属性名称',
     sort INT NOT NULL DEFAULT 0 COMMENT '排序值'
) COMMENT '商品属性表';
#创建商品属性值表
CREATE TABLE sh_goods_attr_value (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '属性值id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     attr_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '属性id',
     attr_value VARCHAR(80) NOT NULL DEFAULT '' COMMENT '属性值'
) COMMENT '商品属性值表';
#创建商品筛选表
CREATE TABLE sh_goods_selector (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '筛选id',
     parent_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '上级筛选id',
     category_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品分类id',
     name VARCHAR(80) NOT NULL DEFAULT '' COMMENT '筛选名称',
     sort INT NOT NULL DEFAULT 0 COMMENT '排序值'
) COMMENT '商品筛选表';
#创建商品筛选值表
CREATE TABLE sh_goods_selector_value (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '筛选值id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     selector_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '筛选id',
     selector_value VARCHAR(80) NOT NULL DEFAULT '' COMMENT '筛选值'
) COMMENT '商品筛选值表';
#添加测试数据
INSERT INTO sh_goods_attr VALUES (1, 0, 6, '基本信息', 0), (2, 1, 6, '机身颜色', 0), (3, 1, 6, '输入方式', 1), (4, 1, 6, '操作系统', 2), (5, 0, 6, '屏幕', 1), (6, 5, 6, '屏幕尺寸', 0), (7, 5, 6, '屏幕材质', 1), (8, 5, 6, '分辨率', 2), (9, 0, 6, '摄像头', 2), (10, 9, 6, '前置摄像头', 0), (11, 9, 6, '后置摄像头', 1), (12, 0, 6, '电池信息', 3), (13, 12, 6, '电池容量', 0), (14, 12, 6, '是否可拆卸', 1);
INSERT INTO sh_goods_attr_value VALUES (1, 5, 2, '黑色'), (2, 5, 3, '触摸屏'), (3, 5, 4, 'Android'), (4, 5, 6, '5.5 寸'), (5, 5, 7, 'IPS'), (6, 5, 8, '1920*1080'), (7, 5, 10, '1600 万'), (8, 5, 11, '800 万'), (9, 5, 13, '3500mAh'), (10, 5, 14, '否');
#创建用户表
CREATE TABLE sh_user (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '用户id',
     name VARCHAR(100) NOT NULL UNIQUE DEFAULT '' COMMENT '用户名',
     password VARCHAR(255) NOT NULL DEFAULT '' COMMENT '密码',
     salt CHAR(32) NOT NULL DEFAULT '' COMMENT '密码盐',
     email VARCHAR(128) NOT NULL DEFAULT '' COMMENT '邮箱',
     mobile CHAR(11) NOT NULL DEFAULT '' COMMENT '手机号',
     level TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户级别',
     money DECIMAL(10,2) NOT NULL DEFAULT 0 COMMENT '金额',
     gender TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '性别',
     qq VARCHAR(20) NOT NULL DEFAULT '' COMMENT 'QQ',
     is_active TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否激活',
     reg_time DATETIME DEFAULT NULL COMMENT '注册时间',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '用户表';
SELECT MD5(CONCAT(MD5('123456'), 'salt1'));
INSERT INTO sh_user (id, name, password, salt, money, is_active) VALUES (1, 'Alex', MD5(CONCAT(MD5('123'), 'salt1')), 'salt1', 1000, 1), (2, 'Bill', MD5(CONCAT(MD5('123'), 'salt2')), 'salt2', 1000, 1);
SELECT id, name, password, salt FROM sh_user;
#创建商品评论表
CREATE TABLE sh_goods_comment (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '评论id',
     parent_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '上级评论id',
     user_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     content TEXT NOT NULL COMMENT '评论内容',
     is_staff TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否为工作人员',
     is_show TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否显示',
     is_del TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否删除',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '评论表';
INSERT INTO sh_goods_comment ( id, user_id, goods_id, content, is_show, create_time) VALUES (1, 1, 8, '好', 0, '2022-4-08 00:00:00'), (2, 2, 10, '不错', 1, '2022-6-03 00:00:00'), (3, 3, 9, '满意', 1, '2022-6-30 00:00:00'), (4, 4, 4, '携带方便', 1, '2022-02-19 00:00:00'), (5, 4, 7, '中低音效果特别棒', 1, '2022-01-19 00:00:00'), (6, 5, 8, '卡机', 1, '2022-01-22 00:00:00'), (7, 6, 5, '黑夜拍照也清晰', 1, '2022-02-15 00:00:00'), (8, 7, 9, '掉色、有线头', 0, '2022-03-03 00:00:00'), (9, 4, 9, '还行', 1, '2022-04-05 00:00:00'), (10, 8, 9, '特别彰显气质', 1,'2022-04-16 00:00:00');
#创建购物车表
CREATE TABLE sh_user_shopcart (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '购物车id',
     user_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     goods_price DECIMAL(10,2) NOT NULL DEFAULT 0 COMMENT '单价',
     goods_num INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '购买件数',
     is_select TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否选中',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '购物车表';
#创建收货地址表
CREATE TABLE sh_user_address (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '地址id',
     user_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户id',
     is_default TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否默认',
     province VARCHAR(20) NOT NULL DEFAULT '' COMMENT '省',
     city VARCHAR(20) NOT NULL DEFAULT '' COMMENT '市',
     district VARCHAR(20) NOT NULL DEFAULT '' COMMENT '区',
     address VARCHAR(255) NOT NULL DEFAULT '' COMMENT '具体地址',
     zip VARCHAR(20) NOT NULL DEFAULT '' COMMENT '邮编',
     consignee VARCHAR(20) NOT NULL DEFAULT '' COMMENT '收件人',
     phone VARCHAR(20) NOT NULL DEFAULT '' COMMENT '联系电话',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '收货地址表';
#创建订单表
CREATE TABLE sh_order (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '订单id',
     user_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户id',
     total_price DECIMAL(10, 2) NOT NULL DEFAULT 0 COMMENT '订单总价',
     order_price DECIMAL(10, 2) NOT NULL DEFAULT 0 COMMENT '应付金额',
     province VARCHAR(20) NOT NULL DEFAULT '' COMMENT '省',
     city VARCHAR(20) NOT NULL DEFAULT '' COMMENT '市',
     district VARCHAR(20) NOT NULL DEFAULT '' COMMENT '区',
     address VARCHAR(255) NOT NULL DEFAULT '' COMMENT '具体地址',
     zip VARCHAR(20) NOT NULL DEFAULT '' COMMENT '邮编',
     consignee VARCHAR(20) NOT NULL DEFAULT '' COMMENT '收件人',
     phone VARCHAR(20) NOT NULL DEFAULT '' COMMENT '联系电话',
     is_valid TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否有效',
     is_cancel TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否取消',
     is_pay TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否付款',
     status TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '物流状态',
     is_del TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否删除',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
     update_time DATETIME DEFAULT NULL COMMENT '更新时间'
) COMMENT '订单表';
#创建订单商品表
CREATE TABLE sh_order_goods (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT 'id',
     order_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '订单id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     goods_name VARCHAR(120) NOT NULL DEFAULT '' COMMENT '商品名称',
     goods_num INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '购买数量',
     goods_price DECIMAL(10,2) NOT NULL DEFAULT 0 COMMENT '商品单价',
     user_note VARCHAR(255) NOT NULL DEFAULT '' COMMENT '用户备注',
     staff_note VARCHAR(255) NOT NULL DEFAULT '' COMMENT '卖家备注'
) COMMENT '订单商品表';
#创建商品评分表
CREATE TABLE sh_goods_score (
     id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '评分id',
     user_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '用户id',
     goods_id INT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品id',
     goods_score TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '商品评分',
     service_score TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '服务评分',
     express_score TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '物流评分',
     is_invalid TINYINT UNSIGNED NOT NULL DEFAULT 0 COMMENT '是否无效',
     create_time DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '评分时间'
) COMMENT '商品评分表';