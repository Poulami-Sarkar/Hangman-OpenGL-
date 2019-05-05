#include "../include/man.h"

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
	glTranslatef(80,80,00);
	glTranslated(300.0,282.0,0);
	glRotatef(30, 0, 0, 0.7);
	glutWireSphere(30,100,100);
	glPopMatrix();
}

void man::drawTorso(){
	draw_line(30,20,30,50);
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

void man::drawgallow(int e){
	if (e == 0)
		draw_line(-15,5,50,5);// the bottom part
	else{
		draw_line(-15,5,2,5);
		draw_line(2,5,10,-50);
		
	
	}
	
	draw_line(-5,5,-5,100);
	draw_line(-5,100,30,100);
	draw_line(30,100,30,90);	
}