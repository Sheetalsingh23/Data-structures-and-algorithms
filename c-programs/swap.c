/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int a, b, temp;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    temp = a;
    a = b;
    b = temp;
    printf("%d %d", a, b);

    return 0;
}