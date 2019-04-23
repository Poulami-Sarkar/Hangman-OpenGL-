#include "../include/onScreen.h"

void onScreen::text(GLfloat x,GLfloat y,char * updateWord)
{
    int len,i;
    char menu[80];
    strcpy(menu,updateWord);
    len = strlen(updateWord);
    //glColor3f(1,0,0);
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0, 600, 0, 600 );
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    glScalef(0.2,0.2,11);
    //glColor3f(1.0, 1.0, 0.0);
    for ( i = 0; i <len; ++i )
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, menu[i]);
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

void onScreen::gameOverfun(char *hangmanword){
    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1.0,1.0,1.0,0.3);
    
    onScreen::text(150,290,"You lost the game. Press any key to exit");
    onScreen::text(200,260,"The word is:");
    onScreen::text(300,260,hangmanword);
}

void onScreen::drawButton(int x0,int y0,int x1, int y1,char disp[]){
    glPushMatrix();
        glColor4f(0.9, 0.9, 0.0,1.0);
        glRecti (x0, y0, x1, y1);
        glLineWidth(3.0);
        glColor4f(0.7, 0.7, 0.1,1.0);
        glBegin(GL_LINES);
            glVertex2i(x0,y0);
            glVertex2i(x1,y0);
        glEnd(); 
        glPushMatrix();

        glColor4f(0.0,0.0,0.8,1.0);
        onScreen::text(x0-70,y0-30,disp);
        glPopMatrix();
    glPopMatrix();
}