// Write a C program to perform the operation on
// array 1) initialization 2) Display 3) Copy 4) Delete 5) Insert

/*Name: Sangeeta Singh
Roll no: 22339
Batch: F7
*/

#include <stdio.h>

void init_array(int *, int);
void display(int *, int);
void copy(int *, int);
void delete_array(int *);
void insert(int *, int);

int main()
{
    int n, s;
    int arr[100]; //initializing array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Choose what you want to do with the array\nEnter 1 to initialise the array\nEnter 2 to view elements in array\nEnter elements to copy\nEnter 3 to Delete element in array\nEnter 4 to insert a element in array\n");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        init_array(arr, n);
        break;
    case 2:
        display(arr, n);
        break;
    case 3:
        copy(arr, n);
        break;
    case 4:
        delete_array(arr);
        display(arr, n - 1);
        break;
    case 5:
        insert(arr, n);
        break;
    }
}

void init_array(int a[], int n)
{
    int i;
    printf("\nEnter %d elements: ", n); //inserting elements
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    int i = 0;
    for (i; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void copy(int a[], int n)
{
    int i, b[n];
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

void delete_array(int a[])
{
    int c, k, p;
    printf("Enter the position to delete element:\t"); //deleting array

    scanf("%d", &p);
    if (p <= k)
    {
        for (c = p - 1; c < k - 1; c++)
        {
            a[c] = a[c + 1];
        }
    }
}

void insert(int a[], int n)
{
}