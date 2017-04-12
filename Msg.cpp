/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	Msg.cpp
*	����ժҪ:
*			��Ϸ��Ϣ�����ʵ��
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/
#include "Msg.h"
#include <conio.h>

cGame		game;			//���ڳ�ʼ����Ϸ��������Ϸ��ز���
cGameArea	a;				//���ڳ�ʼ����Ϸ�������ã��ı���Ϸ������ز���
cMng		manager;		//���ڳ�ʼ�������������ù�������ز���
cSnake		snake;			//���ڳ�ʼ���ߣ����ݻ��ߣ�������


/**************************************************************
*	��������: MessageDispose
*	��������:
*		��Ϸ��Ϣ����
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
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
		Keepdown = false;  //�Ƿ������W A S D �е�һ������
		if(kbhit())
		{
			switch(c = getch())  //��������Ϣ��W A S D��
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
					manager.bPause = !manager.bPause;	//������ͣ��ʼ
					manager.DisplayStatus();	//��ʾ��ͣ��ʼ
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
		if(true == manager.bPause)	//�����ͣ��ֱ�ӽ����´�ѭ��
		{
			//������̵Ƽ�������ʱ
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
		switch(a.cGmArea[snake.pstHead->nX/10][snake.pstHead->nY/10].GetType())	//�����ͷ���������
		{
		case FOOD:				//����ʳ�����ӳ�
			{
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				snake.AddSnakeCell();	//������
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				a.DeleteFood();	//ɾ��ʳ��
				if(a.CreateFood() == false)	//������ʳ��,������Ƿ�ͨ��
				{
					game.GameWin();			//��Ϸͨ�أ�����ͼû�ط�����ʳ��ʱ��
				}
				manager.ScoreAcount(1);		//��һ��
				break;
			}
		case EMPTY:
			{
				a.cGmArea[snake.pstLast->nX/10][snake.pstLast->nY/10].SetType(EMPTY);				//������β���������ϰ�
				a.ChangeColor(snake.pstLast->nX/10, snake.pstLast->nY/10, BLACK);
				snake.SnakeMove();  //���ƶ�һ��
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, BLUE);
				a.cGmArea[snake.pstHead->pstNext->nX/10][snake.pstHead->pstNext->nY/10].SetType(BARRIER);	//��������Ϊ�ϰ���
				break;
			}
		case BARRIER:				//�����ϰ���
			{
				game.GameFail();
				a.ChangeColor(snake.pstHead->nX/10, snake.pstHead->nY/10, RGB(255, 127, 39));
				FlushBatchDraw();
				{
					char c = ' '; 
					while(c != 'r' && c != 'R')  //����Ϸʧ��ʱ����R�������½�����Ϸ
					{
						if(kbhit())
						{
							c = getch();
						}
						Sleep(10);
					}
				}
				ReInit(); //���¿�ʼ��Ϸ
				break;
			}
		}
		EndBatchDraw();
		if(Keepdown==false)
		{
			Sleep(100);
			manager.TimeGo(0.1);	//����ʱ��
			dSS = dSS  + 0.1;
			if(dSS >= 1.0)
			{
				dSS = 0;
				manager.CountDown();
			}
		}
		else						//���������°������ʱ
		{
			Sleep(40);				//�ʵ����߿���������Ϸ������
			manager.TimeGo(0.04);  //����ʱ��
		}
	}
}

/**************************************************************
*	��������: MessageDispose
*	��������:
*		�ۺ���Ϸ��ʼ��
*	�����б�:
*		��
*	�� �� ֵ:
*		��
*	��ʷ��¼:
*		2013.3.16	created by lnk
****************************************************************/
void ReInit()
{
	game.GameInit();		//��ʼ����Ϸ����������
	a.InitArea(); //��ʼ����Ϸ��
	snake.SnakeInit();  //��ʼ����
	manager.InitMng();  //��ʼ��������
	//�����ߵĿ�ʼ״̬
	snake.pstNow = snake.pstHead;
	a.ChangeColor(snake.pstNow->nX/10, snake.pstNow->nY/10, BLUE);
	snake.pstNow = snake.pstLast;
	a.ChangeColor(snake.pstNow->nX/10, snake.pstNow->nY/10, BLUE);
}