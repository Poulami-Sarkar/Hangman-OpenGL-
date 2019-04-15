// C program to illustrate OpenGL game
#include<stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include<math.h>
#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<stdlib.h>

//#include "hang.h"

int wrongTry = 6;
char hangmanWord[100] ="i like big butts and cannot lie";
char tempWord[100];
void showHangman(int);

void text(float x, float y, float r, float g, float b, void* font, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
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

void displayword(float x, float y, float r, float g, float b, void* font, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    displayword(-0.4,1.66,0.0,0.0,0.0,GLUT_BITMAP_HELVETICA_12,hangmanWord);

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
    }
    //glutSolidTeaPot(0.08);
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


