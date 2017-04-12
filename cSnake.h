/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cSnake.h
*	����ժҪ:
*			��������
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CSNAKE_H_
#define _CSNAKE_H_

#include <graphics.h>


#define UP		10
#define DOWN	20
#define LEFT	30
#define RIGHT	40

//��������
class cSnake{
public:
	int nDirection;						//�߶��ķ���(����������)
	cSnake();							//���캯��
	void SnakeInit();					//��ʼ���ߵĽṹ
	void AddSnakeCell();				//���һ������
	void DelSnakeCell();				//ɾ��һ������
	void SnakeMove();					//���ƶ�һ��

	friend void MessageDispose();
	friend void ReInit(); 
private:
	typedef struct tagSNAKE_T
	{
		int nX;							//һ���������Ͻǵ�X����
		int nY;							//һ���������Ͻǵ�Y����
		struct tagSNAKE_T *pstNext;		//ǰһ���ڵ�
		struct tagSNAKE_T *pstPrior;	//��һ���ڵ�
	}SNAKE_T;

	SNAKE_T *pstHead;					//ͷ�ڵ�
	SNAKE_T *pstLast;					//β�ڵ�
	SNAKE_T *pstNow;					//��ǰ�ڵ�
};

#endif//_CSNAKE_H_