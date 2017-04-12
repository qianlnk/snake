/**************************************************************
*	�汾��Ϣ:	2013.3.16(lnk)
*	�ļ�����:	cCell.h
*	����ժҪ:
*			���������
*	��ʷ��¼:
*			����			ʱ��			����
*			lnk				2013.3.16		create
***************************************************************/

#ifndef _CCELL_H_
#define _CCELL_H_

#include <graphics.h>	//c++ͼ�ο⣬������ʹ��EasyX_2011���ݰ�

#define	EMPTY		0	//��λ
#define	BARRIER		-1	//�ϰ���
#define	FOOD		1	//ʳ��
#define CELLSIZEIN	7	//���Ӵ�С
#define CELLSIZE	10

//����������
class cCell  
{
public:
	cCell();										//���캯��
	void SetXY(int nPramX, int nPramY);				//���ø������Ͻ�����
    void SetType(int nPramType);					//���ø�������
	void SetColorDisplayCell(COLORREF cPramColor);	//���ø�����ɫ
	void DisplayLaser();							//��ʾ����״����
	int GetType();									//��ȡ��������
	//virtual ~cCell();								//��������

	friend class cGameArea;	//��Ԫ��cGameArea��ֱ�ӷ��ʱ���˽�г�Ա

private:
	int nX;											//�������Ͻ�X����
	int nY;											//�������Ͻ�Y����
	int nType;										//�������ͣ�0--�� -1--�ϰ� 1--ʳ��
	COLORREF cColor;								//������ɫ
};

#endif//_CCELL_H_
