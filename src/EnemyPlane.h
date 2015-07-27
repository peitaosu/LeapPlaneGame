#pragma once
#include "plane.h"

class EnemyPlane :
	public Plane
{
public:
	EnemyPlane(void);
	virtual ~EnemyPlane(void);

	void SetDelay(unsigned int delay);

	//������ʾ
	void UpdatePlane();
	void ShowPlane();

	//�ƶ�
	void SetX(int x);
	void SetY(int y);
	void PlaneMove();
	void PlanePause();
	void AddPos(int x, int y);

	//BOSS
	void SetBoss(bool isBoss);

	void SetImageInfo(HBITMAP *images, int n);

private:
	int m_iDesX;
	int m_iDesY;
	int m_iNowPos;
	double m_iAngle;

	bool m_bMoveable;
	
	vector<POINT> posMap;

	//�����ӳ�
	unsigned int m_Delay;
	unsigned int m_ShowTime;

	//BOSS�ж�
	bool m_bIsBoss;

	//ͼ��
	HBITMAP *m_PlaneImage;
	int m_iNowImageIndex;
	int m_iImageIndexMax;
};
