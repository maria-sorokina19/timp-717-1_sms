#include <stdio.h>

int main(void) {
	int n, x, i;
	int k = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &x);
		if (x>0) k++;
	}
	printf("%d", k);
	return 0;
}
