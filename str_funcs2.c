#include <stdio.h>

int custom_strlen(const char *s);
int custom_strcmp(const char *s1, const char *s2);
void custom_strcat(char *dest, const char *src);
int custom_sum(int a, int b);
/**
 * custom_strlen - calculates the number of characters in a string
 * @s: the string
 * Return: length of string
 */
int custom_strlen(const char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return (length);
}
/**
 * custom_strcmp - compares string arguments
 * @s1: first argument
 * @s2: second argument
 * Return: s1 - s2
 */
int custom_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
/**
 * custom_strcat - concanates two strings
 * @dest: string
 * @src: string
 * Return: empty
 */
void custom_strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
}
/**
 * custom_sum - returns the sum of 2 numbers
 * @a: number to summed
 * @b: number to be summed
 * Return: sum
 */
int custom_sum(int a, int b)
{
	return (a + b);
}
/**
 * main - main function
 *
 * Return: 0
 */
int main(void)
{
	const char *str1 = "Hello, ";
	const char *str2 = "world!";
	char result[100];
	int num1 = 10;
	int num2 = 20;

	printf("Length of str1: %d\n", custom_strlen(str1));

	printf("Comparison result: %d\n", custom_strcmp(str1, str2));

	custom_strcat(result, str1);
	custom_strcat(result, str2);
	printf("Concatenated string: %s\n", result);

	printf("Sum of %d and %d: %d\n", num1, num2, custom_sum(num1, num2));

	return (0);
}
