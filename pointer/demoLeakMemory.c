#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10
/*内存泄漏:3种场景
   1.野指针
   2.malloc出的堆空间没有被释放
   3.踩空间（read/write is invalid.)
*/

int main()
{
    /*Q1.什么情况下会导致内存泄漏*/
    //case 1:野指针  
#if 0 
    int a;
    printf("a:%d\n", a); 

    int array[BUFFER_SIZE];
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("%d\t", array[idx]);
    }
#endif

#if 0
    char *p;    //p = 0xf4654852201;野指针
    printf("\n");
#endif

    //case2:
    char *ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if(!ptr)
    {
        /*todo...*/
        /*状态码*/
        return -1;
    }
    /*使用malloc分配的空间，数据是脏的（脏数据）*/
    memset(ptr, 0, sizeof(char) * BUFFER_SIZE);
#if 0
    /*极度危险的函数 该用strncpy*/
    strcpy(ptr, "hello worldrefdscxfd");     //只分配10个字节，你没有权限使用别人的地址空间(强占空间)
#else
    /* 使用安全 */
    strncpy(ptr, "hello worldgerhr", BUFFER_SIZE - 1);      //留一个空间给'\0'
#endif          
    printf("ptr:%c\n", *ptr);

#if 1
    if(ptr != NULL)
    {
        free(ptr);
        ptr = NULL;
    }

    if(ptr != NULL)      //这种写法不会出现两次释放
    {
        free(ptr);
        ptr = NULL;
    }
 #endif   

    return 0;
}