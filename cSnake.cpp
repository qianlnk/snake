/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cSnake.cpp
*	����ժҪ:
*			�����ʵ��
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/

#include "cSnake.h"
#include "cGameArea.h"

/**************************************************************
*	��������: cSnake
*	��������:
*		��������(���캯��)
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
cSnake::cSnake()
{
	pstHead = NULL;
	pstLast = NULL;
	pstNow = NULL;
}

/**************************************************************
*	��������: SnakeInit
*	��������:
*		��ʼ���ߵĽṹ
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
*	��������: AddSnakeCell
*	��������:
*		���һ������
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
*	��������: DelSnakeCell
*	��������:
*		ɾ��һ������
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::DelSnakeCell()
{
	pstLast = pstLast->pstPrior;
	free(pstLast->pstNext);
	pstLast->pstNext = NULL;
}

/**************************************************************
*	��������: SnakeMove
*	��������:
*		���ƶ�һ��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cSnake::SnakeMove()
{
	AddSnakeCell();
	DelSnakeCell();
}