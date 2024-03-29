/*
** $ 身份: 嘞垃圾回收.h $
** 垃圾回收器
** 请参见 炉啊.h中的版权声明
*
** 本人所用声母表: a啊 b哔 c西 d迪 e鹅 f弗 g哥 
* h喝 i艾 j鸡 k颗 l嘞 m摸 n恩
* o欧 p匹 q气 r日 s丝 t嚏 
* u由 v微 w屋 x斯 y医 z只
*
* 一些英文单词缩写,我的翻译大多来自;有道词典,谷歌翻译,百度.
* 一些术语实在不好翻译,所以就原封不动.
* 
*/

#ifndef 嘞垃圾回收_喝
#define 嘞垃圾回收_喝


#include "嘞对象.h"
#include "嘞国.h"

/*
** 可回收的对象可能具有以下三种颜色之一:
*  白色,表示该对象未标记; 灰色,表示
** 对象已标记,但其引用可能未标记; 和
** 黑色,表示该对象及其所有引用均已标记.
** 在标记对象时,垃圾回收器的主要不变性,
** 是黑色物体永远不能指向白色物体. 此外,
** 任何灰色物体都必须在 '灰色列表' 中 (灰色,再度灰色,弱,
** 所有弱的,短暂存在的) ,以便在完成之前可以再次访问它
** 回收周期. 这些列表没有意义时不变
** 未强制执行 (例如，清扫阶段) .
*/

/*
** 垃圾回收器的可能状态
*/
#define 垃圾回收状态增殖	0
#define 垃圾回收状态进入原子	1
#define 垃圾回收状态原子	2
#define 垃圾回收状态交换所有垃圾回收	3
#define 垃圾回收状态交换最终对象	4
#define 垃圾回收状态交换存在定案	5
#define 垃圾回收状态交换终	6
#define 垃圾回收状态调用最终	7
#define 垃圾回收状态暂停	8

#define 是否打扫阶段(哥)  \
	(垃圾回收状态扫所有垃圾回收 <= (哥)->垃圾回收状态 && (哥)->垃圾回收状态 <= 垃圾回收状态扫终)

/*
* 告诉 主 不变式的宏
* (白色对象不能指向黑色对象) 必须保留.
*  在回收期间
* 打扫阶段可能会破坏不变性,因为变成白色的对象可能指向仍然是黑色的对象.
* 当打扫结束并且所有对象再次变为白色时,将恢复不变性.
*/
#define 保持不变(哥)	((哥)->垃圾回收状态 <= 垃圾回收状态原子)

/*
** 一些有用的技巧
*/
#define 重置位(斯,摸)		((斯) &= 投_字节(~(摸)))
#define 设置位(斯,摸)		((斯) |= (摸))
#define 测试位(斯,摸)		((斯) & (摸))
#define 位口罩(哔)		(1<<(哔))
#define 位到口罩(哔1,哔2)		(位口罩(哔1) | 位口罩(哔2))
#define 嘞_设置位(斯,哔)		设置位(斯, 位口罩(哔))
#define 重置位单(斯,哔)		重置位(斯, 位口罩(哔))
#define 测试位单(斯,哔)		测试位(斯, 位口罩(哔))

/*
** 在 "标出的" 字段中使用位的布局 .
 前三位是在世代模式中用于对象 "年龄" . 
 最后一位是空闲的将被各自的对象使用 .
*/

#define 白色0位	3  /* 对象是白色的 (类型 0) */
#define 白色1位	4  /* 对象是白色的 (类型 1) */
#define 黑色位	5  /* 对象是黑色的 */
#define 最终位	6  /* 对象已标示为结束 */

#define 白色位	位到口罩(白色0位, 白色1位)


#define 是否白色(斯)      测试位((斯)->已作记号, 白色位)
#define 是否黑色(斯)      测试位单((斯)->已作记号, 黑色位)
#define 是否灰色(斯)  /* 不白不黑 */  \
	(!测试位((斯)->已作记号, 白色位 | 位口罩(黑色位)))

#define 到最终(斯)	测试位单((斯)->已作记号, 最终位)

#define 其它白色(哥)	((哥)->当前白色 ^ 白色位)
#define 是否死摸(欧屋,摸)	((摸) & (欧屋))
#define 是否死(哥,微)	是否死摸(其它白色(哥), (微)->已作记号)

#define 改变白色(斯)	((斯)->已作记号 ^= 白色位)
#define 灰色到黑色(斯)	嘞_设置位((斯)->已作记号, 黑色位)

#define 炉啊西_白色(哥)	投_字节((哥)->当前白色 & 白色位)

