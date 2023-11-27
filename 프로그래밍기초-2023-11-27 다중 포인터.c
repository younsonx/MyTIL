#include <stdio.h>

int main()
{
	int i = 100;
	int* pi = &i;
	int** dpi = &pi;

	printf("%p %p %p\n", &i, pi, *dpi);

	*pi = i + 30;
	printf("%d %d %d \n", i, *pi, **dpi);

	**dpi = *pi + 30;
	printf("%d %d %d \n", i, *pi, **dpi);

	return 0;
}
