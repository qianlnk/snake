/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cMng.cpp
*	����ժҪ:
*			��Ϸ�������ʵ��
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/
#include <conio.h>
#include <stdio.h>
#include "cMng.h"

/**************************************************************
*	��������: TimeGo
*	��������:
*		��ʱ
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::TimeGo(double dAdd)
{
	dTime += dAdd;
	DisplayTime();
}

/**************************************************************
*	��������: ScoreAcount
*	��������:
*		�Ʒ�
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::ScoreAcount(int nAdd)
{
	nScore += nAdd;
	DisplayScore();
}

/**************************************************************
*	��������: DisplayStatus
*	��������:
*		��ʾ��Ϸ״̬
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayStatus()
{
	BeginBatchDraw();
	_stprintf(cScore, _T("%d"), nScore);
	setfont(25, 0, _T("΢���ź�"));
	setfillcolor(cColor);
	bar(625,490,800,515);
	setcolor(BLUE);
	if(bPause)
	{
		outtextxy(625, 490, _T("��ʼ��P����"));
	}
	else
	{
		outtextxy(625, 490, _T("��ͣ��P����"));
	}
	EndBatchDraw();
}

/**************************************************************
*	��������: InitMng
*	��������:
*		��ʼ��logo��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::InitMng()
{
	dTime = 0.0;
	nScore = 0;
	nLeave = 1;
	bPause = false;
	nCountDown = 11;
	nPunish = 0;
	_stprintf(cScore, _T("%d"), nScore);  //��ʽ��ת������
	_stprintf(cTime, _T("%.1lf"), dTime);
	cColor = BLACK;
	BeginBatchDraw();
	setfillcolor(BLACK);
	bar(601,0,800,600);
	setfont(60, 0, _T("΢���ź�"));
	setcolor(GREEN);
	outtextxy(625, 30, _T("̰����"));
	setfont(30, 0, _T("΢���ź�"));
	setcolor(RGB(128,0,255));
	outtextxy(625, 140, _T("������ǳŵ"));
	setfont(25, 0, _T("΢���ź�"));
	setcolor(BLUE);
	outtextxy(625, 430, _T("ʱ�䣺"));
	outtextxy(625, 460, _T("������"));
	outtextxy(625, 490, _T("��ͣ��P����"));
	outtextxy(625, 520, _T("������Ϸ��R����"));
	setcolor(RED);
	outtextxy(720, 400, cLeave);
	outtextxy(680, 460,cScore);
	outtextxy(680, 430, cTime);
	DisplayLED();
	EndBatchDraw();
}

/**************************************************************
*	��������: DisplayTime
*	��������:
*		��ʾʱ��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayTime()
{
	BeginBatchDraw();
	_stprintf(cTime, _T("%.1lf"), dTime);
	setfont(25, 0, _T("΢���ź�"));
	setfillcolor(cColor);
	bar(680,430,800,455);
	setcolor(RED);
	outtextxy(680,430,cTime);
	EndBatchDraw();
}

/**************************************************************
*	��������: DisplayScore
*	��������:
*		��ʾ����
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayScore()
{
	BeginBatchDraw();
	_stprintf(cScore, _T("%d"), nScore);
	setfont(25, 0, _T("΢���ź�"));
	setfillcolor(cColor);
	bar(680,460,800,485);
	setcolor(RED);
	outtextxy(680,460,cScore);
	EndBatchDraw();
}

/**************************************************************
*	��������: DisplayLED
*	��������:
*		��ʾ���̵�
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayLED()
{
	nCountDown = 11;
	if(nFlag == REDLED)
	{
		setcolor(RED);
		setfillcolor(RED);
		nFlag = GREENLED;
	}
	else
	{
		setcolor(GREEN);
		setfillcolor(GREEN);
		nFlag = REDLED;
	}
	fillcircle(685, 200, 15);
}

/**************************************************************
*	��������: CountDown
*	��������:
*		��ʾ����ʱ
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::CountDown()
{
	nCountDown--;

	BeginBatchDraw();
	_stprintf(cCount, _T("%d"), nCountDown);
	setfont(25, 0, _T("΢���ź�"));
	setfillcolor(cColor);
	bar(680,260,800,400);
	setcolor(RED);
	outtextxy(680,260,cCount);
	EndBatchDraw();

	if(nCountDown <= 0)
	{
		DisplayLED();
	}
}