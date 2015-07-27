#pragma once
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

enum ScriptMode
{
	INIT,
	STAGE_1,
	STAGE_2,
	END
};

enum GameState
{
	S_MENU,
	S_GAME,
	S_RANK,
	S_MUSIC,
	S_END,
};

struct RECORD
{
	string name;
	int record;
};

class Plane;
class Shooter;
class Bullet;
class Item;
class HeroPlane;

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	//��������ʾ��

	//�˵�
	void PreFocus();
	void NextFocus();
	void ShowMenu();

	//��������
	void ShowMusicRoom();

	//���а�
	void ShowRank();

	//����Ϸ�а�������
	void KeyProcess(WPARAM wParam);

	//��Ϸ��...
	void UpdateGame();
	void ShowGame();

	void ShowBackground();
	void ShowUI();

	//������������
	template<class T>
	void SetVectorEmpty(vector<T> &pool);

	vector<Bullet*>* GetMyBulletVector();
	vector<Bullet*>* GetEmemyBulletVector();
	vector<Plane*>* GetPlaneVector();
	vector<Shooter*>* GetShooterVector();
	vector<Item*>* GetItemVector();

	void AddBulletToVector(Bullet* bullet, bool type);
	int AddPlaneToVector(Plane* plane);
	void AddShooterToVector(Shooter* shooter);
	void AddItemToVector(Item* item);

	void ClearAll();

	//��Ϸ�������
	void SetScriptMode(int mode);
	void GameScript();
	void SetBossAction(bool boss);

	void AddScore(int num);

	int GetGameStatus();
	void SetGameStatus(int status);
	void GotoMenu();

	//���طɻ�ȡ��
	HeroPlane* GetHeroPlane();

	//���а�
	void AddNewRecord(char* name);
	void WriteNewRecord();
	void ReadRecord();
	void WriteInt(int val, ofstream& os);
	void ReadInt(int& val, string& data);
	void WriteString(string& val, ofstream& os);
	void ReadString(string& val, string& data);

	//ͼƬ����
	void LoadGameImage();
	void SetBGImage(HBITMAP* bgImage, int n);

	void PaintNumber(int num, int x, int y, int col);
	HBITMAP GetItemImage(int itemType);

private:
	//��ϷԪ����
	vector<Plane*> planes;
	vector<Bullet*> myBullets;
	vector<Bullet*> ememyBullets;
	vector<Shooter*> shooters;
	vector<Item*> items;

	//����Ԫ��
	HeroPlane* heroPlane;

	//�ű�
	unsigned int m_Time;
	int m_ScriptMode;
	int m_Process;
	bool m_bProcessOver;

	//SCORE
	int m_iScore;

	//��״̬
	int m_iStatus;

	//ѡ���
	int m_iFocus;
	int m_iSelectionMax;
	string m_MenuStrings[4];
	string m_MusicStrings[21];

	//���а�
	struct RECORD m_Record[20];

	//��������
	HBITMAP *m_BGImage;

	HBITMAP m_BG_sakura[1];
	HBITMAP m_BG_ame[12];
	HBITMAP m_BG_yuki[31];
	int m_iNowBGIndex;
	int m_iGBIndexMax;

	HBITMAP m_HeroImage;

	HBITMAP m_Bullet_1[8];
	HBITMAP m_Bullet_2[9];
	HBITMAP m_Bullet_3[7];

	HBITMAP m_Crash[8];

	HBITMAP m_Number;

	HBITMAP m_Boom_1[5];

	HBITMAP m_InvincibleEffect[30];
	HBITMAP m_LevelUpEffect[4];

	HBITMAP m_ItemImage[6];

	HBITMAP m_GuardImage[5][10];
	HBITMAP m_Remilia[8];
	HBITMAP m_Iku[9];
	HBITMAP m_Komachi[8];
	HBITMAP m_Marisa[10];
	HBITMAP m_Yuyuko[10];
};
