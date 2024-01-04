#include <stdio.h>
#include<string.h>
void invers(char* cuvant);
//Read a sentence from the keyboard. For each word, obtain a new one by taking the letters in reverse order and print each new word.
int main ()
{
    char cuvant[100] = "";
    char sir[100] = "";
    fgets(cuvant,99,stdin);
    char* p = strtok(cuvant," \n");
    while(p!= NULL)
    {
        strcpy(sir,p);
        printf("\n Reverse: %s",sir);
        invers(sir);
        printf("\n Reverse: %s",sir);
        p = strtok(NULL," \n");
    }
    return 0;
}
