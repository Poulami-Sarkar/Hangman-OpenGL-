#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef __linux__
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h> 
#endif

#include <iostream>
#include <math.h>
#include <chrono>
#include <ctime> 
#include <string.h>
#include <string>
//#include <unistd>

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif

#define RAD(x)          (PI*(x)/180)
#define GRAUS(x)        (180*(x)/PI) //Degrees


#endif
