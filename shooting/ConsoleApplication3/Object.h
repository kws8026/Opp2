#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

class Object
{
protected:
	char randering[3];
	int pos;
	int size;
	int state; // 0 사망 1 생존 2 피격
	int hp;
public:
	Object();
	Object(char r[] = nullptr, int p = 0, int state = 0) : pos(p) , size((int)strlen(r)), state(state), hp(10)
	{
		if (r == nullptr) return;
		for (int i = 0; i < 3; i++)
		{
			randering[i] = r[i];
		}
	}
	Object(Object* other) : pos(other->pos)
	{
		if (other->randering == nullptr) return;
		for (int i = 0; i < 3; i++)
		{
			randering[i] = other->randering[i];
		}
	};
	~Object();

	int getpos() { return pos; }
	int getsize() { return size; }
	int getstate() { return state; }
	void setstate(int num) { state = num; }
	void setpos(int num) { pos = num; }
	
	virtual int damaged(int i);
	virtual int rander(char stage[], char* other = nullptr);
	void movepos(int vecterX, int len);
};

