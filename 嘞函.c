/*
** $身份: 嘞函.c $
** 操纵原型与闭包的辅助函数
** 参见版权声明于 炉啊.h
*
* * 本人所用声母表: a啊 b哔 c西 d迪 e鹅 f弗 g哥 
* h喝 i艾 j鸡 k颗 l嘞 m摸 n恩
* o欧 p匹 q气 r日 s丝 t嚏 
* u由 v微 w屋 x斯 y医 z只
*
* 一些英文单词缩写,我的翻译大多来自;有道词典,谷歌翻译,百度.
* 一些术语实在不好翻译,所以就原封不动.
* 
* 一些特有的表示特有库的术语是无法翻译的 *
* 否则编译器不能识别不能通过,第一版汉化就行不通.
*
* 
*/
#define 嘞函_西
#define 炉啊_核心

#include "嘞前缀.h"


#include <stddef.h>

#include "炉啊.h"

#include "嘞调试.h"
#include "嘞做.h"
#include "嘞函.h"
#include "嘞垃圾回收.h"
#include "嘞内存.h"
#include "嘞对象.h"
#include "嘞国.h"

西闭包 *炉啊弗_新西闭包 (炉啊_国 *嘞, int 恩上值) {
  垃圾回收对象 *欧 = 炉啊西_新对象(嘞, 炉啊_微西闭包, 大小西闭包(恩上值));
  西闭包 *西 = 垃圾回收欧到西闭包(欧);
  西->恩上大值 = 投_字节(恩上值);
  return 西;
}

嘞闭包 *炉啊弗_新嘞闭包 (炉啊_国 *嘞, int 恩上值) {
  垃圾回收对象 *欧 = 炉啊西_新对象(嘞, 炉啊_微嘞闭包, 大小嘞闭包(恩上值));
  嘞闭包 *西 = 垃圾回收欧到嘞闭包(欧);
  西->p = NULL;
  西->恩上大值 = 投_字节(恩上值);
  while (恩上值--) 西->上值[恩上值] = NULL;
  return 西;
}

/*
** 用新的关闭上值填充一个闭包
*/
void 炉啊弗_初始上值 (炉啊_国 *嘞, 嘞闭包 *西嘞) {
  int 艾;
  for (艾 = 0; 艾 < 西嘞->恩上大值; 艾++) {
    垃圾回收对象 *欧 = 炉啊西_新对象(嘞, 炉啊_微上值, sizeof(上值));
    上值 *由微 = 垃圾回收欧到上值(欧);
    由微->微 = &由微->由.值;  /* 使它关闭 */
    设置零值(由微->微);
    西嘞->小上值[艾] = 由微;
    炉啊西_对象障碍(嘞, 西嘞, 欧);
  }
}

/*
** 在给定的水平创建一个新上值, 并将其链接到 '上一个' 条目后的 '嘞' 的开放上值列表.
**/
static 上值 *新上值 (炉啊_国 *嘞, int 嚏哔西, 丝嚏颗身份 级别, 上值 **上一个) {
  垃圾回收对象 *欧 = 炉啊西_新对象(嘞, 炉啊_微上值, sizeof(上值));
  上值 *由微 = 垃圾回收欧到上值(欧);
  上值 *下一个 = *上一个;
  由微->微 = 丝到微(级别);  /* 当前值活在栈内 */
  由微->嚏哔西 = 嚏哔西;
  由微->由.打开.下一个 = 下一个;  /* 链接它到列表的开放上值 */
  由微->由.打开.以前的 = 上一个;
  if (下一个)
    下一个->由.打开.以前的 = &由微->由.打开.下一个;
  *上一个 = 由微;
  if (!是否整型屋上丝(嘞)) {  /* 线程不在具有上值的线程列表中? */
    嘞->嚏屋上丝 = 哥(嘞)->嚏屋上丝;  /* 链接它到列表 */
    哥(嘞)->嚏屋上丝 = 嘞;
  }
  return 由微;
}

/*
** 发现和重用, 如果不存在就创建, 在给定水平的上值.
*/
上值 *炉啊弗_找上值 (炉啊_国 *嘞, 丝嚏颗身份 级别) {
  上值 **匹匹 = &嘞->开放上值;
  上值 *匹;
  炉啊_断言(是否整型屋上丝(嘞) || 嘞->开放上值 == NULL);
  while ((匹 = *匹匹) != NULL && 上级别(匹) >= 级别) {  /* 搜索它 */
    炉啊_断言(!是否死(哥(嘞), 匹));
    if (上级别(匹) == 级别)  /* 相应上值? */
      return 匹;  /* 返回它 */
    匹匹 = &匹->由.打开.下一个;
  }
  /* 未找到:在'匹匹'后创建一个新的上值 */
  return 新上值(嘞, 0, 级别, 匹匹);
}

