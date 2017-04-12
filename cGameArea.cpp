/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cGameArea.cpp
*	内容摘要:
*			游戏区域类的实现
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/
#include <easyx.h>
#include <time.h>
#include "cCell.h"
#include "cGameArea.h"

/**************************************************************
*	函数名称: InitArea
*	函数功能:
*		初始化游戏区域
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::InitArea()
{
	int nTmpX = 0;
	int nTmpY = 0;
	BeginBatchDraw();				//开始批量绘制
	//setfillstyle(2);			//游戏区域黑色填充
	setfillcolor(BLACK);
	bar(0, 0, AREASIZE, AREASIZE);	//绘制游戏区域

	for(nTmpX = 0; nTmpX < 60; nTmpX++)
	{
		for(nTmpY = 0; nTmpY < 60; nTmpY++)
		{
			//绘制边框
			if(0 == nTmpX || 59 == nTmpX || 0 == nTmpY || 58 == nTmpY)
			{
				cGmArea[nTmpX][nTmpY].SetXY(nTmpX * CELLSIZE, nTmpY * CELLSIZE);
				cGmArea[nTmpX][nTmpY].SetType(BARRIER);
				cGmArea[nTmpX][nTmpY].SetColorDisplayCell(RGB(237,28,36));
			}
			else if(((25 == nTmpY || 35 == nTmpY) && ((nTmpX > 10 && nTmpX <= 25)
												 || (nTmpX >= 35 && nTmpX < 50)))
				 || ((25 == nTmpX || 35 == nTmpX) && ((nTmpY > 10 && nTmpY <= 25)
				                                 || (nTmpY >= 35 &&  nTmpY < 50))))
			{
				cGmArea[nTmpX][nTmpY].SetXY(nTmpX * CELLSIZE, nTmpY * CELLSIZE);
				cGmArea[nTmpX][nTmpY].SetType(BARRIER);
				cGmArea[nTmpX][nTmpY].SetColorDisplayCell(CYAN);
			}
			//绘制游戏区域
			else
			{
				cGmArea[nTmpX][nTmpY].SetXY(nTmpX * CELLSIZE, nTmpY * CELLSIZE);
				cGmArea[nTmpX][nTmpY].SetType(EMPTY);
				cGmArea[nTmpX][nTmpY].SetColorDisplayCell(BLACK);
			}
		}
	}

	CreateFood();
	EndBatchDraw();
}

/**************************************************************
*	函数名称: ChangeColor
*	函数功能:
*		改变指定格子的颜色
*	参数列表:
*		X			[IN]	指定格子左上角X坐标
*		Y			[IN]	指定格子左上角Y坐标
*		cNewColor	[IN]	改变后的颜色
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::ChangeColor(int X, int Y, COLORREF cNewColor)
{
	cGmArea[X][Y].SetColorDisplayCell(cNewColor);
}

/**************************************************************
*	函数名称: CreateFood
*	函数功能:
*		创建食物
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
bool cGameArea::CreateFood()
{
	srand(time(NULL));
	nFoodX = rand() % 58 + 1;
	nFoodY = rand() % 58 + 1;

	if(cGmArea[nFoodX][nFoodY].GetType() == EMPTY)
	{
		cGmArea[nFoodX][nFoodY].SetColorDisplayCell(GREEN);
		cGmArea[nFoodX][nFoodY].SetType(FOOD);
		return true;
	}

	for(nFoodX = 1; nFoodX < 59; nFoodX++)
	{
		for(nFoodY = 1; nFoodY < 59; nFoodY++)
		{
			if(cGmArea[nFoodX][nFoodY].GetType() == EMPTY)
			{
				cGmArea[nFoodX][nFoodY].SetColorDisplayCell(GREEN);
				cGmArea[nFoodX][nFoodY].SetType(FOOD);
				return true;
			}
		}
	}

	return false;
}

/**************************************************************
*	函数名称: DeleteFood
*	函数功能:
*		删除食物
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::DeleteFood()
{
	cGmArea[nFoodX][nFoodY].SetType(EMPTY);
}