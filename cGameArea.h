/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cGameArea.h
*	����ժҪ:
*			������Ϸ������
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CGAMEAREA_H_
#define _CGAMEAREA_H_

#include <graphics.h>
#include "cCell.h"

#define	CELLNUM			60		//��Ϸ�����С
#define AREASIZE		CELLNUM * 10
//������Ϸ������
class cGameArea
{
public:
	cCell cGmArea[CELLNUM][CELLNUM];				//������Ϸ����60 * 60
	void InitArea();									//��ʼ����Ϸ����
	void ChangeColor(int X, int Y, COLORREF cNewColor);	//�ı�ָ�����ӵ���ɫ
	bool CreateFood();									//����ʳ��
	void DeleteFood();									//ɾ��ʳ��


private:
	int nFoodX;					//ʳ������X
	int nFoodY;					//ʳ������Y
};
#endif//_CGAMEAREA_H_