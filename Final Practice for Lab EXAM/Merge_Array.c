// Write a program to split an array into two arrays

#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    int mid = n / 2;

    int arr1[mid];
    int arr2[n - mid];
    
    for (int i = 0; i < mid; i++)
    {
        arr1[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        arr2[i - mid] = arr[i];
    }

    printf("\nFirst array: ");
    for (int i = 0; i < mid; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\nSecond array: ");
    for (int i = 0; i < n - mid; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}