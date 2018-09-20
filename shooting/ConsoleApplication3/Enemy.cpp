#include "Enemy.h"



Enemy::~Enemy()
{
}

int Enemy::rander(char stage[], char* other)
{
	if (state == 1)
	{ 
		countstun++;
		if (countstun > 50) {
			countstun = 0;
			state = 0;
		}
		return Object::rander(stage,"@.@");
	}
	return Object::rander(stage);
}
