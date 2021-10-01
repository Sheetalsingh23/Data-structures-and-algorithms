/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    printf("The sum of the digits is %d \n", sum);

    return 0;
}