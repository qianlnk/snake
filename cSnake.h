/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cSnake.h
*	内容摘要:
*			定义蛇类
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CSNAKE_H_
#define _CSNAKE_H_

#include <graphics.h>


#define UP		10
#define DOWN	20
#define LEFT	30
#define RIGHT	40

//定义蛇类
class cSnake{
public:
	int nDirection;						//蛇动的方向(分上下左右)
	cSnake();							//构造函数
	void SnakeInit();					//初始化蛇的结构
	void AddSnakeCell();				//添加一格蛇身
	void DelSnakeCell();				//删除一格蛇身
	void SnakeMove();					//蛇移动一格

	friend void MessageDispose();
	friend void ReInit(); 
private:
	typedef struct tagSNAKE_T
	{
		int nX;							//一格蛇蛇左上角的X坐标
		int nY;							//一格蛇蛇左上角的Y坐标
		struct tagSNAKE_T *pstNext;		//前一个节点
		struct tagSNAKE_T *pstPrior;	//后一个节点
	}SNAKE_T;

	SNAKE_T *pstHead;					//头节点
	SNAKE_T *pstLast;					//尾节点
	SNAKE_T *pstNow;					//当前节点
};

#endif//_CSNAKE_H_