#pragma once
#include "user.h"
#include "Enemy.h"
#include "Bullet.h"

class Manager
{
	char* pstage;
	int countBullet;
	int len;
	int killscore;
	int countSpawntime;
	int countReloadtime;
	int countEMovetime;
	int magazine;

	Object *pob[100];
public:
	Manager(char stage[], int size);
	~Manager();
	int spawnenemy();
	int initializing();
	bool isPointinObject(int point,Object* object);
	bool isObjectinObject(Object* target, Object* base);
	int searchNearEnemy();
	int hitkb();
	int update();
	int rander();
	void cooldowncount();
	bool shootBullet();

	int getkillscore() { return killscore; }
};

