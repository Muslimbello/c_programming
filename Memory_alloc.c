#include <stdio.h>
#include <stdlib.h>
int *getAddressOf42()
{
	int value = 42;
	int *mal = malloc(sizeof(int *));
	int *address = &value;
	*mal = *address;
	return mal;
}

int main()
{
	int *result = getAddressOf42();

	// Accessing the value is safe
	printf("%d\n", *result);
	free(result);
	return 0;
}
