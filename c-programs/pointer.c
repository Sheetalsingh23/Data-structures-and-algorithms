/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

void main()
{
    int a;
    int *ptr;

    printf("Enter an integer a: ");
    scanf("%d", &a);

    ptr = &a;
    printf("\nValue of a = %d", a);
    printf("\nValue of *ptr = %d", *ptr);
    printf("\nValue of ptr = %d", ptr);
    printf("\nValue of address = %d", &a);
    printf("\nThe size of the pointer is %d bytes", sizeof(ptr));

    // char c = 'A';
    // char *ptr = &c;
    // printf("The size of the character pointer is %d bytes", sizeof(ptr));
}