#include "wordlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void CreateWordlist(FILE *file, char *characters, int size, int display)
{
    char *word = malloc(sizeof(char) * (size + 1));
    int *index = malloc(sizeof(int) * (size + 1));
    float seconds = 0;
    for (int i = 0; i < size; i++)
    {
        index[i] = 0;
    }
    long double possibilites = powl(strlen(characters), size);
    word[size] = '\0';
    clock_t begin = clock();
    for (unsigned long long i = 0; i < possibilites; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (index[j] >= (int)strlen(characters))
            {
                index[j + 1]++;
                index[j] = 0;
            }
        }
        for (int j = 0; j < size; j++)
        {
            word[j] = characters[index[j]];
        }
        fprintf(file, "%s\n", word);

        index[0]++;
        if (display == 1 && i % (int)(possibilites / 100) == 0)
        {
            system(CLEAR);
            int percentage = round((i / possibilites) * 100);
            printf("%d%% [", percentage);
            for (int i = 0; i < percentage / 10; i++)
            {
                printf("%c", 0xdb);
            }
            for (int i = 0; i < 10 - (percentage / 10); i++)
            {
                printf("-");
            }
            printf("]");
            if (seconds != 0)
            {
                PrintTime(seconds / 20);
            }
        }
        if (i == (unsigned int)(possibilites / 50))
        {
            clock_t end = clock();
            seconds = (end - begin) * 1000 / CLOCKS_PER_SEC;
            system(CLEAR); 
            PrintTime(seconds / 20);
        }
    }
}

void PrintTime(float seconds)
{
    int minutes = 0;
    while (seconds >= 60)
    {
        seconds -= 60;
        minutes += 1;
    }
    printf("\nEstimation of the total task time : %d minutes and %.2f seconds", minutes, seconds);
}