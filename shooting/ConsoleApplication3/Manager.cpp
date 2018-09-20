#include "Manager.h"

Manager::Manager(char stage[],int size) :pstage(stage), countobject(0), len(size) , enemycount(0), killscore(0), playtime(0.0f)
{
	for (int i = 0; i < 100; i++)
		pob[i] = nullptr;
	srand((unsigned int)time(NULL));
}

Manager::~Manager()
{
	for (int i = 0; i < 100; i++){
		if (pob[i] == nullptr)
			continue;
		delete pob[i];
	}
}

int Manager::spawnenemy()
{
	for (int i = 0; i < 5; i++)
	{
		if (pob[i]->getstate()){
			pob[i]->setstate(1);
			pob[i]->setpos(10 + (rand() % 110));
			break;
		}
		return -1;
	}
	return 0;
}

int Manager::initializing()
{
	pob[countobject++] = new User("^.^", 0);
	for(int i = 1; i < 6; i++){
		pob[countobject++] = new Enemy("*.*");
	}
	return 0;
}

bool Manager::isPointinObject(int point, Object * object)
{
	int temppos = object->getpos();
	if(temppos > point || temppos + object->getsize() < point)
		return false;
	return true;
}

bool Manager::isObjectinObject(Object * target, Object * base)
{
	if (target->getpos() > base->getpos() + base->getsize() || target->getpos() + target->getsize() < base->getpos())
		return false;
	return true;
}

int Manager::hitkb()
{
	if (_kbhit())
		switch (_getch())
		{
		case 'a':
		case 'A':
			pob[0]->movepos(-1, len); break;
		case 'd':
		case 'D':
			pob[0]->movepos(1, len); break;
		case 'f':
		case 'F':
			if (countobject > 99)
				countobject = 6;
			pob[countobject++] = new Bullet(pob[0]);
			break;
		default:
			break;
		}
	return 0;
}

int Manager::update()
{
	for (int i = 0; i < 100; i++){
		if (pob[i] == nullptr)
			continue;
		if (pob[i]->getsize() == 1){
			pob[i]->movepos(1,len);
			if (isPointinObject(pob[i]->getpos(), pob[1])){
				delete pob[i];
				pob[i] = nullptr;
			}
			else if(pob[i]->getpos() == len-1){
				delete pob[i];
				pob[i] = nullptr;
			}
		}
	}

	if (pob[0]->getstate())
		return -1;
	return 0;
}

int Manager::rander()
{
	for (int i = 0; i < 100; i++)
	{
		if (pob[i] == nullptr || !(pob[i]->getstate()))
			continue;
		if (pob[i]->rander(pstage)){
			delete pob[i];
			pob[i] = nullptr;
		}
	}
	return 0;
}
