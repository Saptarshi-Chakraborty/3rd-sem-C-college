#include <stdio.h>

void showItemInArray(int *, int, int);

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72}; // SORTED ARRAY
    int length = sizeof(arr) / sizeof(arr[0]);
    int i, low, mid, high, item, flag;

    printf("\nThe array is : \n|");
    for (i = 0; i < length; i++)
    {
        printf(" %d |", arr[i]);
    }

    printf("\n\nEnter the item you want to search : ");
    scanf("%d", &item);

    printf("\nSearching for %d ...\n", item);

    low = 0, high = length;
    mid = (low + high) / 2;

    if (arr[mid] == item)
    {
        printf("Item found at index: %d\n", mid);
        return 1;
    }
    printf("Before:\nmid = %d , low = %d, high = %d\n", mid, low, high);

    flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == item)
        {
            printf("Item found at index: %d\n", mid);
            break;
        }
        if (arr[mid] < item)
            low = mid + 1;
        else if (arr[mid] > item)
            high = mid - 1;
        printf("mid = %d , low = %d, high = %d\n", mid, low, high);

        // break;
    }

    printf("\nmid = %d, arr[mid] = %d\n", mid, arr[mid]);

    if (arr[mid] == item)
    {
        printf("\n>> Item %d found at index  = %d <<\n", item, mid);
        showItemInArray(arr, length, mid);
    }
    else
        printf("\n>> Item %d Not found <<\n", item);

    return 0;
}


