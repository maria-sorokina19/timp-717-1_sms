#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Heap(int *arr, int root, int base)
{
    int max;
    bool flag = false;
    while ((root * 2 <= base) && (!flag))
    {
        if (root * 2 == base)
            max = root * 2;
        else if (arr[root * 2] > arr[root * 2 + 1])
            max = root * 2;
        else
            max = root * 2 + 1;
        if (arr[root] < arr[max])
        {
            int temp = arr[root];
            arr[root] = arr[max];
            arr[max] = temp;
            root = max;
        }
        else
            flag = true;
    }
    return 0;
}

int sorting_function(int *arr, int arr_len)
{
    int i = (arr_len / 2) - 1;
    int j = arr_len - 1;
    int temp;
    for (i; i >= 0; i--)
        Heap(arr, i, arr_len - 1);
    for (j; j >= 1; j--)
    {
        temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        Heap(arr, 0, j - 1);
    }
    return 0;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int k[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &k[i]);
    }
    sorting_function(k, n);
    for (i = 0; i<n; i++)
    {
        if (i==n-1)
            printf("%d", k[i]);
        else
            printf("%d ", k[i]);
    }
    printf("\n");
    return 0;
}
