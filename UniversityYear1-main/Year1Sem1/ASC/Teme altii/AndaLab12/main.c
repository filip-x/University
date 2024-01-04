#include <stdio.h>
char* concatenare(char string1[],char string2[]);


int main()
{
    char rez[30] = "";
    char str1[]="aeghkm54";
    char str2[]="evhjjo98";
    printf("The first resulted string is %s\n",concatenare(str2,str1));
    //strcpy(rez,concatenare(str1,str2));
    printf("The second resulted string is %s",concatenare(str1,str2));
    return 0;
}