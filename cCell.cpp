/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cCell.cpp
*	����ժҪ:
*			�������ʵ��
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/
#include <conio.h>
#include "cCell.h"

/**************************************************************
*	��������: cCell
*	��������:
*		�������(���캯��)
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
*	��������: SetXY
*	��������:
*		���ø������Ͻ�����
*	�����б�:
*		nPramX	[IN]	���Ͻ�X����
*		nPramY	[IN]	���Ͻ�Y����
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetXY(int nPramX, int nPramY)
{
	nX = nPramX;
	nY = nPramY;
}

/**************************************************************
*	��������: SetType
*	��������:
*		���ø�������
*	�����б�:
*		nPramType	[IN]	��������
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetType(int nPramType)
{
	nType = nPramType;
}

/**************************************************************
*	��������: SetColorDisplayCell
*	��������:
*		���ø�����ɫ�����Ƹ���
*	�����б�:
*		cPramColor	[IN]	������ɫ
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cCell::SetColorDisplayCell(COLORREF cPramColor)
{
	cColor = cPramColor;
	setfillcolor(cColor);
	bar(nX, nY, nX + CELLSIZEIN, nY + CELLSIZEIN);
}

/**************************************************************
*	��������: DisplayLaser
*	��������:
*		��ʾ����״����
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
*	��������: DisplayLaser
*	��������:
*		��ȡ��������
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
int cCell::GetType()
{
	return nType;
}							
