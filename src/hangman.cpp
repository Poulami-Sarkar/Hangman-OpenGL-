#include "../include/global.h"
#include "../include/man.h"
#include "../include/onScreen.h"
//#include "../include/words.h"

int wrongTry = 6;
char hangmanWord[20] = "chocolate";
char tempWord[20] = "---------";

void showHangman(int);


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




void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,350,0,350);
    //words::wrongTry = 6;
	
	//strcpy(words::hangmanWord,"chocolate");
	//strcpy(words::tempWord,"-------") ;
    
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //displayword(-0.4,1.66,0.0,1.0,0.0,GLUT_BITMAP_HELVETICA_12,hangmanWord);

	if(wrongTry == 5){
		man::drawHead();
	}
    else if (wrongTry ==4)
	{
		man::drawHead();
		man::drawTorso();
	}
    else if (wrongTry ==3)
	{

		man::drawHead();
		man::drawRArm();
		man::drawTorso();
    }
    else if (wrongTry ==2){
		man::drawHead();

		man::drawRArm();
		man::drawLArm();	

		man::drawTorso();

    }
    else if (wrongTry ==1){
		man::drawHead();
		man::drawRLeg();
		man::drawTorso();
		man::drawRArm();
		man::drawLArm();
    }
    else if (wrongTry ==0){
		man::drawHead();
		man::drawLLeg();
		man::drawRLeg();
		man::drawTorso();
       	man::drawRArm();
		man::drawLArm();
        onScreen::text(10,200,"You lost the game. Press any key to exit");        
    }

    onScreen::text(100,300,tempWord);
    glFlush();
    glutPostRedisplay();   
}



int main(int argc,char **argv) {

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
};


