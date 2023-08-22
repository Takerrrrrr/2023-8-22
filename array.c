#include "array.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// typedef struct 
// {
//     int *array;
//     int size;
// }Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int)*a.size);            // 指针指向的是 动态申请的内存空间
    return a;
}
// ruturn *a local variable will be unvalid
 
void array_free(Array *a)           // 为什么传入结构体指针？ 因为，值传递不会改变结构体成员的值，地址传递才可以
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

// 封装
int array_size(const Array *a)
{
    return a->size;

}

// function: 访问某元素
// retval 是指针，返回指针是为了能在函数外对地址中的值进行修改
int* array_at(Array *a,int index)
{
    return &(a->array[index]);
}

// 不用解引用的方式去修改数组元素的话 就用get/set函数
int array_get(const Array *a,int index)
{
    return a->array[index];
}

int array_set(Array *a,int index,int value)
{
    a->array[index] = value;
}

void array_inflate(Array *a,int more_size)
{
    int *p = (int *)malloc(sizeof(int)*(a->size+more_size));        //定义新的指针
    int i;
    // 以下for 循环可以用memcpy来代替
    // memcpy(p,a,a->size);    参数：dst<-src size
    for(i = 0 ; i< (a->size) ; i++)
    {
        p[i] = a->array[i];
    }

    free(a->array);                 // 释放原来的内存空间
    a->array = p;                   // 指向数组的指针变换为p
    a->size += more_size;           // size增加
}

// (*a).size = a->size
//  这样的可变数组是有缺陷的：
//  1.当数目较大时，每次开辟内存所占空间较大 
//  2.当内存有限制时，可能无法申请到内存

int main()
{
    Array a = array_create(100);    // 离开main后  a的空间被回收
    printf("%d\n",array_size(&a));
    *array_at(&a,0) = 10;
    printf("%d\n",*array_at(&a,0));

    int number = 0;
    int cnt = 0;
    while(number != -1)
    {
        printf("input:");
        scanf(":%d",&number);
        if(number != -1)
            *array_at(&a,cnt++) = number;       // 挨个给数组的元素赋值

    }

    array_free(&a);
    return 0;

}


