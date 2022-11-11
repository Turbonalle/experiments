#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 100 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void print_slowly(char *str)
{
	int i = 0;

	while (str[i])
	{
		delay(1);
		printf("%c", str[i]);
		i++;
	}
}

static long int	int_length(long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*make_space_add_null(int n, int length)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * (length + 2));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (length + 1));
		if (!str)
			return (NULL);
		str[length] = '\0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;
	int		sign;

	length = (long)(int_length(n));
	str = make_space_add_null(n, length);
	if (!str)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	length--;
	while (n != 0)
	{
		str[length] = (n % 10) * sign + '0';
		n = n / 10;
		length--;
	}
	return (str);
}

int main()
{
	print_slowly("What's your name?\n");
	char name[100];
	scanf("%99s", name);
	print_slowly("Hi ");
	print_slowly(name);
	print_slowly("!\nHow old are you?\n");
	char age[100];
	scanf("%99s", age);
	int rest = 100 - atoi(age);
	print_slowly("You are ");
	print_slowly(age);
	print_slowly(" years old.\nIn ");
	print_slowly(ft_itoa(rest));
	print_slowly(" years you'll be 100!");
	return (0);
}