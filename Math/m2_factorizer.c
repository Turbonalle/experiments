#include <stdio.h>
#include <stdlib.h>

void factorize(int n)
{
	int i;
	
	i = 2;
	if (n > 0)
	{
		if (n < 2)
			printf("%d", n);
		else
		{
			while ((i * i) <= n)
			{
				while (n % i == 0)
				{
					printf("%d ", i);
					n /= i;
				}
				i++;
			}
			if (n != 1)
				printf("%d", n);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	factorize(atoi(av[1]));
	printf("\n");
	return (0);
}