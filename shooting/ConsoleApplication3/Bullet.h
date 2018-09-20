#pragma once
#include "Object.h"
#include "user.h"
class Bullet :
	public Object
{
public:
	Bullet(Object *pu) :Object("@", pu->getpos()+3) {};
	~Bullet();
};

