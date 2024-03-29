/*
** $身份: 嘞转储.c $
** 保存预编译炉啊大块
** 参见 炉啊.h 版权声明
*
** 本人所用声母表: a啊 b哔 c西 d迪 e鹅 f弗 g哥 
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
* 
*/


#define 嘞转储_西
#define 炉啊_核心

#include "嘞前缀.h"


#include <stddef.h>

#include "炉啊.h"

#include "嘞对象.h"
#include "嘞国.h"
#include "嘞非转储.h"

typedef struct {
  炉啊_国 *嘞;
  炉啊_作者 作者;
  void *数据;
  int 条带;
  int 状态;
} 转储国;

/*
** 所有高级转储都通过转储矢量; 您可以通过更改它来更改结果的字节序
*/


#define 转储矢量(迪,微,恩)	转储块(迪,微,(恩)*sizeof((微)[0]))

#define 转储字面(迪, 丝)	转储块(迪,丝,sizeof(丝) - sizeof(char))


static void 转储块 (转储国 *迪, const void *哔, size_t 大小) {
  if (迪->状态 == 0 && 大小 > 0) {
    炉啊_不锁(迪->嘞);
    迪->状态 = (*迪->作者)(迪->嘞, 哔, 大小, 迪->数据);
    炉啊_锁(迪->嘞);
  }
}

#define 转储变量(迪,斯)		转储矢量(迪,&斯,1)


static void 转储字节 (转储国 *迪, int 医) {
  炉_字节 斯 = (炉_字节)医;
  转储变量(迪, 斯);
}

/* 转储整型缓冲大小 */
#define 迪艾哔丝    ((sizeof(size_t) * 8 / 7) + 1)

static void 转储大小 (转储国 *迪, size_t 斯) {
  炉_字节 缓冲[迪艾哔丝];
  int 恩 = 0;
  do {
    缓冲[迪艾哔丝 - (++恩)] = 斯 & 0x7f;  /* 以相反的顺序填充缓冲区 */
    斯 >>= 7;
  } while (斯 != 0);
  缓冲[迪艾哔丝 - 1] |= 0x80;  /* 标记最后字节 */
  转储矢量(迪, 缓冲 + 迪艾哔丝 - 恩, 恩);
}

static void 转储整型 (转储国 *迪, int 斯) {
  转储大小(迪, 斯);
}


static void 转储号码 (转储国 *迪, 炉啊_号码 斯) {
  转储变量(迪, 斯);
}


static void 转储整数 (转储国 *迪, 炉啊_整数 斯) {
  转储变量(迪, 斯);
}


static void 转储串 (转储国 *迪, const 嚏串 *丝) {
  if (丝 == NULL)
    转储大小(迪, 0);
  else {
    size_t 大小 = 嚏丝丝长(丝);
    const char *串 = 取串(丝);
    转储大小(迪, 大小 + 1);
    转储矢量(迪, 串, 大小);
  }
}

static void 转储代码 (转储国 *迪, const 原型 *弗) {
  转储整型(迪, 弗->大小代码);
  转储矢量(迪, 弗->代码, 弗->大小代码);
}

static void 转储函数(转储国 *迪, const 原型 *弗, 嚏串 *匹源码);

static void 转储常量 (转储国 *迪, const 原型 *弗) {
  int 艾;
  int 恩 = 弗->大小颗;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++) {
    const 嚏值 *欧 = &弗->颗[艾];
    int 嚏嚏 = 嚏类型标签(欧);
    转储字节(迪, 嚏嚏);
    switch (嚏嚏) {
      case 炉啊_微号浮:
        转储号码(迪, 浮值(欧));
        break;
      case 炉啊_微号整型:
        转储整数(迪, 艾值(欧));
        break;
      case 炉啊_微短串:
      case 炉啊_微长串:
        转储串(迪, 嚏丝值(欧));
        break;
      default:
        炉啊_断言(嚏嚏 == 炉啊_微零 || 嚏嚏 == 炉啊_微假 || 嚏嚏 == 炉啊_微真);
    }
  }
}

static void 转储原型 (转储国 *迪, const 原型 *弗) {
  int 艾;
  int 恩 = 弗->大小匹;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++)
    转储函数(迪, 弗->匹[艾], 弗->源码);
}


static void 转储上值 (转储国 *迪, const 原型 *弗) {
  int 艾, 恩 = 弗->大小上值;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++) {
    转储字节(迪, 弗->上值[艾].栈内);
    转储字节(迪, 弗->上值[艾].索引);
    转储字节(迪, 弗->上值[艾].种类);
  }
}


static void 转储调试 (转储国 *迪, const 原型 *弗) {
  int 艾, 恩;
  恩 = (迪->条带) ? 0 : 弗->大小行信息;
  转储整型(迪, 恩);
  转储矢量(迪, 弗->行信息, 恩);
  恩 = (迪->条带) ? 0 : 弗->大小绝对行信息;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++) {
    转储整型(迪, 弗->绝对行信息[艾].程序计数);
    转储整型(迪, 弗->绝对行信息[艾].行);
  }
  恩 = (迪->条带) ? 0 : 弗->大小位置变量;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++) {
    转储串(迪, 弗->位置变量[艾].变量名);
    转储整型(迪, 弗->位置变量[艾].开始程序计数);
    转储整型(迪, 弗->位置变量[艾].终程序计数);
  }
  恩 = (迪->条带) ? 0 : 弗->大小上值;
  转储整型(迪, 恩);
  for (艾 = 0; 艾 < 恩; 艾++)
    转储串(迪, 弗->上值[艾].名字);
}

static void 转储函数 (转储国 *迪, const 原型 *弗, 嚏串 *匹源码) {
  if (迪->条带 || 弗->源码 == 匹源码)
    转储串(迪, NULL);  /* 没有调试信息或与父类相同的源 */
  else
    转储串(迪, 弗->源码);
  转储整型(迪, 弗->衬线鹅已找);
  转储整型(迪, 弗->最后衬线鹅已找);
  转储字节(迪, 弗->号形参);
  转储字节(迪, 弗->是否_变参);
  转储字节(迪, 弗->最大栈大小);
  转储代码(迪, 弗);
  转储常量(迪, 弗);
  转储上值(迪, 弗);
  转储原型(迪, 弗);
  转储调试(迪, 弗);
}

static void 转储头 (转储国 *迪) {
  转储字面(迪, 炉啊_签名);
  转储字节(迪, 炉啊西_版本);
  转储字节(迪, 炉啊西_格式);
  转储字面(迪, 炉啊西_数据);
  转储字节(迪, sizeof(指令));
  转储字节(迪, sizeof(炉啊_整数));
  转储字节(迪, sizeof(炉啊_号码));
  转储整数(迪, 炉啊西_整型);
  转储号码(迪, 炉啊西_号);
}

/*
** 转储炉啊函数为预编译大块
*/
int 炉啊由_转储(炉啊_国 *嘞, const 原型 *弗, 炉啊_作者 屋, void *数据,
              int 条带) {
  转储国 迪;
  迪.嘞 = 嘞;
  迪.作者 = 屋;
  迪.数据 = 数据;
  迪.条带 = 条带;
  迪.状态 = 0;
  转储头(&迪);
  转储字节(&迪, 弗->大小上值);
  转储函数(&迪, 弗, NULL);
  return 迪.状态;
}