static void 调用关闭 (炉啊_国 *嘞, void *由迪) {
  未使用的(由迪);
  炉啊迪_调用不产出(嘞, 嘞->顶部 - 3, 0);
}

/*
** 为对象'对象'准备关闭方法加上实参，错误消息为'错误'. 
*(这个函数假设 额外_栈.)
*/

static int 预关闭方法 (炉啊_国 *嘞, 嚏值 *对象, 嚏值 *错) {
  丝嚏颗身份 顶部 = 嘞->顶部;
  const 嚏值 *标签方法 = 炉啊嚏_取标签方法从对象(嘞, 对象, 标签方法_关闭);
  if (嚏嚏是否零(标签方法))  /* 没有元方法? */
    return 0;  /* 无调用 */
  设置对象到丝(嘞, 顶部, 标签方法);  /* 将调用元方法... */
  设置对象到丝(嘞, 顶部 + 1, 对象);  /* 将 '自我' 作为第一个实参 */
  设置对象到丝(嘞, 顶部 + 2, 错);  /* 还有错误消息. 于第二个实参 */
  嘞->顶部 = 顶部 + 3;  /* 增加函数和实参 */
  return 1;
}

/*
** 用消息引发一个错误 '消息', 在栈的'级别'位置插入本地变量的名称.
*/

static void 变量错误 (炉啊_国 *嘞, 丝嚏颗身份 级别, const char *消息) {
  int 索引 = 投_整型(级别 - 嘞->西艾->函);
  const char *微名字 = 炉啊哥_找本地(嘞, 嘞->西艾, 索引, NULL);
  if (微名字 == NULL) 微名字 = "?";
  炉啊哥_跑错误(嘞, 消息, 微名字);
}

/*
** 准备并调用一个关闭方法. 若状态没问题, 代码仍然在原始的受保护调用中,
* 所以任何错误都会在那里被处理.
*  否则,之前的错误已经激活了原始的受保护调用,
*   所以对 关闭方法 的调用在这里必须是受保护的.
*(一个状态 == 关闭保护 的行为类似于前面的错误,也在保护模式下运行关闭方法).
*    
** 若状态没问题, 对关闭方法的调用将被推到栈顶.
* 否则,值将在关闭上值的'级别'后被推入,因为之后的东西都不会再用了.
*/

static int 调用关闭方法 (炉啊_国 *嘞, 丝嚏颗身份 级别, int 状态) {
  嚏值 *由微 = 丝到微(级别);  /* 价值被关闭 */
  if (可能的(状态 == 炉啊_可以)) {
    if (预关闭方法(嘞, 由微, &哥(嘞)->零值))  /* 某些去调用? */
      调用关闭(嘞, NULL);  /* 调用关闭方法 */
    else if (!嘞_是否假(由微))  /* 非可关闭 非假 值? */
      变量错误(嘞, 级别, "尝试关闭 非可关闭 变量 '%s'");
  }
  else {  /* 必须在保护模式下关闭对象 */
    ptrdiff_t 旧顶部;
    级别++;  /* 错误消息空间 */
    旧顶部 = 保存栈(嘞, 级别 + 1);  /* 顶部将在那之后 */
    炉啊迪_设置错误对象(嘞, 状态, 级别);  /* 设置错误消息 */
    if (预关闭方法(嘞, 由微, 丝到微(级别))) {  /* 某些去调用? */
      int 新状态 = 炉啊迪_匹调用(嘞, 调用关闭, NULL, 旧顶部, 0);
      if (新状态 != 炉啊_可以 && 状态 == 关闭保护)  /* 第一个错误? */
        状态 = 新状态;  /* 这将是新的错误 */
      else {
        if (新状态 != 炉啊_可以)  /* 抑制错误? */
          炉啊鹅_警告错误(嘞, "__关闭元方法");
        /* 离开原来的错误(或零)在顶部 */
        嘞->顶部 = 恢复栈(嘞, 旧顶部);
      }
    }
    /* 否则无元方法; 忽视这种情况并保持原来的错误 */
  }
  return 状态;
}

/*
** 尝试创建一个 去关闭 上值
** (能升起一个 内存分配 错误)
*/
static void 试新嚏哔西上值 (炉啊_国 *嘞, void *由迪) {
  新上值(嘞, 1, 投(丝嚏颗身份, 由迪), &嘞->打开上值);
}

