
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TEST	if (1 != 0) {printf("LOL\n");}

int		main(void)
{
	int	test = 1;
	TEST
	printf("Bonjour [%1k] !\n", 1);
	return (1);
}
