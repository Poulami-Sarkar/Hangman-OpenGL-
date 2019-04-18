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
	glTranslatef(30,70,00);
	glRotatef(30, 0, 0, 0.7);
	//glColor3f(1.0,0.0,0.0);
	glutWireSphere(20,200,100);
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

/*
void draw_cylinder(GLfloat radius,
                   GLfloat height,
                   GLubyte R,
                   GLubyte G,
                   GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
	
//    /** Draw the tube 
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

}

*/
