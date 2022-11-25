#include <stdio.h>
#include <stdlib.h>

/*
	1. Take a four digit number as input.
	2. Number must include at least two different digits.
	3. Move digits descending order.
	4. Subtract with digits in ascending order.
	5. Repeat steps 3-4, but with the result from subtraction.
	6. After 3-4 steps you will magically end up with number 6174.
	- Note: A number smaller than 1000 will be filled with zeroes (ex. 0042).
*/

int biggest(int *a)
{
	int b[3];
	int i;

	b[0] = *a;
	i = 0;
	while (i < 3)
	{
		if (b[i + 1] > b[i])
			b[i] = b[i + 1];
		i++;
	}
	return (b[i]);
}

int descending(int n)
{
	int i;
	int a[3];
	int b[3];
	
	i = 3;
	printf("Test");
	while (i >= 0)
	{
		a[i] = n % 10;
		n /= 10;
		i--;
	}
	i = 0;
	while (i < 4)
	{
		b[i] = biggest(a);
		i++;
	}
	i = 1;
	while (i < 4)
	{
		n *= 10;
		n += b[i];
		i++;
	}
	return (n);
}

int main(int ac, char **av)
{
	int i;
	int n;

	if (ac != 2)
	{
		printf("Wrong amount of parameters!\n");
		return (0);
	}
	n = atoi(av[1]);
	if (n < 1000 || 9999 < n)
	{
		printf("Wrong size! Test ended!\n");
		return (0);
	}
	printf("\nNumber entered: %d\n\n", n);
	printf("Test");
	i = 0;
	n = descending(n);
	// while (i < 4)
	// {
	// 	printf("Test");
	// 	n = descending(n);
	// 	printf("n = '%d'\n", n);
	// 	i++;
	// }
	return (0);
}