#include <string.h>
#include <stdio.h>
#include <ctype.h>

char nochartest(char *str, char ch, int tries)
{
	if (strchr(str, ch) == NULL)
	{
		printf("There is no such character in the sentence. Try again!\n");
		scanf (" %c", &ch);
	}
	return (ch);
}

int main(int ac, char **av)
{
	char *str = "Bananas are good for hungry monkeys!";
	char ch;
	char *ptr;
	char *arr[] = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth"};
	int i = 0;
	int tries = 3;

	printf ("Original string: \"%s\" \n ", str);
	printf ("Please enter a character you want to search in the string: "); 
	scanf (" %c", &ch);
	
	if (!isalpha(ch))
	{
		printf("That's not a letter, stupid!\n");
	}
	else if (strchr(str, ch) == NULL)
	{
		while (tries > 0 && strchr(str, ch) == NULL)
		{
			tries--;
			if (tries == 0)
			{
				printf("You don't deserve any more tries...\n");
			}
			else
			{
				ch = nochartest(str, ch, tries);
			}
			
		}	
	}

	ptr = strchr(str, ch);

	while (ptr)
	{
		printf("%s '%c' is at: '%s'\n", arr[i], ch, ptr);
		ptr = strchr(ptr + 1, ch);
		i++;
	}
	
	return (0);
}