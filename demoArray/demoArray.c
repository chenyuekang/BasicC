#include <stdio.h>
#include <string.h>
/*数组：
1.它是一段连续的存储空间
2.它里面存放的数据类型是相同的(没讲，先保留)
*/
#define BUFFER_SIZE 10

int main()
{  
    /*方法一：使用定义即初始化*/
#if 1
    int array[BUFFER_SIZE] = { 0 };
#else
    int array[BUFFER_SIZE];
#endif
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }

    int len = sizeof(array);
    printf("len:%d\n", len);

    /*地址*/
    printf("%p\n", array);
    printf("%p\n", &array[0]);
    printf("%p\n", &array[1]);
    printf("%p\n", &array[9]);
    /*数组的(首)地址和数组的首地址是一样的*/

#if 0
    /*二进制*/
    /*八进制*/
    /*十进制*/
    /*十六进制*/
    /*0 1 2 3 4 5 6 7 8 9 A B C D E F*/
    /*0XXF + 0X01 = 0X10*/
    /*0X34 = 3 * 16 ^ 1 + 4 * 16 ^ 0 = 48 + 4 = 52*/
    /*0Xb4 = 11 * 16 ^ 1 + 4 * 16 ^ 0*/
    /*0X90 = 9 * 16 ^ 1 + 0*/
#endif

#if 0
    /*清除脏数据*/
    memset(array, 0, sizeof(array));
    printf("===========\n");
     
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
#endif

    /*数组的越界访问*/
    /*判断索引的有效性*/
    printf("array[-1]: %d\n", array[-1]);
    printf("array[10]: %d\n", array[10]);

    return 0;
}