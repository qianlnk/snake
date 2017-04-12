/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cGameArea.cpp
*	����ժҪ:
*			��Ϸ�������ʵ��
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/
#include <easyx.h>
#include <time.h>
#include "cCell.h"
#include "cGameArea.h"

/**************************************************************
*	��������: InitArea
*	��������:
*		��ʼ����Ϸ����
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::InitArea()
{
	int nTmpX = 0;
	int nTmpY = 0;
	BeginBatchDraw();				//��ʼ��������
	//setfillstyle(2);			//��Ϸ�����ɫ���
	setfillcolor(BLACK);
	bar(0, 0, AREASIZE, AREASIZE);	//������Ϸ����

	for(nTmpX = 0; nTmpX < 60; nTmpX++)
	{
		for(nTmpY = 0; nTmpY < 60; nTmpY++)
		{
			//���Ʊ߿�
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
			//������Ϸ����
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
*	��������: ChangeColor
*	��������:
*		�ı�ָ�����ӵ���ɫ
*	�����б�:
*		X			[IN]	ָ���������Ͻ�X����
*		Y			[IN]	ָ���������Ͻ�Y����
*		cNewColor	[IN]	�ı�����ɫ
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::ChangeColor(int X, int Y, COLORREF cNewColor)
{
	cGmArea[X][Y].SetColorDisplayCell(cNewColor);
}

/**************************************************************
*	��������: CreateFood
*	��������:
*		����ʳ��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
*	��������: DeleteFood
*	��������:
*		ɾ��ʳ��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cGameArea::DeleteFood()
{
	cGmArea[nFoodX][nFoodY].SetType(EMPTY);
}