#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*状态码*/
enum STATUS_CODE     //枚举
{
   REGISTER = 1,
   LOGIN,
   QUIT,
};

/*宏定义*/
/*代码规范：宏必须全部大写*/
#define COUNT_NUM 10
#define RANGE_NUM 200

int main()
{
#if 0
    /*判断语句*/
    int budget = 5000;

    int applephone = 8999;
    int mi14Pro = 4399;
    int huaweiP60 = 6000;

    if(budget > applephone)
    {
        printf("get a applephone!\n");
    }
    else if( budget > mi14Pro)
    {
        printf("get a mi14Pro!\n");
    }
     else if( budget > huaweiP60)
    {
        printf("get a huaweiP60!\n");
    }
#endif


#if 0
    int budget = 5000;
    int minbudget = 5500;
    int maxbudget = 8000;

    int applephone = 8999;
    int mi14Pro = 4399;
    int huaweiP60 = 6000;

    /* ||:只要有一个条件被满足，那么就为1（成立）*/
    if((budget < applephone) || (budget > mi14Pro))
    {
        printf("I am happy, get a phone\n");
    }
    else
    {
        printf("I am sad, no phone\n");
    }
    /* 0 && 1 = 0*/
    /* &&:两边都是1（成立）才是1 */ 
    if((minbudget < budget) && (budget < maxbudget))
    {
        printf("success get a phone\n");
    }
    else
    {
        printf("error get a phone\n");
    }
#endif
/*代码规范1：一个函数尽量不要超过80行，最多不要超过120行，需要拆分优化*/


#if 0
    /*坑1：每一个case都需要有breakaa;*/
    int choice = 0;
    printf("请输入你的选项:");
    scanf("%d", &choice);
    /*switch*/
    switch(choice)
    {
    case REGISTER:
        {
    /*坑2：如果case里面的语句过多，一定需要加上{}来包含*/
        printf("welcome to register\n");
        }
        break;
    case LOGIN:
        {
        printf("welcome to logic\n");
        }
        break;
    case QUIT:
        {
        printf("welcome to quit\n");
        }
        break;
    default:
        printf("input choice invalid\n");
        break;
    }
#endif    

#if 0
    srand(time(NULL));

    /* 请你写一个100以内的数[1-100]*/
    //int randomNum = rand() % 100 + 1;
    /* 循环 */
    /*for循环*/

    /*代码规范：循环不允许使用i*/
    /*代码规范：不允许使用魔鬼数字,要用宏定义*/
    int randomNum = 0;    //在外面定义的话，只开辟一次，如果在大括号里面，每次都需要开辟空间，比较浪费时间
    for(int idx = 0; idx < COUNT_NUM; idx++)
    {
        randomNum = rand() % RANGE_NUM + 1;
        printf("randomNum:%d\n", randomNum);
    }

#endif


#if 1
/*编码规范：变量尽量使用驼峰式命令*/
/*for循环有结束的条件，而while则没有*/
/*什么情况下CPU消耗会飙升  ？*/
    int circuleTimes = COUNT_NUM >> 1;
    int randomNum = 0;

    /*while一定需要有退出的条件*/
    while(circuleTimes--)    //circuleTimes--后置是先判断再运算   
    {                        //--circuleTimes前置是先运算再判断
        randomNum = rand() % RANGE_NUM + 1;
        printf("randomNum:%d\n", randomNum);
    }

#endif
    return 0;
}