/* 世代模式下的对象年龄 */
#define 哥_新		0	/* 在当前周期中创建 */
#define 哥_生存	1	/* 在前一个循环中创建 */
#define 哥_老0		2	/* 通过第一屋标出老 . 这个周期中的障碍 */
#define 哥_老1		3	/* 第一个完整的周期作为老 */
#define 哥_老		4	/* 很旧的对象 (不可访问) */
#define 哥_已触摸1	5	/* 旧对象触碰此循环 */
#define 哥_已触摸2	6	/* 旧对象在上一个循环中被触及 */

#define 年龄位		7  /* 所有年龄位 (111) */

#define 取年龄(欧)	((欧)->已作记号 & 年龄位)
#define 设置年龄(欧,啊)  ((欧)->已作记号 = 投_字节(((欧)->已作记号 & (~年龄位)) | 啊))
#define 是否老(欧)	(取年龄(欧) > 哥_生存)

#define 改变年龄(欧,弗,嚏)  \
	检查_表达式(取年龄(欧) == (弗), (欧)->已作记号 ^= ((弗)^(嚏)))

/* 垃圾回收参数的默认值 */
#define 炉啊艾_生成少校乘         100
#define 炉啊艾_生成辅修乘         20

/* 在开始新的循环之前等待内存双倍 */
#define 炉啊艾_垃圾回收暂停    200

/*
** 一些垃圾回收参数被存储为4 , 允许一个 "炉_字节" 的最大值为1023 .
*/
#define 取垃圾回收形参(匹)	((匹) * 4)
#define 设置垃圾回收形参(匹,微)	((匹) = (微) / 4)

#define 炉啊艾_垃圾回收乘      100

/* 下一个垃圾回收步骤之前要分配多少 (log2 - 对数2) */
#define 炉啊艾_垃圾回收步骤大小 13      /* 8 KB - 8 千字节 */

/*
 检查声明的垃圾回收模式是否世代.
 在世代模式下,
 回收器可以临时进入增量模式去改善性能.
 这个信号通过 '哥->最后原子 != 0'
*/
#define 是否十二月垃圾回收模式生成(哥)	(哥->垃圾回收种类 == 颗垃圾回收_生成 || 哥->最后原子 != 0)

/*
 当欠债变成正数时做了回收的第一步 .
 '预' / '销售点' 只允许在需要的时候做一些调整 .
 宏 '条件改变内存' 只用于大型测试,
 (在每个机会上强制执行完整的垃圾回收周期)
*/
#define 炉啊西_条件垃圾回收(嘞,预,销售点) \
	{ if (哥(嘞)->垃圾回收欠债 > 0) { 预; 炉啊西_步骤(嘞); 销售点;}; \
	  条件改变内存(嘞,预,销售点); }


/* 通常, '预'/'销售点' 是空的 */
#define 炉啊西_检查垃圾回收(嘞)		炉啊西_条件垃圾回收(嘞,(void)0,(void)0)


#define 炉啊西_障碍(嘞,匹,微) (  \
	(是否回收表(微) && 是否黑色(匹) && 是否白色(垃圾回收值(微))) ?  \
	炉啊西_障碍_(嘞,对象到垃圾回收欧(匹),垃圾回收值(微)) : 投_空的(0))

#define 炉啊西_障碍背后(嘞,匹,微) (  \
	(是否回收表(微) && 是否黑色(匹) && 是否白色(垃圾回收值(微))) ? \
	炉啊西_障碍背后_(嘞,匹) : 投_空的(0))

#define 炉啊西_对象障碍(嘞,匹,欧) (  \
	(是否黑色(匹) && 是否白色(欧)) ? \
	炉啊西_障碍_(嘞,对象到垃圾回收欧(匹),对象到垃圾回收欧(欧)) : 投_空的(0))

炉啊艾_函 void 炉啊西_固定 (炉啊_国 *嘞, 垃圾回收对象 *欧);
炉啊艾_函 void 炉啊西_自由所有对象 (炉啊_国 *嘞);
炉啊艾_函 void 炉啊西_步骤 (炉啊_国 *嘞);
炉啊艾_函 void 炉啊西_日直到国 (炉啊_国 *嘞, int 国口罩);
炉啊艾_函 void 炉啊西_完全垃圾回收 (炉啊_国 *嘞, int 是否紧急);
炉啊艾_函 垃圾回收对象 *炉啊西_新对象 (炉啊_国 *嘞, int 嚏嚏, size_t 丝只);
炉啊艾_函 void 炉啊西_障碍_ (炉啊_国 *嘞, 垃圾回收对象 *欧, 垃圾回收对象 *微);
炉啊艾_函 void 炉啊西_障碍背后_ (炉啊_国 *嘞, 垃圾回收对象 *欧);
炉啊艾_函 void 炉啊西_检查终止 (炉啊_国 *嘞, 垃圾回收对象 *欧, 表 *摸嚏);
炉啊艾_函 void 炉啊西_改变模式 (炉啊_国 *嘞, int 新模式);


#endif