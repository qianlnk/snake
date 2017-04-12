/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cGameArea.h
*	内容摘要:
*			定义游戏区域类
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CGAMEAREA_H_
#define _CGAMEAREA_H_

#include <graphics.h>
#include "cCell.h"

#define	CELLNUM			60		//游戏区域大小
#define AREASIZE		CELLNUM * 10
//创建游戏区域类
class cGameArea
{
public:
	cCell cGmArea[CELLNUM][CELLNUM];				//定义游戏区域60 * 60
	void InitArea();									//初始化游戏区域
	void ChangeColor(int X, int Y, COLORREF cNewColor);	//改变指定格子的颜色
	bool CreateFood();									//创建食物
	void DeleteFood();									//删除食物


private:
	int nFoodX;					//食物坐标X
	int nFoodY;					//食物坐标Y
};
#endif//_CGAMEAREA_H_