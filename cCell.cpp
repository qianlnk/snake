/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cCell.cpp
*	内容摘要:
*			格子类的实现
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/
#include <conio.h>
#include "cCell.h"

/**************************************************************
*	函数名称: cCell
*	函数功能:
*		构造格子(构造函数)
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
cCell::cCell()
{
	nX = 0;
	nY = 0;
	nType = EMPTY;
	cColor = BLACK;
}

/**************************************************************
*	函数名称: SetXY
*	函数功能:
*		设置格子左上角坐标
*	参数列表:
*		nPramX	[IN]	左上角X坐标
*		nPramY	[IN]	左上角Y坐标
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetXY(int nPramX, int nPramY)
{
	nX = nPramX;
	nY = nPramY;
}

/**************************************************************
*	函数名称: SetType
*	函数功能:
*		设置格子类型
*	参数列表:
*		nPramType	[IN]	格子类型
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetType(int nPramType)
{
	nType = nPramType;
}

/**************************************************************
*	函数名称: SetColorDisplayCell
*	函数功能:
*		设置格子颜色并绘制格子
*	参数列表:
*		cPramColor	[IN]	格子颜色
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetColorDisplayCell(COLORREF cPramColor)
{
	cColor = cPramColor;
	setfillcolor(cColor);
	bar(nX, nY, nX + CELLSIZEIN, nY + CELLSIZEIN);
}

/**************************************************************
*	函数名称: DisplayLaser
*	函数功能:
*		显示镭射状格子
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::DisplayLaser()
{
	IMAGE iImage(CELLSIZE, CELLSIZE);
	SetWorkingImage(&iImage);
	DWORD* pdMem = GetImageBuffer(&iImage);
	for(int iIndex = 0; iIndex < CELLSIZE * CELLSIZE; iIndex++)
	{
		pdMem[iIndex] = BGR(RGB(0, 0, iIndex * 256 / (CELLSIZE * CELLSIZE)));
	}
	SetWorkingImage(NULL);
	putimage(nX, nY, &iImage);
}

/**************************************************************
*	函数名称: DisplayLaser
*	函数功能:
*		获取格子类型
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
int cCell::GetType()
{
	return nType;
}							
