/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cSnake.cpp
*	内容摘要:
*			蛇类的实现
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#include "cSnake.h"
#include "cGameArea.h"

/**************************************************************
*	函数名称: cSnake
*	函数功能:
*		构造蛇类(构造函数)
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
cSnake::cSnake()
{
	pstHead = NULL;
	pstLast = NULL;
	pstNow = NULL;
}

/**************************************************************
*	函数名称: SnakeInit
*	函数功能:
*		初始化蛇的结构
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::SnakeInit()
{
	if(pstHead != NULL)
	{
		for(pstNow = pstHead->pstNext; 
		pstNow->pstNext != NULL; 
		pstNow = pstNow->pstNext)
		{
			free(pstNow->pstPrior);
		}

		if(pstNow->pstNext != NULL)
		{
			free(pstNow->pstPrior);
			free(pstNow);
		}
	}

	pstHead = (SNAKE_T *)malloc(sizeof(SNAKE_T));
	pstNow = (SNAKE_T *)malloc(sizeof(SNAKE_T));
	pstHead->pstPrior = NULL;
	pstHead->pstNext = pstNow;
	pstHead->nX = (int)(AREASIZE / 2);
	pstHead->nY = (int)(AREASIZE / 2);

	pstNow->pstPrior = pstHead;
	pstNow->pstNext = NULL;
	pstNow->nX = (int)(AREASIZE / 2);
	pstNow->nY = (int)(AREASIZE / 2) - CELLSIZE;

	pstLast = pstNow;

	nDirection = DOWN;
}

/**************************************************************
*	函数名称: AddSnakeCell
*	函数功能:
*		添加一格蛇身
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::AddSnakeCell()
{
	pstNow = pstHead;
	pstNow->pstPrior = (SNAKE_T *)malloc(sizeof(SNAKE_T));
	pstNow = pstNow->pstPrior;
	pstNow->pstPrior = NULL;
	pstNow->pstNext = pstHead;

	switch(nDirection)
	{
	case UP:
		{
			pstNow->nX = pstHead->nX;
			pstNow->nY = pstHead->nY - CELLSIZE;
			break;
		}
	case DOWN:
		{
			pstNow->nX = pstHead->nX;
			pstNow->nY = pstHead->nY + CELLSIZE;
			break;
		}
	case LEFT:
		{
			pstNow->nX = pstHead->nX - CELLSIZE;
			pstNow->nY = pstHead->nY;
			break;
		}
	case RIGHT:
		{
			pstNow->nX = pstHead->nX + CELLSIZE;
			pstNow->nY = pstHead->nY;
			break;
		}
	default:
		{
			break;
		}
	}

	pstHead = pstNow;
}

/**************************************************************
*	函数名称: DelSnakeCell
*	函数功能:
*		删除一格蛇身
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::DelSnakeCell()
{
	pstLast = pstLast->pstPrior;
	free(pstLast->pstNext);
	pstLast->pstNext = NULL;
}

/**************************************************************
*	函数名称: SnakeMove
*	函数功能:
*		蛇移动一格
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::SnakeMove()
{
	AddSnakeCell();
	DelSnakeCell();
}