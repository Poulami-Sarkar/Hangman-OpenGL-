#include "../include/global.h"
#include "../include/man.h"
#include "../include/onScreen.h"
//#include "../include/words.h"

int wrongTry = 6; // The no of attempts given to the Player
char hangmanWord[20];// Stores the word that is chosen from the words.txt file
char updateWord[20]; // 
int wordLen,occur = 1; // occur is 1 : is already in entered text;
char enteredText[50];
int* checkWord;
int sumCheckWord = 0;

void showHangman(int);

void showHint(){
    glMatrixMode (GL_MODELVIEW);
        glColor3f (0.0, 1.0, 1.0);
    glRecti (200, 250, 350, 300);
}

// to check is the given key is already present in the entered set of keys;
void winReshapeFcn (int newWidth, int newHeight)
{
glMatrixMode (GL_PROJECTION);
glLoadIdentity ( );
glViewport (0, 0, newWidth, newHeight);
gluOrtho2D (0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
glClear (GL_COLOR_BUFFER_BIT);
}

void checkUsage(unsigned char key){
    int j;
    key = toupper(key);
    bool exist = false;
    for(j = 0 ;enteredText[j]!='\0';j++){
        if(key==enteredText[j]){
            exist = true;
            break;
        }
    }
    if(j == strlen(enteredText) && exist == false){
        // this letter is entered for the first time and is not in enteredText
        occur = 0;
    }
    if(!exist){
            for(j = 0;j<26;j++){
                if(enteredText[j]=='\0'){
                        enteredText[j]=key;
                        break;
                }
            }
    }

    int n=wordLen;
	glutPostRedisplay();


}
void update(unsigned char key){
    for (int i=0;updateWord[i]!='\0';i++){
        if(hangmanWord[i] == key){
            updateWord[i] = key;
            checkWord[i]=1;		
        }
    }
    sumCheckWord = 0;
    for (int i = 0 ; i<wordLen;i++){
        sumCheckWord += checkWord[i];
    }
    //printf("The sumcheckword: %d\n",sumCheckWord);
    //printf("wordLen : %d",wordLen);
}

void enter(unsigned char key,int x, int y){
    int f = 0;
    //f  is 0: the key does not occur in hangmanWord
    checkUsage(key);
    if(wrongTry == 0)
        exit(0);
    if(strchr(hangmanWord, key)){
        f=1;
        update(key);
    }
    if(f==0 && occur == 0){
       wrongTry--;
       occur = 1;
    }
    switch ( key )
    {
        case 27: // Escape key
            int currentWindowID = glutGetWindow( );
            glutDestroyWindow(currentWindowID);
            exit(0);
            break;
    }
    
}




void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,350,0,350);
    glLineWidth(4.0);
    wordLen = strlen(hangmanWord);

    checkWord = new int[wordLen];
    for (int i = 0; i < wordLen ; i++){
		checkWord[i]=0;
	}


    for (int i=0;i<wordLen;i++){
        updateWord[i]='-';
    }
    
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //displayword(-0.4,1.66,0.0,1.0,0.0,GLUT_BITMAP_HELVETICA_12,hangmanWord);
    showHint();
	if(sumCheckWord == wordLen){
        onScreen::text(200,250,"You won the Game");
        wrongTry = 999;
        glutPostRedisplay();
        onScreen::text(200,200,"Press 'ESC' to exit");       
    }
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
        onScreen::text(10,230,"The word is:");
        onScreen::text(220,230,hangmanWord);  
              
    }
    
    
    onScreen::text(100,300,updateWord);
    onScreen::text(350,550,"The Entered Charachters:");
    onScreen::text(350,450,enteredText);
    glFlush();
    glutPostRedisplay();   
}



int main(int argc,char **argv) {

    int i=0;
	FILE *fp;
    fp = fopen("words.txt", "r");

    char output[100][2][100];
    
    while(!feof(fp)){
        //fscanf(fp,"%s %s",output[i][0],output[i][1]);
        fscanf(fp,"%s",output[i][0]);
        i++;
    }
    fclose(fp);

    int random;

    srand(time(NULL));
    random = (rand())%10;
    printf("The random no generated: %d\n",random);
    strcpy(hangmanWord,output[random][0]);    

    char hangmanOutput[100];             
    int matchFound = 0;                         
    int counter = 0 , position = 0, winner, length ;
    char alphabetFromUser;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    //glutInitWindowPosition(0,0);
    glutCreateWindow("Hangman");
    init();
   // glutFullScreen();
    glutKeyboardFunc(enter);
    glutDisplayFunc(display); 
    glutReshapeFunc(winReshapeFcn);   
    glutMainLoop();
    return 0;
};