/*
** $ 身份：嘞应用程序接口.h $
** 炉啊 应用程序接口的辅助功能
**请参见炉啊.h中的版权声明
*/

#ifndef 嘞应用程序接口_喝
#define 嘞应用程序接口_喝

#include "嘞极限.h"
#include "嘞国.h"

/* 递增 "嘞->顶"，检查栈溢出 */
#define 应用程序接口_增量调用返回_顶(嘞)   {嘞->顶++; 应用程序接口_检查(嘞, 嘞->顶 <= 嘞->调用信息->顶 \
				"栈 溢出");}

/*
**若一个调用返回有太多多返回，则被调可能没有
**栈空间可容纳所有结果。 在这种情况下，此宏
**增加其栈空间（'嘞->调用信息->顶'）。
*/
#define 啊迪仅结果(嘞,恩结果) \
    { if ((恩结果) <= 炉啊_多返回 && 嘞->调用信息->顶 < 嘞->顶) 嘞->调用信息->顶 = 嘞->顶; }

/* 确保栈中至少包含'n'个元素 */
#define 应用程序接口_检查恩元素(嘞,恩)	应用程序接口_检查(嘞, (恩) < (嘞->顶 - 嘞->调用信息->函), \
				  "栈中没有足够的元素")

/*
**为了减少从C函数返回的开销,存在
**这些函数中的 待-关闭 变量在 调用信息 的代码中进行了编码
**字段"恩结果",其功能不包含任何 待-关闭 的变量
**具有零,一,或 "全部" 所需结果的系统没有开销. 功能
**与其他所需的结果数量以及
**要关闭的变量,请进行额外检查.
*/

#define 有到关闭西函(恩)	((恩) < 炉啊_多返回)

#define 代码恩结果(恩)		(-(恩) - 3)

#endif
