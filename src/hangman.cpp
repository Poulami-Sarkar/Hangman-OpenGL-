#include "../include/global.h"
#include "../include/man.h"
#include "../include/onScreen.h"
//#include "../include/words.h"

int wrongTry = 6,i = 0,wordLen,occur = 1,playGame = 0,xM,yM,instructions = 0,quit= 0,gameOver = 0; // The no of attempts given to the Player,occur is 1 : is already in entered text;
// Stores the word that is chosen from the words.txt file
char meaning[200];
char output[100][2][100];
man hm;                                 //Hanged man

void initialiseParams(){
    long int random;
    srand(time(NULL));
    random = (rand())%10;
    printf("The random no generated: %d\n",random);
    strcpy(hm.w.hangmanWord,output[random][0]);
    strcpy(meaning,output[random][1]);
    strncpy(hm.w.enteredText,"",sizeof(hm.w.enteredText));
    strncpy(hm.w.updateWord,"",sizeof(hm.w.updateWord));
    printf("The updateword: %s\n",hm.w.updateWord);
    printf("The hangman: %s\n",hm.w.hangmanWord);
    printf("The entered: %s\n",hm.w.enteredText);
    wordLen = strlen(hm.w.hangmanWord);
    wrongTry = 6;
    for (int i=0;i<wordLen;i++){
        hm.w.updateWord[i]='-';
    }
    printf("The updateword: %s\n",hm.w.updateWord);  
}

void playGamefun(){
    // The box containing the updateWord
    glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glRecti(250,550,550,650);
        glRecti(50,450,750,600);
    glPopMatrix();

    if(strcmp(hm.w.hangmanWord,hm.w.updateWord) == 0){
        onScreen::text(220,300,"You won the Game");
        wrongTry = 999;
        glutPostRedisplay();
        onScreen::text(220,275,"Press 'ESC' to go to Main Page");       
    }
    if(wrongTry == 5){
        hm.drawHead();
    }
    else if (wrongTry ==4)
    {
        hm.drawHead();
        hm.drawTorso();
    }
    else if (wrongTry ==3)
    {

        hm.drawHead();
        hm.drawRArm();
        hm.drawTorso();
    }
    else if (wrongTry ==2){
        hm.drawHead();
        hm.drawRArm();
        hm.drawLArm();	
        hm.drawTorso();
    }
    else if (wrongTry ==1){
        hm.drawHead();
        hm.drawRLeg();
        hm.drawTorso();
        hm.drawRArm();
        hm.drawLArm();
    }else if (wrongTry ==0 || wrongTry == -1){
        hm.drawHead();
        hm.drawLLeg();
        hm.drawRLeg();
        hm.drawTorso();
        hm.drawRArm();
        hm.drawLArm();
        // When you want to return to start Page
        gameOver = 1;
        playGame = 0;
            
    } 
    glColor3f(1.0,0.0,0.0);
    onScreen::text(250,500,hm.w.updateWord);
    onScreen::text(70,450,meaning);
    onScreen::text(200,150,"The Entered Characters:");
    onScreen::text(220,120,hm.w.enteredText);
    

}


void startPage(){
    if(playGame == 0){
        glMatrixMode (GL_MODELVIEW);
        glPushMatrix();
            glColor4f(0.8, 0.5, 0.0,1.0);
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
        wrongTry = 6;

        onScreen::drawButton(300, 225, 500, 265,"Exit");
        onScreen::drawButton(300,265,500,305,"Instructions");
        onScreen::drawButton(300,305,500,345,"Play");
        onScreen::text(275,350,"Let's Play");
        onScreen::text(230,310,"The Game Of Words");
    }
    
}

// to check is the given key is already present in the entered set of keys;
void winReshapeFcn (int newWidth, int newHeight)
{
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
glViewport (0, 0, newWidth, newHeight);
gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
glClear (GL_COLOR_BUFFER_BIT);

}


void checkUsage(unsigned char key){
    int j;
    key = toupper(key);
    bool exist = false;
    for(j = 0 ;hm.w.enteredText[j]!='\0';j++){
        if(key==hm.w.enteredText[j]){
            exist = true;
            break;
        }
    }
    if(j == strlen(hm.w.enteredText) && exist == false){
        // this letter is entered for the first time and is not in enteredText
        occur = 0;
    }
    if(!exist){
            for(j = 0;j<26;j++){
                if(hm.w.enteredText[j]=='\0'){
                        hm.w.enteredText[j]=key;
                        break;
                }
            }
    }
	glutPostRedisplay();
}

void enter(unsigned char key,int x, int y){
    int f = 0;
    //f  is 0: the key does not occur in hangmanWord
    checkUsage(key);
    //if(wrongTry == 0)
    //  wrongTry--;
    
    if(strchr(hm.w.hangmanWord, key)){
        f=1;
        hm.w.update(key,wordLen);
    }
    if(f==0 && occur == 0){
    // reset occur to 1
       wrongTry--;
       occur = 1;
    }
    switch ( key )
    {
        case 27: // Escape key
            //int currentWindowID = glutGetWindow();
            //glutDestroyWindow(currentWindowID);
            //exit(0);
            playGame = 0;
            gameOver = 0;
            initialiseParams();
            break;
    }
    
}

void mouseFunc(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    int x,y;
    x = 300;
    y = 365;
    if (playGame == 0){
        if ( xMouse > x && xMouse < x+200 && yMouse > y && yMouse < y+40){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                playGame = 1;
                gameOver = 0;
            }
        }
        else if ( xMouse > x && xMouse < x+200 && yMouse > y+40 && yMouse < y+40*2){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                instructions = 1;
            }
        }else if ( xMouse > x && xMouse < x+200 && yMouse > y+40*2 && yMouse < y+40*3){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                quit = 1;
            }
        }
    }
glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(quit == 1){
        exit(0);
    }
    if(playGame == 1 && gameOver == 0){
        playGamefun();
    }
    else if(gameOver == 1){
        onScreen::gameOverfun(hm.w.hangmanWord);
    }
    else
    {
        startPage();
    }
    glFlush();
    glutPostRedisplay();   
}


void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5,0.5,0.2,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,350,0,350);
    glLineWidth(4.0);
    
}

void passive(int x,int y){
    xM = x;
    yM = y;
}


int main(int argc,char **argv) {
    // Read from the file the words
	FILE *fp;
    fp = fopen("words.txt", "r");
    while(!feof(fp)){
        fscanf(fp,"%s%[^\n]",output[i][0],output[i][1]);
        i++;
    }
    
    fclose(fp);
    initialiseParams();
    initialiseParams();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Hangman");
    init();
   // glutFullScreen();
    glutKeyboardFunc(enter);
    glutMouseFunc(mouseFunc);
    glutDisplayFunc(display); 
    glutPassiveMotionFunc(passive);
    glutReshapeFunc(winReshapeFcn);   
    glutMainLoop();
    return 0;
};