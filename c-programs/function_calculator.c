/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

void add(int, int);
void sub(int, int);
void mul(int, int);
void div(int, int);

void main()
{
    int a, b, choice, d;
    printf("\nEnter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add(a, b);
        break;
    case 2:
        sub(a, b);
        break;
    case 3:
        mul(a, b);
        break;
    case 4:
        div(a, b);
        break;
    default:
        printf("\nEnter valid choice!");
        break;
    }
    // printf("\nAre you interested in further operation");
    // printf("\nPress 1 otherwise 0\n");
    do
    {
        // printf("\nAre you interested in further operation");
        // printf("\nPress 1 otherwise 0\n");
        // scanf("%d", d);
    } while (d);
}

void add(int a, int b)
{
    printf("\nAddition: ", a + b);
}
void sub(int a, int b)
{
    printf("\Subtraction: ", a - b);
}
void mul(int a, int b)
{
    printf("\Multiplication: ", a * b);
}
void div(int a, int b)
{
    printf("\Division: ", a / b);
}