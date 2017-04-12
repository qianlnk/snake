/**************************************************************
*	版本信息:	2013.3.16(lnk)
*	文件名称:	Msg.cpp
*	内容摘要:
*			游戏消息管理的实现
*	历史记录:
*			人物			时间			操作
*			lnk				2013.3.16		create
***************************************************************/
#include "Msg.h"
#include <conio.h>

cGame		game;			//用于初始化游戏、设置游戏相关参数
cGameArea	a;				//用于初始化游戏区域，设置，改变游戏区域相关参数
cMng		manager;		//用于初始化管理区域，设置管理区相关参数
cSnake		snake;			//用于初始化蛇，数据化蛇，操作蛇


/**************************************************************
*	函数名称: MessageDispose
*	函数功能:
*		游戏消息管理
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void MessageDispose()
{
	char c;
	double dSS = 0.0;
	snake.pstNow = NULL;
	bool Keepdown = false;

	while(true)
	{
		Keepdown = false;  //是否持续按W A S D 中的一个按键
		if(kbhit())
		{
			switch(c = getch())  //处理按键消息（W A S D）
			{
			case 'w':
			case 'W':
				{
					if(snake.nDirection == UP)
					{
						Keepdown = true;
					}
					else if(snake.nDirection != DOWN && snake.nDirection != UP)
					{
						snake.nDirection = UP;
					}
					break;
				}
			case 's':
			case 'S':
				{
					if(snake.nDirection == DOWN)
					{
						Keepdown = true;
					}
					else if(snake.nDirection != UP && snake.nDirection != DOWN)
					{
						snake.nDirection = DOWN;
					}
					break;
				}
			case 'a':
			case 'A':
				{
					if(snake.nDirection == LEFT)
					{
						Keepdown = true;
					}
					else if(snake.nDirection != RIGHT && snake.nDirection != LEFT)
					{
						snake.nDirection = LEFT;
					}
					break;
				}
			case 'd':
			case 'D':
				{
					if(snake.nDirection == RIGHT)
					{
						Keepdown = true;
					}
					else if(snake.nDirection != LEFT && snake.nDirection != RIGHT)
					{
						snake.nDirection = RIGHT;
					}
					break;
				}
			case 'p':
			case 'P':
				{
					manager.bPause = !manager.bPause;	//设置暂停或开始
					manager.DisplayStatus();	//显示暂停或开始
					break;
				}
			case 'r':
			case 'R':
				{
					ReInit();
					break;
				}
			}
		}
		if(true == manager.bPause)	//如果暂停，直接进行下次循环
		{
			//保存红绿灯继续倒计时
			Sleep(100);
			dSS = dSS  + 0.1;
			if(dSS >= 1.0)
			{
				dSS = 0;
				manager.CountDown();
			}
			continue;
		}
		BeginBatchDraw();
		switch(a.cGmArea[snake.pstHead->nX/10][snake.pstHead->nY/10].GetType())	//检测蛇头遇到的情况
		{
		case FOOD:				//遇到食物，蛇身加长
			{
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				snake.AddSnakeCell();	//蛇增长
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				a.DeleteFood();	//删除食物
				if(a.CreateFood() == false)	//创建新食物,并检查是否通关
				{
					game.GameWin();			//游戏通关（当地图没地方创建食物时）
				}
				manager.ScoreAcount(1);		//加一分
				break;
			}
		case EMPTY:
			{
				a.cGmArea[snake.pstLast->nX/10][snake.pstLast->nY/10].SetType(EMPTY);				//设置蛇尾经过处无障碍
				a.ChangeColor(snake.pstLast->nX/10, snake.pstLast->nY/10, BLACK);
				snake.SnakeMove();  //蛇移动一次
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				a.cGmArea[snake.pstHead->pstNext->nX/10][snake.pstHead->pstNext->nY/10].SetType(BARRIER);	//设置蛇身为障碍物
				break;
			}
		case BARRIER:				//遇到障碍物
			{
				game.GameFail();
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, RGB(255, 127, 39));
				FlushBatchDraw();
				{
					char c = ' '; 
					while(c != 'r' && c != 'R')  //当游戏失败时，按R键可重新进行游戏
					{
						if(kbhit())
						{
							c = getch();
						}
						Sleep(10);
					}
				}
				ReInit(); //重新开始游戏
				break;
			}
		}
		EndBatchDraw();
		if(Keepdown==false)
		{
			Sleep(100);
			manager.TimeGo(0.1);	//增加时间
			dSS = dSS  + 0.1;
			if(dSS >= 1.0)
			{
				dSS = 0;
				manager.CountDown();
			}
		}
		else						//当持续按下按方向键时
		{
			Sleep(40);				//适当休眠可以增加游戏流畅性
			manager.TimeGo(0.04);  //增加时间
		}
	}
}

/**************************************************************
*	函数名称: MessageDispose
*	函数功能:
*		综合游戏初始化
*	参数列表:
*		无
*	返 回 值:
*		无
*	历史记录:
*		2013.3.16	created by lnk
****************************************************************/
void ReInit()
{
	game.GameInit();		//初始化游戏参数、设置
	a.InitArea(); //初始化游戏区
	snake.SnakeInit();  //初始化蛇
	manager.InitMng();  //初始化管理区
	//绘制蛇的开始状态
	snake.pstNow = snake.pstHead;
	a.ChangeColor(snake.pstNow->nX/10, snake.pstNow->nY/10, BLUE);
	snake.pstNow = snake.pstLast;
	a.ChangeColor(snake.pstNow->nX/10, snake.pstNow->nY/10, BLUE);
}