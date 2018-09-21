#include "Manager.h"

Manager::Manager(char stage[],int size) 
	:pstage(stage), countBullet(6), len(size) , killscore(0),  magazine(0), 
	countSpawntime(200), countReloadtime(100), countEMovetime(25)
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
	if (countSpawntime < 200)
		return -1;
	for (int i = 1; i < 6; i++)
	{
		if (!(pob[i]->getstate())){
			pob[i]->setstate(1);
			pob[i]->sethp(10);
			pob[i]->setpos(10 + (rand() % 105));
			countSpawntime = 0;
			return 0;
		}
	}
	return -1;
}

int Manager::initializing()
{
	pob[0] = new User("^.^", 0);
	for(int i = 1; i < 6; i++){
		pob[i] = new Enemy("*.*");
	}
	return 0;
}

bool Manager::isPointinObject(int point, Object * object)
{
	int temppos = object->getpos();
	if(temppos > point || temppos + object->getsize()-1 < point)
		return false;
	return true;
}

bool Manager::isObjectinObject(Object * target, Object * base)
{
	if (target->getpos() > base->getpos() + base->getsize()-1 || target->getpos() + target->getsize()-1 < base->getpos())
		return false;
	return true;
}

int Manager::searchNearEnemy()
{
	// 추후구현
	return -1;
}

int Manager::hitkb()
{
	if (_kbhit())
		switch (_getch())
		{
		case 'a':
		case 'A':
			pob[0]->movepos(len, -1); break;
		case 'd':
		case 'D':
			pob[0]->movepos(len, 1); break;
		case 'f':
		case 'F':
			shootBullet();
			break;
		default:
			break;
		}
	return 0;
}

int Manager::update()
{
	// 충돌체크
	for (int i = 1; i < 100; i++){ 
		if (pob[i] == nullptr)
			continue;
		if (pob[i]->getsize() == 1){
			pob[i]->movepos(len);
			for(int j = 1; j < 6; j++)
			{ 
				if (isPointinObject(pob[i]->getpos(), pob[j])){
					if (!(pob[j]->getstate()))
						continue;
					delete pob[i];
					pob[j]->damaged(1);
					pob[i] = nullptr;
					if (pob[j]->gethp() < 1){
						pob[j]->setstate(0);
						killscore++;
					}
					break;
				}
				else if (pob[i]->getpos() == len - 1 || pob[i]->getpos() == 0) {
					delete pob[i];
					pob[i] = nullptr;
					break;
				}

			}
		}
		else
		{
			if (!(pob[i]->getstate()))
				continue;
			if(countEMovetime > 24 || countEMovetime == 0)
			{ 
				if (pob[0]->getpos() > pob[i]->getpos())
					pob[i]->movepos(len,1);
				else
					pob[i]->movepos(len,-1);
				countEMovetime = 0;
			}
			if (isObjectinObject(pob[i], pob[0]) && pob[0]->getstate() == 1)
			{
				pob[0]->damaged(2);
				if (pob[0]->gethp() < 1)
					pob[0]->setstate(0);
			}
		}
	} 
	// 스폰 및 쿨다운 조절
	cooldowncount();
	// 엔딩 체크
	if (!(pob[0]->getstate()))
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

void Manager::cooldowncount()
{
	if(spawnenemy())
		countSpawntime++;
	if(magazine < 1)
		countReloadtime++;
	countEMovetime++;
}

bool Manager::shootBullet()
{
	if (countBullet > 99)
		countBullet = 6;
	if (countReloadtime > 100)
		magazine = 10;
	if (magazine < 1)
		return false;
	for (int i = 1; i < 6; i++)
	{
		if (!(pob[i]->getstate()))
			continue;
		pob[countBullet++] = new Bullet(pob[0], pob[i]);
		magazine--;
		countReloadtime = 0;
		return true;
	}
	return false;
}
