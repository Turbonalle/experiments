#include <stdio.h>	// printf() scanf()
#include <stdlib.h>	// atoi()
#include <math.h>	// floor()
#define WHITE "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

float	get_distance()
{
	char	meters[20];

	printf("Please enter distance (m): ");
	scanf("%20s", meters);
	return (atof(meters));
}

float	get_time()
{
	char	time[20];
	float	minutes;
	float	seconds;
	int		i;

	printf("Please enter time (mm.ss): ");
	scanf("%20s", time);

	minutes = 0;
	i = 0;
	while (time[i] && time[i] != '.')
	{
		minutes = (minutes * 10) + time[i] - '0';
		i++;
	}

	if (time[i] == '.')
		i++;
	
	seconds = 0;
	while (time[i])
	{
		seconds = seconds * 10;
		seconds = seconds + time[i]- '0';
		i++;
	}
	seconds += (minutes * 60);
	return (seconds);
}

float	get_speed()
{
	char	speed[20];

	printf("Please enter speed (km/h): ");
	scanf("%20s", speed);
	return (atof(speed));
}

void	calc_distance()
{
	float	t;
	float	s;
	float	distance;

	printf(GREEN"----------------------------------\n"WHITE);
	t = get_time();
	s = get_speed();
	printf(CYAN);
	printf("\nDistance:\n");
	distance = (s / 3.6) * t;
	printf("%.0f m\n", distance);
	printf(WHITE);
}

void	calc_time()
{
	float	d;
	float	s;
	float	minutes;
	float	seconds;

	printf(GREEN"----------------------------------\n"WHITE);
	d = get_distance();
	s = get_speed();
	printf(CYAN);
	printf("\nTime:\n");
	seconds = d / (s / 3.6);
	minutes = floor(seconds / 60);
	seconds = seconds - (minutes * 60);
	printf("%.0f'%.0f\"\n", minutes, seconds);
	printf(WHITE);
}

void	calc_speed()
{
	float	d;
	float	t;
	int		minutes;
	float	seconds;


	printf(GREEN"----------------------------------\n"WHITE);
	d = get_distance();
	t = get_time();
	printf(CYAN);
	printf("\nSpeed:\n");
	printf("%.2f m/s\n", d / t);
	printf("%.2f km/h\n", (d / 1000) / (t / 60 / 60));
	minutes = floor((t / 60) / (d / 1000));
	seconds = ((t / 60) / (d / 1000) - minutes) * 60;
	printf("%d'%.0f\" min/km\n", minutes, seconds);
	printf(WHITE);
}

void	handle_input(int input)
{
	if (input == 1)
		calc_distance();
	else if (input == 2)
		calc_time();
	else if (input == 3)
		calc_speed();
}

int get_input(void)
{
	char	input[1];
	char	arr[3] = { 'd', 't', 's' };
	int		choice;
	int		i;

	printf(GREEN"----------------------------------\n"WHITE);
	printf("\nPlease enter the index of what you'd like me to calculate.\n\n");
	printf("1. Distance\n");
	printf("2. Time\n");
	printf("3. Speed\n");
	printf("0. Exit program\n\n");
	scanf("%1s", input);
	printf("\n");
	choice = atoi(input);
	if (choice == 1 || choice == 2 || choice == 3)
		return (choice);
	i = -1;
	while (++i < 3)
		if (input[0] == arr[i])
			return (i + 1);
	return (0);
}

int main(void)
{
	int	input;
	
	printf(GREEN"----------------------------------\n");
	printf("\tRUNNING CALCULATOR\n");
	// printf("----------------------------------\n"WHITE);
	input = get_input();
	while (input != 0)
	{
		handle_input(input);
		input = get_input();
	}
	return (0);
}