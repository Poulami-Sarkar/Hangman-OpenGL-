#include<stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include<math.h>
#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/
#include<stdlib.h>

int X1, X2, Y1, Y2;

void text(float x, float y, float r, float g, float b, void* font, char *string);
void init();
void drawPixel(int x, int y);
void draw_line(GLfloat x0,GLfloat y0, GLfloat x1,GLfloat y1);
void display();