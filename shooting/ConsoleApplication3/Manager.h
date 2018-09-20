#pragma once
#include "user.h"
#include "Enemy.h"
#include "Bullet.h"

class Manager
{
	char* pstage;
	int countobject;
	int len;
	int enemycount;
	int killscore;
	float playtime;

	Object *pob[100];
public:
	Manager(char stage[], int size);
	~Manager();
	int spawnenemy();
	int initializing();
	bool isPointinObject(int point,Object* object);
	bool isObjectinObject(Object* target, Object* base);
	int hitkb();
	int update();
	int rander();
};

