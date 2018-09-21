#include "user.h"



User::~User()
{
}

int User::rander(char stage[], char * other)
{
	if (state == 2)
	{
		countdamage++;
		if (countdamage > 50) {
			countdamage = 0;
			state = 1;
		}
		if (countdamage%2)
		{
			return Object::rander(stage, "---");
		}
	}
	return Object::rander(stage);
}
