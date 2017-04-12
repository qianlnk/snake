/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cMng.cpp
*	内容摘要:
*			游戏管理类的实现
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/
#include <conio.h>
#include <stdio.h>
#include "cMng.h"

/**************************************************************
*	函数名称: TimeGo
*	函数功能:
*		走时
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::TimeGo(double dAdd)
{
	dTime += dAdd;
	DisplayTime();
}

/**************************************************************
*	函数名称: ScoreAcount
*	函数功能:
*		计分
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::ScoreAcount(int nAdd)
{
	nScore += nAdd;
	DisplayScore();
}

/**************************************************************
*	函数名称: DisplayStatus
*	函数功能:
*		显示游戏状态
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayStatus()
{
	BeginBatchDraw();
	_stprintf(cScore, _T("%d"), nScore);
	setfont(25, 0, _T("微软雅黑"));
	setfillcolor(cColor);
	bar(625,490,800,515);
	setcolor(BLUE);
	if(bPause)
	{
		outtextxy(625, 490, _T("开始（P键）"));
	}
	else
	{
		outtextxy(625, 490, _T("暂停（P键）"));
	}
	EndBatchDraw();
}

/**************************************************************
*	函数名称: InitMng
*	函数功能:
*		初始化logo栏
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
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
	_stprintf(cScore, _T("%d"), nScore);  //格式化转换类型
	_stprintf(cTime, _T("%.1lf"), dTime);
	cColor = BLACK;
	BeginBatchDraw();
	setfillcolor(BLACK);
	bar(601,0,800,600);
	setfont(60, 0, _T("微软雅黑"));
	setcolor(GREEN);
	outtextxy(625, 30, _T("贪吃蛇"));
	setfont(30, 0, _T("微软雅黑"));
	setcolor(RGB(128,0,255));
	outtextxy(625, 140, _T("制作：浅诺"));
	setfont(25, 0, _T("微软雅黑"));
	setcolor(BLUE);
	outtextxy(625, 430, _T("时间："));
	outtextxy(625, 460, _T("分数："));
	outtextxy(625, 490, _T("暂停（P键）"));
	outtextxy(625, 520, _T("重新游戏（R键）"));
	setcolor(RED);
	outtextxy(720, 400, cLeave);
	outtextxy(680, 460,cScore);
	outtextxy(680, 430, cTime);
	DisplayLED();
	EndBatchDraw();
}

/**************************************************************
*	函数名称: DisplayTime
*	函数功能:
*		显示时间
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayTime()
{
	BeginBatchDraw();
	_stprintf(cTime, _T("%.1lf"), dTime);
	setfont(25, 0, _T("微软雅黑"));
	setfillcolor(cColor);
	bar(680,430,800,455);
	setcolor(RED);
	outtextxy(680,430,cTime);
	EndBatchDraw();
}

/**************************************************************
*	函数名称: DisplayScore
*	函数功能:
*		显示分数
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::DisplayScore()
{
	BeginBatchDraw();
	_stprintf(cScore, _T("%d"), nScore);
	setfont(25, 0, _T("微软雅黑"));
	setfillcolor(cColor);
	bar(680,460,800,485);
	setcolor(RED);
	outtextxy(680,460,cScore);
	EndBatchDraw();
}

/**************************************************************
*	函数名称: DisplayLED
*	函数功能:
*		显示红绿灯
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
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
*	函数名称: CountDown
*	函数功能:
*		显示倒计时
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void cMng::CountDown()
{
	nCountDown--;

	BeginBatchDraw();
	_stprintf(cCount, _T("%d"), nCountDown);
	setfont(25, 0, _T("微软雅黑"));
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