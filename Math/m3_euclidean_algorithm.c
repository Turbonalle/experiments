#include <stdlib.h>
#include <stdio.h>

// Enter two numbers. The algorithm will find the gcd of them.

int euclids_algorithm(int dividend, int divisor)
{
	if (divisor == 0) return (dividend);
	int remainder = dividend % divisor;
	printf("%d\t%d\t%d\n", dividend, divisor, remainder);
	return (euclids_algorithm(divisor, remainder));
}

int main(int ac, char *av[])
{
	printf("divid\tdivis\tremain\n");
	if (ac == 3)
		printf("GCF = %d\n", euclids_algorithm(atoi(av[1]), atoi(av[2])));
	return (0);
}