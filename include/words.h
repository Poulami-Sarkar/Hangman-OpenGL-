#ifndef WORDS_H
#define WORDS_H


#include "../include/global.h"
#include "../include/man.h"
#include "../include/words.h"


class words{
	const char wordlist[20][100]  = {"big","butts","cute","babies","hot","grasshoppers","bunnies","rabies","heat","dinosaurs"};
public:
	static int wrongTry ;
	static char hangmanWord[100];
	static char tempWord[100]; 

	words();
	static void update(unsigned char key);
	static void enter(unsigned char key,int x, int y);
	
};

#endif
