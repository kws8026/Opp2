#pragma once
#include "Object.h"

class User : public Object
{
	int countdamage;
public:
	User(char r[], int p) :Object(r, p, 1), countdamage(0) {};
	~User();
	int rander(char stage[], char* other);
};

