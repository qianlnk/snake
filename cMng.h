/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cMng.h
*	内容摘要:
*			定义游戏管理类
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CMNG_H_
#define _CMNG_H_

#define REDLED		100
#define GREENLED	200

#include <graphics.h>
//定义游戏管理
class cMng{
public:
	void TimeGo(double dAdd);
	void ScoreAcount(int nAdd);
	void DisplayStatus();
	void InitMng();
	void DisplayLED();
	void CountDown();

	friend void MessageDispose();
private:
	double dTime;
	int nScore;
	int nLeave;
	bool bPause;
	int nCountDown;	//红绿灯倒计时
	int nFlag;
	int nPunish;	//扣分
	TCHAR cCount[4]; //倒计时
	TCHAR cTime[33];
	TCHAR cScore[5];
	TCHAR cLeave[2];
	COLORREF cColor;
	void DisplayTime();
	void DisplayScore();
};
#endif//_CMNG_H_
