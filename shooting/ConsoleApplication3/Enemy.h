#pragma once
#include "Object.h"
class Enemy :
	public Object
{
	int countstun;
public:
	Enemy(char r[]=nullptr, int p=0) :Object(r, p) , countstun(0) {};
	~Enemy();
	int rander(char stage[], char* other);
};

