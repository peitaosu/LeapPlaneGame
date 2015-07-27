#pragma once
#include <Windows.h>
#include <vector>

using namespace std;

enum PLANE_STATUS
{
	P_ALIVE,
	P_DISAPPEAR,
	P_EXPLODE,
	P_INVINCIBLE,
	P_BOOM,
};

class Shooter;
class Item;

class Plane
{
public:
	Plane(void);
	Plane(RECT& ImpactBox);
	virtual ~Plane(void);

	//��Ա����ȡ��
	int GetHp();
	int GetAtk();
	int GetDef();
	int GetSpeed();
	void SetHp(int Hp);
	void SetAtk(int Atk);
	void SetDef(int Def);
	void SetSpeed(int Speed);

	int GetX();
	int GetY();
	int GetState();
	virtual void SetX(int x);
	virtual void SetY(int y);
	void SetPos(int x, int y);
	void SetState(int State);

	RECT& GetImpactBox();
	void SetImpactBox(int width, int height);

	void SetImage(HBITMAP image);
	void SetOffset(int x, int y);

	void AddShooter(vector<Shooter*> &shooters);
	void ClearShooter();

	//�����趨
	void SetFireCommand(bool command);

	//��Ʒ����
	void AddItem(int ItemType, int ItemNum);
	void ClearItem();

	//��ײ�ж�
	BOOL IsImpact(RECT& ImpactBox);
	void SetExplodeInfo(HBITMAP* images, int n);
	void PlaneExplode();

	//������ʾ
	virtual void UpdatePlane();
	virtual void ShowPlane();

protected:
	//����
	int m_iHp;
	int m_iHpMax;
	int m_iAtk;
	int m_iDef;
	int m_iSpeed;

	//״̬,λ��
	int m_iX;
	int m_iY;
	int m_iState;

	//��ײ��Ϣ
	RECT m_ImpactBox;
	int m_iWidth;
	int m_iHeight;

	//������
	int m_iNowShooterGroup;
	vector< vector<Shooter*> > m_vShooterGroup;

	//����ָ��
	bool m_bFireCommand;

	//ͼ��
	HBITMAP m_hImage;

	//��ը
	HBITMAP *m_ExplodeImage;
	int m_iNowExplodeIndex;
	int m_iExplodeIndexMax;
	bool m_bExplodeOver;

	//�����ͼ���ƫ����
	int m_iOffsetX;
	int m_iOffsetY;

	//��ʱ��
	unsigned int m_Time;
	unsigned int m_InvincibleTime;

	//��Ʒ����
	vector<Item*> items;

	//��ɱ
};
