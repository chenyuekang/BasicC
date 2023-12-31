#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32
/*指针*/
int main()
{
#if 0
    //1.指针怎么定义
    //基础数据类型
    /*建议(Tips):定义变量(任意类型)记得初始化*/
    int a = 0;
    long b = 0;
    
    /*指针的定义*/
    int *p = NULL;
#endif

#if 0
    /*指针的使用:指针内存存放的是某变量的地址*/
    /*一级 & 二级指针*/
    int a = 5;

    int *p = &a;

    printf("a:%d\n", a);
    printf("&a:%p\n", &a);
    /*非常重要*/
    printf("*(&a):%d\n", *(&a));     

    printf("*p = %d\n", *p);      //*p就是解引用（读写数据），read:*p = 5;
    printf("p = %p\n", p);
    printf("&p:%p\n", &p);        //打印ptr是&p,*ptr就是&a,即*(*ptr) = *(&a)

#if 0
    /*这个地方不对*/
    int *ptr = &p;
    printf("p:%p\n", ptr);
#else
    int **ptr = &p;
    printf("ptr:%p\n", ptr);

    printf("*ptr:%p\n", *ptr);

    /*非常非常 重要*/
    printf("*(*ptr):%d\n", *(*ptr));
#endif
#endif


#if 0
    /* 指针的特性1:
       指针占用的内存大小是8个字节（64位操作系统），如果是32位的操作系统指针占用的内存大小是4个字节 
    */
    int a = 10;
    int len = sizeof(a);
    printf("len:%d\n", len);

    char p = 97;
    len = sizeof(p);
    printf("len:%d\n", len);

    char *ptr = &p;
    printf("%c\t%d\n", *ptr, *ptr);
    len = sizeof(ptr);
    printf("len:%d\n", len);

    int *ptrInt = &a;
    printf("*(&a):%d\n", *(&a));
    printf("*ptrInt:%d\n", *ptrInt);
    len = sizeof(ptrInt);
    printf("len:%d\n", len);

#endif

#if 0
    /*指针特性2:指针和字符串*/
    /*字符串是区别于字符数组的*/

    char * ptr = "hello world";
    int len = sizeof(ptr);
    printf("len:%d\n", len);

    /*Q1:怎么判断字符串的长度*/
    int length = strlen(ptr);
    printf("length:%d\n", length);

    /*Q2:字符数组的赋值*/
    char name[BUFFER_SIZE] = {0};
    //name = "zhangsan";
    strcpy(name, "zhangsan");
    printf("name:%s\n", name);

    /*Q3:我要给字符串赋值 bug.*/
    char *ptr2 = NULL;
    printf("&ptr2:%p\n", &ptr2);      
#if 0
    printf("&(zhangsan):%p\n", &("zhangsan"));
    ptr2 = "zhangsan";             //可以正常输出，因为ptr2指向字符串所在地址空间
    printf("ptr2:%p\n", ptr2);
#else
    strcpy(ptr2, "zhangsan");      //出现段错误，因为没有赋值(没有开辟内存空间），字符串在全局常量区，ptr2在栈区(离开函数就释放了)
#endif
    printf("ptr2:%s\n", ptr2);     //输出字符串时用字符串中第一个字符的地址来输出的，%s字符串的输出要地址
#endif  

    /*堆空间*/
    /*void *是一个指针，这个指针被称为万能指针,需要强转*/
    char *ptr = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    strcpy(ptr, "zhangsan");
    printf("ptr:%s\n", ptr);

    return 0;
}