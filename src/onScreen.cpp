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
    //glRasterPos2i(x, y);
    glTranslatef(x,y,0);
    glScalef(0.15*(float)w/1280,0.20*(float)h/960,40);
    //glColor3f(1.0, 1.0, 0.0);
    for ( i = 0; i <len; ++i )
        glutStrokeCharacter(GLUT_STROKE_ROMAN, menu[i]);
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

void onScreen::gameOverfun(char *hangmanword,man hm){
    int i = 0,stop;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(350.0,260.0,0);
    glScaled(1.5,1.5,0);
    hm.drawgallow(1);
    hm.drawHead();
    hm.drawLLeg();
    hm.drawRLeg();
    hm.drawTorso();
    hm.drawRArm();
    hm.drawLArm();
        
    glPopMatrix();
    onScreen::text(100,450,"You lost the game. Press any key to exit");
    onScreen::text(120,390,"The word is:");

    onScreen::text(300,390,hangmanword);
}

void onScreen::drawButton(float dim[],char disp[]){
    glPushMatrix();
        glColor4f(0.0, 0.0, 0.0,1.0);
        float x0 = dim[0], y0 = dim[1],x1= dim[2],y1= dim[3];
        float aspect = h/w;
        glRecti (x0,y0, x1, y1);
        glLineWidth(3.0);
        glColor4f(0.2, 0.2, 0.2,1.0);
        glBegin(GL_LINES);
            glVertex2i(x0,y0);
            glVertex2i(x1,y0);
        glEnd(); 
        glPushMatrix();

        glColor4f(0.7,0.7,0.7,1.0);
        onScreen::text(380-70*(float)w/800,y0-35*(float)h/800,disp);
        glPopMatrix();
    glPopMatrix();
}


void onScreen::startPage(int playGame){
    float aspect = h/w;
    if(playGame == 0){
        glMatrixMode (GL_MODELVIEW);
        glPushMatrix();
            glColor4f(0.3, 0.3, 0.3,1.0);
            glRecti (400, 350, 1000, 450);
        glPopMatrix();
        glColor4f(0.3, 0.4, 0.2,1.0);
        glBegin(GL_LINES);
            glVertex2i(550,345);
            glVertex2i(800,345);
            glVertex2i(800,225);
            glVertex2i(800,345);
            glVertex2i(550,225);
            glVertex2i(550,345);
        glEnd();
       
        onScreen::drawButton(exit,"Exit");
        onScreen::drawButton(instr,"Instructions");
        onScreen::drawButton(play,"Play");
        onScreen::text(220,350,"Let's Play");
        onScreen::text(200,310,"The Game Of Words");
    }
    
}


void onScreen::playGamefun(int *playGame,int *gameOver,int *score,man hm){
    // The box containing the updateWord
    char scr[20] = {0};
    std::sprintf(scr, "%d", *score);
    glPushMatrix();
        glColor3f(0.3,0.2,0.1);
        glTranslated(200,0,0);
        glScaled(1.6,1.0,0.0);
        glRecti(150,550,600,650);
        glRecti(10,450,700,600);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.15,0.44,0.43);
        glTranslated(-600,-200,0);
        glRecti(1200,600,1350,700);
    glPopMatrix();
    
    if(strcmp(hm.w.hangmanWord,hm.w.updateWord) == 0){
        glColor3f(1.0,1.0,1.0);
        onScreen::text(220,300,"You guessed it right!");
        hm.w.wrongTry = 999;
        hm.w.correct = 1;
        glutPostRedisplay();
        onScreen::text(220,275,"Right Click to go to next level");
        onScreen::text(220,250,"Press 'ESC' to go to Main Page");
    }
    glPushMatrix();
    glTranslated(350.0,260.0,0);
    glScaled(1.5,1.5,0);
    hm.drawgallow(0);
    switch(hm.w.wrongTry){
        case 5:
            glPushMatrix();
            //glTranslated(-100.0,10.0,0);
            hm.drawHead();
            glPopMatrix();
            break;
        case 4:
            hm.drawHead();
            hm.drawTorso();
            break;
        case 3:
            hm.drawHead();
            hm.drawRArm();
            hm.drawTorso();
            break;
        case 2:
            hm.drawHead();
            hm.drawRArm();
            hm.drawLArm();	
            hm.drawTorso();
            break;
        case 1:
            hm.drawHead();
            hm.drawRLeg();
            hm.drawTorso();
            hm.drawRArm();
            hm.drawLArm();
            break;
        case 0:
            hm.drawHead();
            hm.drawLLeg();
            hm.drawRLeg();
            hm.drawTorso();
            hm.drawRArm();
            hm.drawLArm();
            // When you want to return to start Page
            *gameOver = 1;
            *playGame = 0;          
    } 
    glPopMatrix();
    glColor3f(0.86,0.83,0.74);
    onScreen::text(250,500,hm.w.updateWord);
    onScreen::text(100,450,hm.w.meaning);
    onScreen::text(270,400,"Score");
    onScreen::text(290,350,scr);
    onScreen::text(200,150,"The Entered Characters:");
    onScreen::text(220,120,hm.w.enteredText);
}


onScreen::onScreen(){
    h = 800;
    w = 800;
    ax0 = 600;
    ax1 = 700;
    by0 = 400;
    by1 = 40;
    aspect = (float)h/(float)w;
}