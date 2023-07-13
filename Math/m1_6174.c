#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOOPS 10
#define MIN 0
#define MAX 9999
#define ON 1
#define OFF 0

/*
	1. Take a four digit number as input.
	2. Number must include at least two different digits.
	3. Move digits descending order.
	4. Subtract with digits in ascending order.
	5. Repeat steps 3-4, but with the result from subtraction.
	6. After 3-4 steps you will magically end up with number 6174.
	- Note: A number smaller than 1000 will be filled with zeroes (ex. 0042).
*/

/*
BIGGEST
- Finds the biggest number of an array
- Sets it to zero
- Returns it
*/

int biggest(int *a)
{
	int i;
	int big;
	int pos;

	big = 0;
	i = -1;
	while (++i < 4)
	{
		if (a[i] > big)
		{
			big = a[i];
			pos = i;
		}
	}
	a[pos] = 0;
	return (big);
}

/*
DESCENDING
- Takes a number and returns it in descending order.
*/

int descending(int n)
{
	int i;
	int before[4];
	int after[4];

	if (n != 0)
	{
		while (n < 1000)
			n *= 10;
	}
	if (n == 0)
	{
		i = -1;
		while (++i < 4)
			before[i] = 0;
	}
	i = 4;
	while (--i >= 0)
	{
		before[i] = n % 10;
		n /= 10;
	}
	i = -1;
	while (++i < 4)
	{
		after[i] = biggest(before);
	}
	n = 0;
	i = -1;
	while (++i < 4)
	{
		n *= 10;
		n += after[i];
	}
	return (n);
}

/*
REVERSE
- Takes a number and returns it in ascending order.
*/

int reverse(int n)
{
	int i, r;

	r = 0;
	i = -1;
	while (++i < 4)
	{
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return (r);
}

/*
KAPREKAR_CONSTANT
- Takes a number and loops it until it reaches 6174.
*/

void kaprekar_constant(int n)
{
	int i;
	int a, d;

	i = -1;
	while (++i < LOOPS)
	{
		d = descending(n);
		printf("Number descending: %d\n", d);
		a = reverse(d);
		printf("Number ascending: %d\n", a);
		n = d - a;
		printf("Number after loop %d = %d\n", i, n);
		if (n == 6174)
		{
			printf("Number 6174 reached!\n");
			return ;
		}
	}
	printf("Number 6174 not reached!\n");
	return ;
}

/*
TEST_KAPREKAR_CONSTANT
- Takes a number and loops it until it reaches 6174.
- Returns the amount of iterations.
*/

int test_kaprekar_constant(int n)
{
	int i;
	int a, d, c;
	int print;

	print = ON;
	c = n;
	i = -1;
	if (n != 6174)
	{
		while (++i < LOOPS)
		{
			d = descending(c);
			a = reverse(d);
			c = d - a;
			if (c == 6174)
				break;
		}
	}
	if (print == ON)
	{
		if (c != 6174)
			printf("%4d [KO] iterations: %d\n", n, i + 1);
		else
			printf("%4d [OK] iterations: %d\n", n, i + 1);
	}
	return (i);
}

/*
MAIN
- Takes a number and loops it until it reaches 6174.
- Returns the amount of iterations.
*/

int main(int ac, char **av)
{
	int i;
	int a, d, n;
	float iterations;

	if (ac == 1)
	{
		iterations = 0;
		i = MIN - 1;
		while (++i < MAX)
			iterations += test_kaprekar_constant(i);
		printf("Average iterations: %.2f\n", iterations / (MAX - MIN + 1));
		return (0);
	}
	
	if (ac == 3)
	{
		int i_max;
		iterations = 0;
		n = atoi(av[1]);
		i_max = atoi(av[2]);
		i = -1;
		while (++i < i_max && i < MAX)
			iterations += test_kaprekar_constant(n + i);
		printf("Average iterations: %.2f\n", iterations / i_max);
		return (0);
	}

	if (ac != 2)
	{
		printf("Wrong amount of parameters!\n");
		return (0);
	}

	n = atoi(av[1]);
	if (n < MIN || MAX < n)
	{
		printf("Wrong size! Test ended!\n");
		return (0);
	}

	kaprekar_constant(n);

	return (0);
}