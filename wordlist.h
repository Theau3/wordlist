#ifndef WORDLIST_H
#define WORDLIST_H
#include <stdio.h>

#define CHARACTERS      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define WORDLIST_FILE   "wordlist.txt" 
#define CLEAR           "cls" //"clear" for linux

void CreateWordlist(FILE * file, char * characters, int size, int display);
void PrintTime(float seconds);
#endif