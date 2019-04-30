#ifndef MAN_H
#define MAN_H

#include "../include/global.h"
#include "../include/words.h"

class man {

	public:
		words w;
		int a = 10;
		//man();
		void drawHead();
		void drawTorso();
		void drawLArm();
		void drawRArm();
		void drawLLeg();
		void drawRLeg();
		void drawbase(int wrongTry);
		void draw_line(GLfloat x0,GLfloat y0, GLfloat x1,GLfloat y1);
};

#endif


