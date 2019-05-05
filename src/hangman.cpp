#include "../include/global.h"
#include "../include/man.h"
#include "../include/onScreen.h"
//#include "../include/words.h"

int i = 0,wordLen,occur = 1,playGame = 0,xM,yM,instructions = 0,quit= 0,gameOver = 0,score=0; // The no of attempts given to the Player,occur is 1 : is already in entered text;
onScreen screen;
// Stores the word that is chosen from the words.txt file
//char meaning[200];
char output[100][2][100];
man hm;                                 //Hanged man

void initialiseParams(){
    long int random1,random2;
    srand(time(NULL));
    random1 = rand();
    srand(time(NULL));
    random2 = (rand()*random1)%30;
    printf("The random no generated: %d\n",random2);
    strcpy(hm.w.hangmanWord,output[random2][0]);
    strcpy(hm.w.meaning,output[random2][1]);
    strncpy(hm.w.enteredText,"",sizeof(hm.w.enteredText));
    strncpy(hm.w.updateWord,"",sizeof(hm.w.updateWord));
    printf("The updateword: %s\n",hm.w.updateWord);
    printf("The hangman: %s\n",hm.w.hangmanWord);
    printf("The entered: %s\n",hm.w.enteredText);
    wordLen = strlen(hm.w.hangmanWord);
    hm.w.wrongTry = 6;
    for (int i=0;i<wordLen;i++){
        hm.w.updateWord[i]='-';
    }
    printf("The updateword: %s\n",hm.w.updateWord);  
}


// to check is the given key is already present in the entered set of keys;
void winReshapeFcn (int newWidth, int newHeight)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glViewport (0, 0,newWidth, newHeight);
    gluOrtho2D (0.0,newWidth, 0.0,newHeight);
    if (screen.w != newWidth) {
        screen.ax0 =(((float)newWidth + 100)/(float)800)*(float)300;
        screen.ax1 = (((float)newWidth)/(float)800)*(float)500;
        if (newWidth == 1280){
            screen.by0 = 550;
            screen.by1 = ((float)newHeight/(float)800.0)*(float)40.0;
            printf("reshape:%f %f",screen.by0,screen.by1);
        }
        else{
            screen.by0 = 550;
            screen.by1 = ((float)newHeight/(float)800.0)*(float)40.0;
            printf("reshape:%f %f",screen.by0,screen.by1);
        }
    }
    screen.aspect = newHeight/newWidth;
    screen.h = newHeight;
    screen.w = newWidth;
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
    checkUsage(key);
    key = tolower(key);    
    if(strchr(hm.w.hangmanWord, key)){
        f=1;
        hm.w.update(key,wordLen);
    }
    if(f==0 && occur == 0){
    // reset occur to 1
       hm.w.wrongTry--;
       occur = 1;
    }
    switch ( key )
    {
        case 27: 
            playGame = 0;
            gameOver = 0;
            instructions = 0;
            score = 0;
            initialiseParams();
            break;
        case 'n':
            instructions++;
            break;
        case 'p':
            instructions--;
    }
}

void mouseFunc(GLint button, GLint action, GLint xMouse, GLint yMouse)
{ 
    int x,y,add;
    x = screen.exit[0];
    y = screen.play[3];
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
        printf("Click one %d %d",xMouse,yMouse);
    screen.by0 = 365;
    screen.by1 = 405;
    screen.ax0 = 550;
    screen.ax1 = 850;
    add = 40;
    if (playGame == 0){
        if ( xMouse > screen.ax0 && xMouse < screen.ax1 && yMouse > screen.by0 && yMouse < screen.by1){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                glClearColor(0.50f, 0.42f, 0.35f, 1.0f );
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                playGame = 1;
                gameOver = 0;
            }
        }
        else if ( xMouse > screen.ax0 && xMouse < screen.ax1 && yMouse > screen.by0+add && yMouse < screen.by1+add){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                instructions = 1;
            }
        }else if ( xMouse > screen.ax0 && xMouse < screen.ax1 && yMouse > screen.by0+2*add && screen.by1+2*add){
            if( button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
                quit = 1;
            }
        }
    }
    
    if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN && playGame == 1){
           // if(hm.w.correct == 1){
                initialiseParams();
                ++score;
                playGame = 1;
            //}
            
    }
glFlush();
}

void instructionsfun(){
    glColor3f(1.0,0,0);
    screen.text(20,550,"Press 'P' to go to previous and 'N' to go to next");
    glColor3f(0.0,0.0,0.0);

    if(instructions == 1){
        for(int i =0;i<20;i++){
            screen.text(20,500-i*25,output[i][0]);
            screen.text(120,500-i*25,output[i][1]);
        }
    } else if(instructions != 1){
        for(int i =0;i<20;i++){
            screen.text(20,500-i*25,output[i+20][0]);
            screen.text(120,500-i*25,output[i+20][1]);
        }
    }
    
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(quit == 1){
        exit(0);
    }
    if(playGame == 1 && gameOver == 0){
        screen.playGamefun(&playGame,&gameOver,&score,hm);
        
    }
    else if(gameOver == 1){
        screen.gameOverfun(hm.w.hangmanWord,hm);
    }
    else if (instructions == 1 || instructions == 2){
        glClearColor(1.0,1.0,1.0,1.0);
        instructionsfun();
    }
    else
    {
        hm.w.wrongTry = 6;
        screen.startPage(playGame);
    }
    glFlush();
    glutPostRedisplay();   
}


void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6,0.1,0.1,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
    glLineWidth(4.0);
    
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
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1280,960);
    screen.w = 1280;
    screen.h = 960;
    glutInitWindowPosition(0,0);
    glutCreateWindow("Hangman");
    init();
    //glutFullScreen();
    glutKeyboardFunc(enter);
    glutMouseFunc(mouseFunc);
    glutDisplayFunc(display); 
    glutReshapeFunc(winReshapeFcn);   
    glutMainLoop();
    return 0;
};