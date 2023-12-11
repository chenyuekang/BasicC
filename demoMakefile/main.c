#include <stdio.h>
#include <stdlib.h>


int printString()
{
    int ret = 0;
    printf("printf string\n");
    return ret;
}

int main()
{
    int num1 = 10;
    printf("num:%d\n", num1);
    printString();
    return 0;
}