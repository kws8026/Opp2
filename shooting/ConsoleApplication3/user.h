#pragma once
#include "Object.h"

class User : public Object
{
	int magazine;
	int reloadCD;
public:
	User(char r[], int p) :Object(r, p, 1), magazine(10), reloadCD(0){};
	~User();

	void reload();
};

