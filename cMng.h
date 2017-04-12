/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cMng.h
*	����ժҪ:
*			������Ϸ������
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CMNG_H_
#define _CMNG_H_

#define REDLED		100
#define GREENLED	200

#include <graphics.h>
//������Ϸ����
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
	int nCountDown;	//���̵Ƶ���ʱ
	int nFlag;
	int nPunish;	//�۷�
	TCHAR cCount[4]; //����ʱ
	TCHAR cTime[33];
	TCHAR cScore[5];
	TCHAR cLeave[2];
	COLORREF cColor;
	void DisplayTime();
	void DisplayScore();
};
#endif//_CMNG_H_
