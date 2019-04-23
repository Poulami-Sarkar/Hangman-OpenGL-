#ifndef MAN_H
#define MAN_H


#include "../include/global.h"

class man{

	public:
		
		static void drawHead();
		static void drawTorso();
		static void drawLArm();
		static void drawRArm();
		static void drawLLeg();
		static void drawRLeg();
		static void draw_line(GLfloat x0,GLfloat y0, GLfloat x1,GLfloat y1);
};

#endif


