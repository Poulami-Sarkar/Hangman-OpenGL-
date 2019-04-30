#ifndef ONSCREEN_H
#define ONSCREEN_H

#include "../include/global.h"
#include "../include/man.h"
#include "../include/words.h"


class onScreen{
	public:
		float exit[4] = {300, 225, 500, 265}, instr[4]={300, 265, 500, 305},play[4]={300, 305, 500, 345};
		float by0,by1,ax0,ax1;
		//int x1, x2, y1, y2;
		int h, w;
		float aspect;
		void text(float x, float y, char *string);
		//static void init();
		void drawPixel (int x, int y);
		onScreen();
		void drawButton(float [],char disp[]);
		void gameOverfun(char *hangmanword);
		void startPage(int playGame);
		void playGamefun(int*,int* ,man);
		//static void display();

};

#endif
