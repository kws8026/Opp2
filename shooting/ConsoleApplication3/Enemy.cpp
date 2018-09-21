#include "Enemy.h"



Enemy::~Enemy()
{
}

int Enemy::rander(char stage[], char* other)
{
	if (state == 2)
	{ 
		countstun++;
		if (countstun > 50) {
			countstun = 0;
			state = 1;
		}
		return Object::rander(stage,"@.@");
	}
	return Object::rander(stage);
}
