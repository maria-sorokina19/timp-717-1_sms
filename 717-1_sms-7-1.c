#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sorting_function(int *arr, int start_arr, int arr_len, int k)
{
    int i = start_arr;
    int j = arr_len;
    int tmp, temp;
    if ((start_arr+arr_len)%2==1)
        temp = arr[(start_arr+arr_len-1)/2];
    else
        temp = arr[(start_arr+arr_len)/2];
    do
    {
        while(arr[i]<temp)
            i++;
        while(arr[j]>temp)
            j--;
        if (i <= j)
        {
            if(i<j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                k++;
            }
            i++;
            j--;
        }
    }
    while (i<=j);
    if (i < arr_len)
        sorting_function(arr, i, arr_len, k);
    if (start_arr < j)
        sorting_function(arr, start_arr, j, k);
    return k;
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
    sorting_function(k, 0, n-1, 0);
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

