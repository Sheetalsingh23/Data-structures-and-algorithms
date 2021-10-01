/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

void swapv(int, int *ptr);

void main()
{
    int a = 10, b = 20;
    printf("Before swapping a = %d and b = %d", a, b);
    swapv(a, &b);
    printf("\nBefore swapping a = %d and b = %d", a, b);
}

void swapv(int a, int *ptr)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("\nAfter swapping a = %d and b = %d", a, b);
}