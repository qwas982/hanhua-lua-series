/*
** $ 身份：嘞代码.h $
** 炉啊的代码生成器
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
*/

#ifndef 嘞代码_喝
#define 嘞代码_喝

#include "嘞词汇.h"
#include "嘞对象.h"
#include "嘞操作码.h"
#include "嘞解析器.h"

/*
** 标记补丁程序列表的末尾. 作为绝对值,它都是无效的地址
** 并作为列表链接 (链接一个元素到自身).
*/
#define 不_跳 (-1)

/*
** 搜索正则打印行 "秩序 操作者" 若你改变这些枚举  (秩序 操作)
*/
typedef enum 二元操作者 {
  /* 算术操作者 */
  操作者_加, 操作者_减, 操作者_乘, 操作者_余数, 操作者_幂,
  操作者_除, 操作者_符号除,
  /* 位移操作者 */
  操作者_位与, 操作者_位或, 操作者_位异或,
  操作者_左移, 操作者_右移,
  /* 串操作者 */
  操作者_连接,
  /* 对比操作者 */
  操作者_等于, 操作者_小于, 操作者_小等,
  操作者_不等, 操作者_大于, 操作者_大等,
  /* 逻辑操作者 */
  操作者_与, 操作者_或,
  操作者_不是二元操作者
} 二元操作者;

/* 如果操作是可折叠的(即,它是算术或位移),则为真 */

#define 折叠二元操作(操作)	((操作) <= 操作者_右移)

#define 炉啊颗_代码甲乙丙(弗丝,欧,啊,哔,西)	炉啊颗_代码甲乙丙颗(弗丝,欧,啊,哔,西,0)

typedef enum 没操作者 { 操作者_负号, 操作者_位非, 操作者_非, 操作者_长度, 操作者_不是没操作者 } 没操作者;

/* 取 (指针指向) 给定指令 '表达式描述' */
#define 取指令(弗丝,鹅)	((弗丝)->弗->代码[(鹅)->由.信息])


#define 炉啊颗_设置乘法返(弗丝,鹅)	炉啊颗_设置返回(弗丝, 鹅, 炉啊_乘法返)

#define 炉啊颗_跳到(弗丝,嚏)	炉啊颗_补丁列表(弗丝, 炉啊颗_跳(弗丝), 嚏)

炉啊艾_函 int 炉啊颗_代码 (函国 *弗丝, 指令 艾);
炉啊艾_函 int 炉啊颗_代码甲乙斯 (函国 *弗丝, 操作码 欧, int 甲, unsigned int 乙斯);
炉啊艾_函 int 炉啊颗_代码甲丝乙斯 (函国 *弗丝, 操作码 欧, int 甲, int 乙斯);
炉啊艾_函 int 炉啊颗_代码甲乙丙颗 (函国 *弗丝, 操作码 欧, int 甲,
                                            int 乙, int 丙, int 颗);
炉啊艾_函 int 炉啊颗_是否颗整型 (表达式描述 *鹅);
炉啊艾_函 int 炉啊颗_表达式到常量 (函国 *弗丝, const 表达式描述 *鹅, 嚏值 *微);
炉啊艾_函 void 炉啊颗_固定行 (函国 *弗丝, int 行);
炉啊艾_函 void 炉啊颗_无 (函国 *弗丝, int 来自, int 恩);
炉啊艾_函 void 炉啊颗_重新服务寄存 (函国 *弗丝, int 恩);
炉啊艾_函 void 炉啊颗_检查栈 (函国 *弗丝, int 恩);
炉啊艾_函 void 炉啊颗_整型 (函国 *弗丝, int 寄存, 炉啊_整数 恩);
炉啊艾_函 void 炉啊颗_排出变量 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 int 炉啊颗_表达式到任意寄存 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_表达式到任意寄存上 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_表达式到下一个寄存 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_表达式到值 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 int 炉啊颗_表达式到寄存器常量 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_自己 (函国 *弗丝, 表达式描述 *鹅, 表达式描述 *键);
炉啊艾_函 void 炉啊颗_已索引 (函国 *弗丝, 表达式描述 *嚏, 表达式描述 *颗);
炉啊艾_函 void 炉啊颗_去若真 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_去若假 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_存储变量 (函国 *弗丝, 表达式描述 *变量, 表达式描述 *鹅);
炉啊艾_函 void 炉啊颗_设置返回 (函国 *弗丝, 表达式描述 *鹅, int 恩结果);
炉啊艾_函 void 炉啊颗_设置一个返 (函国 *弗丝, 表达式描述 *鹅);
炉啊艾_函 int 炉啊颗_跳 (函国 *弗丝);
炉啊艾_函 void 炉啊颗_返 (函国 *弗丝, int 第一, int 恩返);
炉啊艾_函 void 炉啊颗_补丁列表 (函国 *弗丝, int 列表, int 目标);
炉啊艾_函 void 炉啊颗_补丁到这里 (函国 *弗丝, int 列表);
炉啊艾_函 void 炉啊颗_连接 (函国 *弗丝, int *嘞1, int 嘞2);
炉啊艾_函 int 炉啊颗_取签条 (函国 *弗丝);
炉啊艾_函 void 炉啊颗_前缀 (函国 *弗丝, 没操作者 操作, 表达式描述 *微, int 行);
炉啊艾_函 void 炉啊颗_中缀 (函国 *弗丝, 二元操作者 操作, 表达式描述 *微);
炉啊艾_函 void 炉啊颗_后缀 (函国 *弗丝, 二元操作者 操作, 表达式描述 *微1,
                            表达式描述 *微2, int 行);
炉啊艾_函 void 炉啊颗_设置表大小 (函国 *弗丝, int 程序计数,
                                  int 日啊, int 啊大小, int 喝大小);
炉啊艾_函 void 炉啊颗_设置列表 (函国 *弗丝, int 基础, int 恩元素, int 到存储);
炉啊艾_函 void 炉啊颗_完成 (函国 *弗丝);
炉啊艾_函 嘞_不返 炉啊颗_语义错误 (词国 *嘞丝, const char *消息);


#endif