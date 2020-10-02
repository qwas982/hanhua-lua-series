/*
** $ 身份：嘞标签方法.h $
** 标签方法
** 请参见 炉啊.h中的版权声明
*
* 本人所用声母表: a啊 b哔 c西 d迪 e鹅 f弗 g哥 
* h喝 i艾 j鸡 k颗 l嘞 m摸 n恩
* o欧 p匹 q气 r日 s丝 t嚏 
* u由 v微 w屋 x斯 y医 z只
*
* 一些英文单词缩写,我的翻译大多来自;有道词典,谷歌翻译,百度.
* 一些术语实在不好翻译,所以就原封不动.
*
* 
*/

#ifndef 嘞标签方法_喝
#define 嘞标签方法_喝


#include "嘞对象.h"

/*
* 警告: 若您更改此枚举的顺序,
* 搜索正则打印行 "秩序 标签方法" 和  "秩序 操作" 
*/

typedef enum {
  标签方法_索引,
  标签方法_新索引,
  标签方法_垃圾回收,
  标签方法_模式,
  标签方法_长度,
  标签方法_等于,  /* 最后一种快速访问的标签方法 */
  标签方法_加,
  标签方法_减,
  标签方法_乘,
  标签方法_余数,
  标签方法_幂,
  标签方法_除,
  标签方法_符号除,
  标签方法_位与,
  标签方法_位或,
  标签方法_位异或,
  标签方法_左移,
  标签方法_右移,
  标签方法_负,
  标签方法_位非,
  标签方法_小于,
  标签方法_小等,
  标签方法_连接,
  标签方法_调用,
  标签方法_关闭,
  标签方法_恩		/* 枚举中元素的数量 */
} 嚏摸丝;

/*
** 测试是否没有标签方法。
** (因为标记方法使用原始访问，结果可能为 "空的"  无) 
*/
#define 不标签方法(标签方法)	测试标签是否无(标签方法)

#define 哥快速标签方法(哥,鹅嚏,鹅) ((鹅嚏) == NULL ? NULL : \
  ((鹅嚏)->旗 & (1u<<(鹅))) ? NULL : 炉啊嚏_取标签方法(鹅嚏, 鹅, (哥)->标签方法名字[鹅]))

#define 快速标签方法(嘞,鹅嚏,鹅)	哥快速标签方法(哥(嘞), 鹅嚏, 鹅)

#define 嚏类型名字(斯)	炉啊嚏_类型名字_[(斯) + 1]

炉啊艾_迪十二月(const char *const 炉啊嚏_类型名字_[炉啊_总共类型];)

炉啊艾_函 const char *炉啊嚏_对象类型名字 (炉啊_国 *嘞, const 嚏值 *欧);

炉啊艾_函 const 嚏值 *炉啊嚏_取标签方法 (表 *事件, 嚏摸丝 事件, 嚏串 *鹅名字);
炉啊艾_函 const 嚏值 *炉啊嚏_取标签方法通过对象 (炉啊_国 *嘞, const 嚏值 *欧,
                                                       嚏摸丝 事件);
炉啊艾_函 void 炉啊嚏_初始 (炉啊_国 *嘞);

炉啊艾_函 void 炉啊嚏_调用标签方法 (炉啊_国 *嘞, const 嚏值 *弗, const 嚏值 *匹1,
                            const 嚏值 *匹2, const 嚏值 *匹3);
炉啊艾_函 void 炉啊嚏_调用标签方法返丝 (炉啊_国 *嘞, const 嚏值 *弗,
                            const 嚏值 *匹1, const 嚏值 *匹2, 丝嚏颗身份 匹3);
炉啊艾_函 void 炉啊嚏_尝试二元标签方法 (炉啊_国 *嘞, const 嚏值 *匹1, const 嚏值 *匹2,
                              丝嚏颗身份 返丝, 嚏摸丝 事件);
炉啊艾_函 void 炉啊嚏_尝试连接标签方法 (炉啊_国 *嘞);
炉啊艾_函 void 炉啊嚏_尝试二元关联标签方法 (炉啊_国 *嘞, const 嚏值 *匹1,
       const 嚏值 *匹2, int 内微, 丝嚏颗身份 返丝, 嚏摸丝 事件);
炉啊艾_函 void 炉啊嚏_尝试二元艾标签方法 (炉啊_国 *嘞, const 嚏值 *匹1, 炉啊_整数 艾2,
                               int 内微, 丝嚏颗身份 返丝, 嚏摸丝 事件);
炉啊艾_函 int 炉啊嚏_调用秩序标签方法 (炉啊_国 *嘞, const 嚏值 *匹1,
                                const 嚏值 *匹2, 嚏摸丝 事件);
炉啊艾_函 int 炉啊嚏_调用秩序艾标签方法 (炉啊_国 *嘞, const 嚏值 *匹1, int 微2,
                                 int 内微, int 是否浮点, 嚏摸丝 事件);

炉啊艾_函 void 炉啊嚏_啊迪仅可变参数 (炉啊_国 *嘞, int 恩固定杂参,
                                   struct 调用信息 *调信, const 原型 *匹);
炉啊艾_函 void 炉啊嚏_取可变参数 (炉啊_国 *嘞, struct 调用信息 *调信,
                                              丝嚏颗身份 哪里, int 通缉);


#endif