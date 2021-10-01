/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

int main()
{
    int n, reverse = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n)
    {
        reverse = (reverse * 10) + (n % 10);
        n /= 10;
    }
    if (temp == reverse)
        printf("palindrome number ");
    else
        printf("not palindrome");

    return 0;
}