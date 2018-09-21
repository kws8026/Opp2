#include "Manager.h"

int main()
{
	const int len = 120;
	int timer = 0;
	char stage[len + 1];
	Manager gm(stage,120);
	gm.initializing();

	while (true)
	{
		clock_t temp;
		clock_t tick = clock();
		memset(&stage, ' ', len);

		if (gm.hitkb() || gm.update() || gm.rander())
			break;

		stage[len-1] = '\r';
		stage[len] = '\0';
		printf("%s" ,stage);
		temp = clock() - tick;
		while(temp < 20)
   			temp = clock() - tick;
		timer += temp;
	}
	printf("playtime  : %dsec\nkillscore : %d\n", timer /1000,gm.getkillscore());

	return 0;
}