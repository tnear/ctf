/*
gcc formatString.c -o formatString -g -m32

Input that number and make the program call system("/bin/cat flag.txt");"
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    char name[16];
    unsigned long s1 = 0;
    unsigned long number = 0;
    setvbuf(stdin, 0, 2, 0); // No need to understand this function
    setvbuf(stdout, 0, 2, 0); // No need to understand this function

    printf("Give me your name: ");
    fgets(name, 16, stdin);

    s1 = rand() % 1000000;
    s1 = 3735928559;

    printf("Hello ");
    printf(name);
    printf("\nPick a number: ");
    scanf("%lu", &number);

    if (number != s1) {
        printf("The lucky number is %lu\n", s1);
        puts("Good luck next time");
    } else {
        printf("The flag is cs350{the_flag}");
    }

    return 0;
}
