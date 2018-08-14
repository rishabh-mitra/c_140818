#include<stdio.h>

  

void strcpy1 (char *s, const char *t)

{

    while (*s++ = *t++);

}



int main()

{

        const char *str1="anubhav";

        char *str2;

        strcpy1(str2,str1);

        printf("%s",str2);

}
