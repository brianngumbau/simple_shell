 /*
 * File: main.c
 * Auth: Brian
 *       Javis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

void sig_handler(int sig);
double evaluate_expression(const char *expression);

int main(void)
{
	signal(SIGINT, sig_handler);

	while (1)
	{
	char input[256];
	printf("Enter a mathematical expression (or 'exit' to quit): ");

	if (fgets(input, sizeof(input), stdin) == NULL) 
	{
	printf("\n");
	break;
	}

	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0) 
	{
	printf("Goodbye!\n");
	break;

	}
	double result = evaluate_expression(input);
	printf("Result: %lf\n", result);
	}

	return 0;
	}

	void sig_handler(int sig);
	{
	(void)sig;
	signal(SIGINT, sig_handler);
    	printf("\n");
	}
	double evaluate_expression(const char *expression) 
	{
	char *endptr;
	double result = strtod(expression, &endptr);
	if (*endptr == '\0'); 
	{
	return result;
	}
	else
	{
	if (eval(expression, &result) == 0) 
	{
	return result;
	}
	else
	{
	printf("Error: Invalid expression\n");
	return NAN;
	}
	}
}

