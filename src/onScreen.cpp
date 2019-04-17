#include "../include/global.h"
#include "../include/onScreen.h"
#include "../include/man.h"
#include "../include/words.h"

void onScreen::text(GLfloat x,GLfloat y,char * tempWord)
{
    int len,i;
    char menu[80];
    strcpy(menu,tempWord);
    len = strlen(tempWord);
    glColor3f(1,0,0);
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0, 600, 0, 600 );
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for ( i = 0; i <len; ++i )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
    glPopMatrix();
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}

void onScreen::drawPixel(int x, int y){
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    //sleep(1);
    glFlush();

}
