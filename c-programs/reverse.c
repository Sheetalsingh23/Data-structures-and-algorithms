/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int n, reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n)
    {
        reverse = (reverse * 10) + (n % 10);
        n /= 10;
    }
    printf("Reversed Number is %d", reverse);

    return 0;
}