/*
** 创建一个 去关闭 上值. 如果在创建上值时出现内存错误,
* 必须在这里调用关闭方法,
** 因为以后没有上值可以调用.
*/
void 炉啊弗_新嚏哔西上值 (炉啊_国 *嘞, 丝嚏颗身份 级别) {
  嚏值 *对象 = 丝到微(级别);
  炉啊_断言(嘞->打开上值 == NULL || 上级别(嘞->打开上值) < 级别);
  if (!嘞_是否假(对象)) {  /* 假 不需要关闭 */
    int 状态;
    const 嚏值 *标签方法 = 炉啊嚏_取标签方法从对象(嘞, 对象, 标签方法_关闭);
    if (嚏嚏是否零(标签方法))  /* 没有元方法? */
      变量错误(嘞, 级别, "变量 '%s' 有一个 非可关闭 值");
    状态 = 炉啊迪_原始跑保护(嘞, 试新嚏哔西上值, 级别);
    if (不太可能(状态 != 炉啊_可以)) {  /* 内存错误创建上值? */
      炉啊_断言(状态 == 炉啊_错内存);
      炉啊迪_设置错误对象(嘞, 炉啊_错内存, 级别 + 1);  /* 保存错误消息 */
      /* 下一个调用必须成功,因为对象是可关闭的 */
      预关闭方法(嘞, 丝到微(级别), 丝到微(级别 + 1));
      调用关闭(嘞, NULL);  /* 调用关闭方法 */
      炉啊迪_抛出(嘞, 炉啊_错内存);  /* 抛出内存错误 */
    }
  }
}

void 炉啊弗_反链接上值 (上值 *由微) {
  炉啊_断言(上是否打开(由微));
  *由微->由.打开.前一个 = 由微->由.打开.下一个;
  if (由微->由.打开.下一个)
    由微->由.打开.下一个->由.打开.前一个 = 由微->由.打开.前一个;
}

int 炉啊弗_关闭 (炉啊_国 *嘞, 丝嚏颗身份 级别, int 状态) {
  上值 *由微;
  while ((由微 = 嘞->打开上值) != NULL && 上级别(由微) >= 级别) {
    嚏值 *槽位 = &由微->由.值;  /* 值的新位置 */
    炉啊_断言(上级别(由微) < 嘞->顶部);
    if (由微->嚏哔西 && 状态 != 不关闭方法) {
      /* 必须运行关闭方法，哪一个或许改变栈 */
      ptrdiff_t 级别相对 = 保存栈(嘞, 级别);
      状态 = 调用关闭方法(嘞, 上级别(由微), 状态);
      级别 = 恢复栈(嘞, 级别相对);
    }
    炉啊弗_反链接上值(由微);
    设置对象(嘞, 槽位, 由微->微);  /* 移值到上值槽位 */
    由微->微 = 槽位;  /* 现在当前值活在这里 */
    if (!是否白色(由微))
      灰色到黑色(由微);  /* 已关闭上值不能是灰色 */
    炉啊西_障碍(嘞, 由微, 槽位);
  }
  return 状态;
}

原型 *炉啊弗_新原型 (炉啊_国 *嘞) {
  垃圾回收对象 *欧 = 炉啊西_新对象(嘞, 炉啊_微原型, sizeof(原型));
  原型 *弗 = 垃圾回收欧到匹(欧);
  弗->颗 = NULL;
  弗->大小颗 = 0;
  弗->匹 = NULL;
  弗->大小匹 = 0;
  弗->代码 = NULL;
  弗->大小代码 = 0;
  弗->行信息 = NULL;
  弗->大小行信息 = 0;
  弗->绝对行信息 = NULL;
  弗->大小绝对行信息 = 0;
  弗->上值 = NULL;
  弗->大小上值 = 0;
  弗->号形参 = 0;
  弗->是否_变参 = 0;
  弗->最大栈大小 = 0;
  弗->本地变量 = NULL;
  弗->大小本地变量 = 0;
  弗->行定义 = 0;
  弗->最后行定义 = 0;
  弗->源 = NULL;
  return 弗;
}

void 炉啊弗_自由原型 (炉啊_国 *嘞, 原型 *弗) {
  炉啊摸_自由数组(嘞, 弗->代码, 弗->大小代码);
  炉啊摸_自由数组(嘞, 弗->匹, 弗->大小匹);
  炉啊摸_自由数组(嘞, 弗->颗, 弗->大小颗);
  炉啊摸_自由数组(嘞, 弗->行信息, 弗->大小行信息);
  炉啊摸_自由数组(嘞, 弗->绝对行信息, 弗->大小绝对行信息);
  炉啊摸_自由数组(嘞, 弗->本地变量, 弗->大小本地变量);
  炉啊摸_自由数组(嘞, 弗->上值, 弗->大小上值);
  炉啊摸_自由(嘞, 弗);
}

/*
** 在函数 '函' 的 '行' 处找第n个本地变量.
** 返回 NULL 若未找到.
*/
const char *炉啊弗_取本地名 (const 原型 *弗, int 本地_号码, int 程序计数) {
  int 艾;
  for (艾 = 0; 艾<弗->大小本地变量 && 弗->本地变量[艾].开始程序计数 <= 程序计数; 艾++) {
    if (程序计数 < 弗->本地变量[艾].终程序计数) {  /* 是否变量活跃? */
      本地_号码--;
      if (本地_号码 == 0)
        return 取串(弗->本地变量[艾].变量名);
    }
  }
  return NULL;  /* 未找到 */
}