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
    glScalef(0.1*(float)w/800,0.2*(float)h/800,11);
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

void onScreen::gameOverfun(char *hangmanword){
    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(1.0,1.0,1.0,0.3);
    
    onScreen::text(150,290,"You lost the game. Press any key to exit");
    onScreen::text(200,260,"The word is:");
    onScreen::text(300,260,hangmanword);
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
        onScreen::text(300-70*(float)w/800,y0-30*(float)h/800,disp);
        glPopMatrix();
    glPopMatrix();
}


void onScreen::startPage(int playGame){
    float aspect = h/w;
    if(playGame == 0){
        glMatrixMode (GL_MODELVIEW);
        glPushMatrix();
            glColor4f(0.3, 0.3, 0.3,1.0);
            glRecti (250, 350, 550, 450);
        glPopMatrix();
        glColor4f(0.2, 0.3, 0.1,1.0);
        glBegin(GL_LINES);
            glVertex2i(500,345);
            glVertex2i(300,345);
            glVertex2i(300,225);
            glVertex2i(300,345);
            glVertex2i(500,225);
            glVertex2i(500,345);
        glEnd();
       
        onScreen::drawButton(exit,"Exit");
        onScreen::drawButton(instr,"Instructions");
        onScreen::drawButton(play,"Play");
        onScreen::text(275,350,"Let's Play");
        onScreen::text(230,310,"The Game Of Words");
    }
    
}


void onScreen::playGamefun(int *playGame,int *gameOver,man hm){
    // The box containing the updateWord
    
    glPushMatrix();
        glColor3f(0.66,0.63,0.54);
        glRecti(250,550,550,650);
        glRecti(50,450,750,600);
    glPopMatrix();

    if(strcmp(hm.w.hangmanWord,hm.w.updateWord) == 0){
        onScreen::text(220,300,"You won the Game");
        hm.w.wrongTry = 999;
        glutPostRedisplay();
        onScreen::text(220,275,"Press 'ESC' to go to Main Page");       
    }
    if(hm.w.wrongTry == 5){
        hm.drawHead();
    }
    else if (hm.w.wrongTry ==4)
    {
        hm.drawHead();
        hm.drawTorso();
    }
    else if (hm.w.wrongTry ==3)
    {

        hm.drawHead();
        hm.drawRArm();
        hm.drawTorso();
    }
    else if (hm.w.wrongTry ==2){
        hm.drawHead();
        hm.drawRArm();
        hm.drawLArm();	
        hm.drawTorso();
    }
    else if (hm.w.wrongTry ==1){
        hm.drawHead();
        hm.drawRLeg();
        hm.drawTorso();
        hm.drawRArm();
        hm.drawLArm();
    }else if (hm.w.wrongTry ==0 || hm.w.wrongTry == -1){
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
    glColor3f(0.86,0.83,0.74);
    onScreen::text(250,500,hm.w.updateWord);
    onScreen::text(70,450,hm.w.meaning);
    onScreen::text(200,150,"The Entered Characters:");
    onScreen::text(220,120,hm.w.enteredText);
}

onScreen::onScreen(){
    h = 800;
    w = 800;
    ax0 = 300;
    ax1 = 500;
    by0 = 400;
    by1 = 40;
    aspect = (float)h/(float)w;
}