#ifndef WORDS_H
#define WORDS_H

#include "../include/global.h"

class words{
//	const char wordlist[20][100]  = {"big","butts","cute","babies","hot","grasshoppers","bunnies","rabies","heat","dinosaurs"};
public:
	int wrongTry ;
	char hangmanWord[20],updateWord[20],enteredText[50],meaning[200];
	//words();
	void update(unsigned char key,int wordLen);
	void enter(unsigned char key,int x, int y);
	
};

#endif
