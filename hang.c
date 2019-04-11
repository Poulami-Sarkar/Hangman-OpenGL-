#include<stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include<math.h>
#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<stdlib.h>

int X1, X2, Y1, Y2;

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

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_line(30,20,10,5);
    draw_line(30,20,50,5);
    draw_line(30,20,30,50);
    draw_line(30,50,10,35);
    draw_line(30,50,50,35);
    //glutSolidTeaPot(0.08);

    glFlush();
}

/*void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}*/

int main(int argc, char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    //glutInitWindowPosition(0,0);
    glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
