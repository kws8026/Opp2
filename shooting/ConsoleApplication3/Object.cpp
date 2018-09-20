#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

int Object::damaged(int i)
{
	return 0;
}

int Object::rander(char stage[], char* other)
{
	if (randering == nullptr)
		return -1;
	for (int i = pos; i < pos + size; i++)
	{
		if (other == nullptr)
			stage[i] = randering[i - pos];
		else
			stage[i] = other[i - pos];
	}
	return 0;
}

void Object::movepos(int vecterX,int len)
{
	pos += vecterX;
	if (pos > len - size)
		pos = len - size;
	else if (pos < 0)
		pos = 0;
}
