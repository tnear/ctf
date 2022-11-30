/*
https://www.youtube.com/watch?v=qpyRz5lkRjE

gcc bufferOverflow.c -o bufferOverflow -fno-stack-protector -m32 -no-pie -g
(ignore warnings about 'gets')

See bufferOverflowDriver.py

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void debug()
{
    printf("!! SPAWNING SHELL !!\n");
    system("/bin/bash");
}

bool isValidPassword(char *input)
{
    return strcmp("my_pass", input) == 0;
}

bool checkPassword()
{
    char password[64];

    printf("password: ");
    gets(password);

    return isValidPassword(password);
}

int main(int argc, char **argv)
{
    printf("WELCOME TO THE SECURE SERVER\n");

    if (checkPassword())
    {
        debug();
    } else {
        printf("Wrong password, sorry.\n");
    }
}
