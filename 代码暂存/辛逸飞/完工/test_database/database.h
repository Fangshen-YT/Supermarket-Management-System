// Name: database.h
// Author: 辛逸飞
// Date: 2017-09-13
// Language: C
// Features: 数据库接口: 文件读取, 转存为结构体或写入文件.

#ifndef _DATABASE_H_ // 防止重复调用
#define _DATABASE_H_

/*************************************************
path:
  文件路径
*************************************************/
extern char path[300];

/*************************************************
标题:
  STU_time 时间存取结构型
*************************************************/

typedef struct {
  int year;
  int month;
  int day;
  int hour;
  int minute;
} STU_time;

/*************************************************
标题:
  admin_information数据库 管理员信息 可读写

路径:
  ./database/admin_information/

文件名:
  {admin_id}.txt

数据:
  1行4列
  超市名 | 管理员姓名 | 邮箱 | 密码

接收:
  user_id 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 成功读写数据
*************************************************/

typedef struct {
  char shop_id[30];  // 超市名
  char name[10];     // 管理员姓名
  char email[30];    // 邮箱
  char password[30]; // 密码
} STU_admin_information;

extern STU_admin_information admin_information;

extern int database_admin_information(char user_id[30], int read_type);

/*************************************************
标题:
  consumer_information数据库 顾客信息 可读写

路径:
  ./database/consumer_information/

文件名:
  {consumer_id}.txt

数据:
  1行7列
  顾客姓名 | 性别(男性 : 1, 女性: 2) | 手机号 | 密码 | 邮箱 | 地址 | 余额

接收:
  user_id 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 成功读写数据
*************************************************/

typedef struct {
  char name[10];     // 顾客姓名
  char sex[10];      // 顾客性别
  char tel[20];      // 手机号
  char password[30]; // 密码
  char email[30];    // 邮箱
  char address[50];  // 地址
  char money[10];    // 余额
} STU_consumer_information;

extern STU_consumer_information consumer_information;

extern int database_consumer_information(char user_id[30], int user_type);

/*************************************************
标题:
  goods_index数据库 按商品种类索引的商品清单 可读写

路径:
  ./database/goods_index/

文件名:
  {goods_id}.txt

数据:
  n行8列
  超市ID | 单价 | 进价 | 销量 | 库存 | 折扣价格 | 折扣开始时间 |折扣结束时间

接收:
  goods_id: 商品种类
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char shop_id[30];     // 超市ID
  float unit_price;     // 单价
  float in_price;       // 进价
  int sales_volume;     // 销量
  int goods_in_stock;   // 库存
  float discount_price; // 折扣价格
  STU_time time_begin;  // 折扣开始时间
  STU_time time_end;    //折扣结束时间
} STU_goods_index;

extern STU_goods_index goods_index[];

extern int database_goods_index(char user_id[30], int user_type);

/*************************************************
标题:
  order_admin_all数据库 管理员可查询订单 可读写

路径:
  ./database/order_admin/

文件名:
  {admin_id}_all.txt

存放数据:
  n行7列
  订单编号 | 顾客ID | 购买时间 | 商品ID | 购买数量 | 单价 | 总价

接收:
  user_id: 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char order_id[30];    // 订单编号
  char consumer_id[30]; // 顾客编号
  STU_time sold_time;   // 购买时间
  char goods_id[30];    // 商品ID
  int purchase_num;     // 购买数量
  float unit_price;     // 单价
  float all_price;      // 总价
} STU_order_admin_all;

extern STU_order_admin_all order_admin_all[];

extern int database_order_admin_all(char user_id[30], int user_type);

/*************************************************
标题:
  order_admin_consumer数据库 管理员可查询订单_按顾客分类 可读写

路径:
  ./database/order_admin/

文件名:
  {admin_id}_consumer.txt

存放数据
  n行3列
  顾客ID | 商品ID | 购买数量

接收:
  user_id: 用户ID
  read_type: 读取类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char consumer_id[30]; // 顾客ID
  char goods_id[30];    //商品ID
  int purchase_num;     // 购买数量
} STU_order_admin_consumer;

extern STU_order_admin_consumer order_admin_consumer[];

extern int database_order_admin_consumer(char user_id[30], int user_type);

/*************************************************
标题:
  order_admin_goods数据库 管理员可查询订单_按货物分类 可读写

路径:
  ./database/order_admin/

文件名:
  {admin_id}_goods.txt

存放数据
n行4列
商品ID | 销量 | 营业额 | 利润

接收:
  user_id: 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char goods_id[30]; // 商品ID
  int purchase_num;  // 购买数量
  float all_price;   // 营业额
  float profit;      // 利润
} STU_order_admin_goods;

extern STU_order_admin_goods order_admin_goods[];

extern int database_order_admin_goods(char user_id[30], int user_type);

/*************************************************
标题:
  order_consumer数据库 管理员可查询订单_按货物分类 可读写

路径:
  ./database/order_consumer/

文件名:
  {consumer_id}.txt

存放数据
n行6列
订单编号 | 购买时间 | 商品ID | 购买数量 | 单价 | 总价

接收:
  user_id: 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char order_id[30];  // 订单编号
  char sold_time[25]; // 购买时间
  char goods_id[30];  // 商品ID
  int purchase_num;   // 购买数量
  float unit_price;   // 单价
  float all_price;    // 总价
} STU_order_consumer;

extern STU_order_consumer order_consumer[];

extern int database_order_consumer(char user_id[30], int user_type);

/*************************************************
标题:
  shop_index数据库 商品清单_以管理员ID为索引 可读写

路径:
  ./database/shop_index/

文件名:
  {admin_id}.txt

存放数据
n行8列
顾客ID | 单价 | 进价 | 销量 | 库存 | 折扣价格 | 折扣开始时间 |折扣结束时间

接收:
  shop_id: 超市信息
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char goods_id[30];    // 商品编号
  float unit_price;     // 零售价格
  float in_price;       // 进货价格
  int sales_volume;     // 销量
  int goods_in_stock;   // 存货
  float discount_price; // 折扣价
  STU_time time_begin;  // 折扣开始时间
  STU_time time_end;    // 折扣结束时间
} STU_shop_index;

extern STU_shop_index shop_index[];

extern int database_shop_index(char user_id[30], int user_type);

/*************************************************
标题:
  shopping_cart数据库 用户离线购物车 可读写

路径:
  ./database/shopping_cart/

文件名:
  {guke_id}.txt

存放数据
n行3列
商品ID | 管理员ID | 打算购买数量

接收:
  user_id: 用户ID
  read_type: 读写类型
    0: 读取
    1: 写入

返回:
  0: 文件不存在
  1: 文件存在并成功读写
*************************************************/

typedef struct {
  char goods_id[30]; // 商品ID
  char shop_id[30];  //管理员ID
  int purchase_num;  // 购买数量
} STU_shopping_cart;

extern STU_shopping_cart shopping_cart[]; // 最多存放100笔订单

extern int database_shopping_cart(char user_id[30], int user_type);

#endif /* _DATABASE_H_ */
