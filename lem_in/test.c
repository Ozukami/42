#include <stdio.h>

int	main(void)
{	
	int ants = 40;
	int way1 = 2;
	int way2 = 3;
	int way3 = 4;
	int total = 0;
	int turn = 0;

	int j = 0;
	int k = 0;
	int i = 0;
	
	while (total <= ants)
	{
		turn++;
		if (turn == 1)
		{
			j++;
			k++;
			i++;
			total = total + 3;
		}
		if (turn >= way1 && turn != 1)
		{
			j++;
			total = total + 1;
			if (total == ants)
			{
				printf("WAY 1 > %d ANTS / WAY2 > %d ANTS / WAY3 > %d = %d\n", j, k, i, total);
				return (0);
			}
		}
		if (turn >= way2 && turn != 1)
		{
			k++;
			total = total + 1;
			if (total == ants)
			{
				printf("WAY 1 > %d ANTS / WAY2 > %d ANTS / WAY3 > %d = %d\n", j, k, i, total);
				return (0);
			}
		}
		if (turn >= way3 && turn != 1)
		{
			i++;
			total = total + 1;
			if (total == ants)
			{
				printf("WAY 1 > %d ANTS / WAY2 > %d ANTS / WAY3 > %d = %d\n", j, k, i, total);
				return (0);
			}
		}
		printf("TURN %d\n", turn);
	}
	return (0);
}
