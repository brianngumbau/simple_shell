#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_vowels(const char *str);
/**
 * main - main function
 *
 * Return: 0
 */
int main(void)
{
	char input[256];

	printf("Enter a string: ");
	fgets(input, sizeof(input), stdin);

	input[strcspn(input, "\n")] = '\0';

	int vowel_count = count_vowels(input);

	printf("Number of vowels: %d\n", vowel_count);

	return (0);
}
/**
 * count_vowels - counts the number of vowels
 * @str: string for vowels to be counted
 * Return: number of vowels
 */
int count_vowels(const char *str)
{
	int count = 0;
	const char *vowels = "aeiouAEIOU";

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (strchr(vowels, str[i]) != NULL)
		{
			count++;
		}
	}

	return (count);
}

