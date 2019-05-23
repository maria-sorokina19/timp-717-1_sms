#include <stdio.h>
#include <stdlib.h>

int sorting_function(int *arr, int arr_len)
{
    int step, tmp, j;
    int k = 0;
    for (step = arr_len / 2; step > 0; step /= 2)
        for (int i = step; i < arr_len; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
            k++;
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
        else  printf("%d ", k[i]);
    }
    printf ( "\n" );
    return 0;
}

