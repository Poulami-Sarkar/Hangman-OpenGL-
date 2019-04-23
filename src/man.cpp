#include "../include/man.h"
#include "../include/global.h"
#include "../include/words.h"



void man::draw_line(GLfloat x0,GLfloat y0, GLfloat x1,GLfloat y1){
    glColor3f(1,0,1);
    glBegin(GL_LINES);
    glVertex2d(x0,y0);
    glVertex2d(x1,y1);
    glEnd(); 

}

void man::drawHead(){
	glClearColor(0.0,0.0,0.0,1.0);
	glPushMatrix();
    glLoadIdentity();
	glTranslatef(30,70,00);
	glRotatef(30, 0, 0, 0.7);
	//glColor3f(1.0,0.0,0.0);
	glutWireSphere(20,100,100);
	glPopMatrix();
}

void man::drawTorso(){
	draw_line(30,20,30,50);
	//draw_cylinder(0.3,1.0,255,160,100);
}

void man::drawRArm(){
	draw_line(30,50,50,35);
}	


void man::drawLArm(){
	draw_line(30,50,10,35);
}	


void man::drawLLeg(){
	draw_line(30,20,10,5);
}

void man::drawRLeg(){
	draw_line(30,20,50,5);
}	