#include <stdio.h>
#include <string.h>

int main()
{
    /*指针和字符串*/
    char *ptr = "hello world";   //字符串存放在全局(常量)区

    /*Q1:字符串常量？什么叫字符串常量*/
    /*1.打印字符串的每一个字符*/
    /*way1:使用for循环的方式*/
#if 0
    int len = strlen(ptr);
    printf("len:%d\n", len);
    char p = '0';
    for(int idx = 0; idx < strlen(ptr); idx++)
    {
        p = *ptr;
        printf("p:%c, idx:%d\n", p, idx);
        ptr++;
        printf("strlen(ptr):%ld\n", strlen(ptr));
    }
#elif 0
    int len = strlen(ptr);
    printf("len:%d\n", len);
    char p = '0';
    for(int idx = 0; idx < len; idx++)
    {
        p = *ptr;
        printf("p:%c, idx:%d\n", p, idx);
        ptr++;
    }
#else
    /*实现方式2：*/
    while(*ptr != '\0')
    {   printf("%c\t", *ptr);
        ptr++;
    }
    printf("\n");

#endif

    return 0;
}