#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sorting_function(int *arr, int arr_len)
{
    int j = arr_len;
    bool step = true;
    int tmp;
    int k = 0;
    while (j > 1 || step == true)
    {
        if (j > 1)
            j /= 1.247f;
        step = false;
        for (int i = 0; i + j < arr_len; ++i)
            if (arr[i + j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + j];
                arr[i + j] = tmp;
                step = 1;
                k++;
            }
    }
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
    sorting_function(k, n);
    for (i = 0; i<n; i++)
    {   
        if (i==n-1) printf("%d", k[i]);
        else printf("%d ", k[i]);
    }
    printf ( "\n" );
    return 0;
}

