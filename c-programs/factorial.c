/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int n, i, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        fact *= i;
    }
    printf("The factorial of the %d is %lli \n", n, fact);

    return 0;
}