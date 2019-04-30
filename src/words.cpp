#include "../include/words.h"
#include "../include/global.h"

void words::update(unsigned char key,int wordLen){
    for (int i=0;i<wordLen;i++){
        if(hangmanWord[i] == key){
            updateWord[i] = key;
        }
    }
}