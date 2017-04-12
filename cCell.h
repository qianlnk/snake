/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cCell.h
*	内容摘要:
*			定义格子类
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CCELL_H_
#define _CCELL_H_

#include <graphics.h>	//c++图形库，我这里使用EasyX_2011惊蛰版

#define	EMPTY		0	//空位
#define	BARRIER		-1	//障碍物
#define	FOOD		1	//食物
#define CELLSIZEIN	7	//格子大小
#define CELLSIZE	10

//创建格子类
class cCell  
{
public:
	cCell();										//构造函数
	void SetXY(int nPramX, int nPramY);				//设置格子左上角坐标
    void SetType(int nPramType);					//设置格子类型
	void SetColorDisplayCell(COLORREF cPramColor);	//设置格子颜色
	void DisplayLaser();							//显示镭射状格子
	int GetType();									//获取格子类型
	//virtual ~cCell();								//析构函数

	friend class cGameArea;	//友元类cGameArea可直接访问本类私有成员

private:
	int nX;											//格子左上角X坐标
	int nY;											//格子左上角Y坐标
	int nType;										//格子类型，0--空 -1--障碍 1--食物
	COLORREF cColor;								//格子颜色
};

#endif//_CCELL_H_
