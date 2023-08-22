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
    a.array = (int *)malloc(sizeof(int)*a.size);            // ָ��ָ����� ��̬������ڴ�ռ�
    return a;
}
// ruturn *a local variable will be unvalid
 
void array_free(Array *a)           // Ϊʲô����ṹ��ָ�룿 ��Ϊ��ֵ���ݲ���ı�ṹ���Ա��ֵ����ַ���ݲſ���
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

// ��װ
int array_size(const Array *a)
{
    return a->size;

}

// function: ����ĳԪ��
// retval ��ָ�룬����ָ����Ϊ�����ں�����Ե�ַ�е�ֵ�����޸�
int* array_at(Array *a,int index)
{
    return &(a->array[index]);
}

// ���ý����õķ�ʽȥ�޸�����Ԫ�صĻ� ����get/set����
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
    int *p = (int *)malloc(sizeof(int)*(a->size+more_size));        //�����µ�ָ��
    int i;
    // ����for ѭ��������memcpy������
    // memcpy(p,a,a->size);    ������dst<-src size
    for(i = 0 ; i< (a->size) ; i++)
    {
        p[i] = a->array[i];
    }

    free(a->array);                 // �ͷ�ԭ�����ڴ�ռ�
    a->array = p;                   // ָ�������ָ��任Ϊp
    a->size += more_size;           // size����
}

// (*a).size = a->size
//  �����Ŀɱ���������ȱ�ݵģ�
//  1.����Ŀ�ϴ�ʱ��ÿ�ο����ڴ���ռ�ռ�ϴ� 
//  2.���ڴ�������ʱ�������޷����뵽�ڴ�

int main()
{
    Array a = array_create(100);    // �뿪main��  a�Ŀռ䱻����
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
            *array_at(&a,cnt++) = number;       // �����������Ԫ�ظ�ֵ

    }

    array_free(&a);
    return 0;

}


