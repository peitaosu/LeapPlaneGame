#pragma once
#include <Windows.h>

class Bullet;

class Shooter
{
public:
	Shooter(void);
	virtual ~Shooter(void);

	//��Ա���ú�ȡ��
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	void SetPos(int x, int y);

	double GetDirection();
	double GetFireDirection();
	int GetSpeed();
	int GetFireSpeed();
	bool GetCommand();
	void SetDirection(double direcion);
	void SetFireDirection(double direction);
	void SetSpeed(int speed);
	void SetFireSpeed(int speed);
	void SetCommand(bool command);
	void SetDelay(UINT delay);
	void SetReloadMax(int max);

	int GetState();
	void SetState(int state);

	void SetBulletTemplate(Bullet &BulletTemplate);

	RECT& GetImpactBox();
	void SetImpactBox(int width, int height);

	void SetImage(LPCTSTR ImageName);

	//�ƶ�
	virtual void ShooterMove();

	//װ��
	void Reload();
	Bullet* ReloadBullet();

	//����
	virtual bool Fire(bool camp);

	//��ʾ
	void ShowShooter();

private:
	//λ��
	int m_iX;
	int m_iY;

	//����
	double m_iDirection;
	double m_iFireDirection;

	//״̬
	int m_iState;

	//�ӵ�ģ��
	Bullet *m_BulletTemplate;

	//�ٶ�
	UINT m_iDelay;
	UINT m_iShowTime;
	UINT m_Time;

	int m_iReloadMax;
	int m_iRemainBullets;

	int m_iSpeed;
	int m_iFireSpeed;
	bool m_bCommand;

	//ͼ��
	HBITMAP m_hImage;

	//��ײ��
	RECT m_ImpactBox;
};
