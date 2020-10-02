/*
** $ 身份：嘞前缀.h $
** 炉啊代码的定义必须在任何其他头文件之前
**请参见炉啊.h中的版权声明
*/

#ifndef 嘞前缀_喝
#define 嘞前缀_喝

/*
**允许 POSIX/XSI 内容
*/
#if !defined(炉啊_用_C89)	/* { */

#if !defined(_斯开_源)
#define _斯开_源           600
#elif _斯开_源 == 0
#undef _斯开_源  /* 使用 -迪_斯开_源 = 0 取消定义 */
#endif

/*
**允许在gcc和其他一些编译器中处理大文件
*/
#if !defined(炉啊_32位) && !defined(_文件_偏移_位)
#define _大文件_源       1
#define _文件_偏移_位       64
#endif

#endif				/* } */

/*
** Windows的东西
*/
#if defined(_WIN32)	/* { */

#if !defined(_CRT_安全_无_警告)
#define _CRT_安全_无_警告  /* 避免有关ISO C功能的警告 */
#endif

#endif			/* } */

#endif