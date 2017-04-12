/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	cGame.h
*	内容摘要:
*			定义游戏类
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CGAME_H_
#define _CGAME_H_

#include <graphics.h>
//定义游戏类
class cGame{
public:
	void GameInit();
	void GameWin();
	void GameFail();
};

#endif//_CGAME_H_
