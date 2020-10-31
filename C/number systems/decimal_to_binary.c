#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	char buffer[80];
	char *pointer;

	while(1)
	{
		printf("enter a positive number");

		if(!fgets(buffer, sizeof(buffer) - 1, stdin))
			break;

		if(index(buffer, '\n') != NULL)
			*index(buffer, '\n') = '\0';

		if(0 == buffer[0])
			break;

		unsigned long inp = atol(buffer);
		unsigned long int j = inp;

		*(pointer = buffer + sizeof(buffer) - 1) = '\0';

		do 
		{
			*--pointer = (j & 1 ? '1' : '0');
		}
		while((j >>= 1) > 0);

		printf("number: %lu => %s\n", inp, pointer);
	}

	printf("\n");

	return 0;
}
