/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int n, i, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("The sum of first %d numbers is %d \n", n, sum);

    return 0;
}