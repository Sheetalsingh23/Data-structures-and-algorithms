/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int *simple();

void main()
{
    int *num;
    num = simple();
    printf("\n*num = %d", *num);
}

int *simple()
{
    int a = 10;
    return &a;
}