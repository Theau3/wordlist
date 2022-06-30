#include "wordlist.h"
#include <stdio.h>

int main(){
    FILE * file = fopen(WORDLIST_FILE,"a");
    if (file == NULL)
    {
        file = fopen(WORDLIST_FILE,"w");
    }
    
    int size;
    printf("Size of the words to generate : ");
    scanf("%d",&size);
    int affichage;
    printf("Display? (0/1) : ");
    scanf("%d",&affichage);
    CreateWordlist(file,CHARACTERS,size,affichage);
    fclose(file);
    return 1;
}