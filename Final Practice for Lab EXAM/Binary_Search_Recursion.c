#include <stdio.h>

int binarySearch(int *, int, int, int);

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72}; // SORTED ARRAY
    int length = sizeof(arr) / sizeof(arr[0]);
    int i, item, result;

    printf("\nThe array is : \n|");
    for (i = 0; i < length; i++)
    {
        printf(" %d |", arr[i]);
    }
    printf("\nEnter the item to search : ");
    scanf("%d", &item);

    result = binarySearch(arr, 0, length, item);

    printf("\n >> Result = %d <<\n", result);

    if (result == -1)
        printf("\n>> Item %d Not found << \n", item);
    else
        printf("\n>> Item %d found at index = %d << \n", item, result);

    return 0;
}

int binarySearch(int *arr, int left, int right, int item)
{
    int mid;
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == item)
            return mid;

        if (arr[mid] > item)
            return binarySearch(arr, left, mid - 1, item);

        return binarySearch(arr, mid + 1, right, item);
    }

    return -1;
}
