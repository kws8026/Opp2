#pragma once
#include "Object.h"
#include "user.h"
class Bullet :
	public Object
{
	int vextorx;
public:
	Bullet(Object *pu, Object *pe) :Object("=", pu->getpos(), 1) {
		if (pu->getpos() < pe->getpos()){
			pos += pu->getsize() - 1; vextorx = 1;
		}
		else
			vextorx = -1;
	};
	~Bullet();

	void movepos( int len, int vecterX = 0);
};

