#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
/**
 * main - main function of the monty program
 * @argc: is the number of arguments passed to the program
 * @argv: is a pointer to the strings passed as argument
 *
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	int line_number = 0;
	char *token = NULL;
	char instructions[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(instructions, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		token = strtok(instructions, "\n\t\r");
		if (token == NULL)
			continue;
		get_instruction(&stack, token, line_number);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
