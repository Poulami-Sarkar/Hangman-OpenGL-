#ifndef ONSCREEN_H
#define ONSCREEN_H

#include "../include/global.h"
#include "../include/man.h"
#include "../include/words.h"


class onScreen{

	public:
		//int x1, x2, y1, y2;

		static void text(float x, float y, char *string);
		//static void init();
		void drawPixel (int x, int y);
		//static void display();

};

#endif
