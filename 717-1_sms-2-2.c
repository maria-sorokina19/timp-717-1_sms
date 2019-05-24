#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
        int n, i;
        int op = 0;
        int cl = 0;
        int k = 0;
        bool j = false; 
        scanf("%d", &n); 
        char x;
	for (i = 0; i<n; i++)
	{		
		scanf("%c", &x);
		if (x  == '(')
            	{
            		op++;
            	}
            	else if (x == ')')
           	{		
               		cl++;
            	}
            	else if (x == ' ')
            	{	
            		n++;
            	}	
            	if ((op == 1)&&(cl == 0))
            	{
               		j = true;
            	}
	}
        if (j&&(op==cl))
        {
                 k = 1;
        }
        printf("%d", k);
        return 0;
}
