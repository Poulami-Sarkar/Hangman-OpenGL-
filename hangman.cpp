// C program to illustrate OpenGL game
#include<stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include<math.h>
#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<stdlib.h>
#include <unistd.h>

//#include "hang.h"

int wrongTry = 6;
char hangmanWord[100] ="i like big butts and cannot lie";
char tempWord[100]    ="- ---- --- ----- --- ------ ---" ;
void showHangman(int);

void text(GLfloat x,GLfloat y,char * tempWord)
{
    int len,i;
    char menu[80];
    strcpy(menu,tempWord);
    len = strlen(menu);
    glColor3f(1,0,0);
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0, 600, 0, 600 );
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for ( i = 0; i < len; ++i )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
    glPopMatrix();
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
}


void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,350,0,350);
}
void drawPixel(int x, int y){
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    //sleep(1);
    glFlush();

}

void draw_line(GLfloat x0,GLfloat y0, GLfloat x1,GLfloat y1){
    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex2d(x0,y0);
    glVertex2d(x1,y1);
    glEnd(); 
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //displayword(-0.4,1.66,0.0,1.0,0.0,GLUT_BITMAP_HELVETICA_12,hangmanWord);

    if (wrongTry ==4)
        //body
        draw_line(30,20,30,50);
    else if (wrongTry ==3){
        //hands
        draw_line(30,50,50,35);
        draw_line(30,20,30,50);
    }
    else if (wrongTry ==2){
        //hands
        draw_line(30,50,10,35);
        draw_line(30,50,50,35);
         //body
        draw_line(30,20,30,50);
    }
    else if (wrongTry ==1){
        //legs
        draw_line(30,20,50,5);
        //body
        draw_line(30,20,30,50);
        //hands
        draw_line(30,50,10,35);
        draw_line(30,50,50,35);
    }
    else if (wrongTry ==0){
        draw_line(30,20,10,5);
        draw_line(30,20,50,5);
        draw_line(30,20,30,50);
        draw_line(30,50,10,35);
        draw_line(30,50,50,35);
        text(100,200,"LOSER LOSER YOU STUPID OLD GEEZER. Press any key to exit");        
    }
    //glutSolidTeaPot(0.08);
    text(100,300,tempWord);
    glFlush();
    glutPostRedisplay();   
}

void update(unsigned char key){
    for (int i=0;tempWord[i]!='\0';i++){
        if(hangmanWord[i] == key)
            tempWord[i] = key;
    }
}

void enter(unsigned char key,int x, int y){
    int f = 0;
    if(wrongTry == 0)
        exit(0);
    //usleep(5000000);
    if(strchr(hangmanWord, key)){
        f=1;
        update(key);
    }
    if(f==0)
        wrongTry--;
}

int main(int argc,char **argv)
{

    char hangmanOutput[100];             
    int matchFound = 0;                         
    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    //glutInitWindowPosition(0,0);
    glutCreateWindow("Hangman");
    init();
    glutKeyboardFunc(enter);
    glutDisplayFunc(display);    
    glutMainLoop();
    return 0;
}


