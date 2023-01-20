#include "monty.h"
#include <string.h>

/**
 * get_instruction - gets right instrutctions
 * @stack: is a pointer to the head pointer of the stack
 * @token: is pointer containing string in a single line
 * @line_number: is the number where token is located at
 *
 * Return: nothing
 */
void get_instruction(stack_t **stack, char *token, unsigned int line_number)
{
	instruction_t table[] = {{"pop", pop}, {"pall", pall}, {"pint", pint}};
	char *token_copy = NULL,  *copy2 = NULL;
	size_t i;

	if (token == NULL || *token == '\0')
		return;

	token_copy = malloc(sizeof(char) * (strlen(token) + 1));
	strcpy(token_copy, token);
	if (token_copy == NULL)
		return;
	if (strncmp(token_copy, "push", 4) == 0)
	{
		push(stack, token_copy, line_number);
		free(token_copy);
		return;
	}
	copy2 = strtok(token_copy, "$");
	if (copy2 == NULL)
	{
		free(token_copy);
		return;
	}
	for (i = 0; i < (sizeof(table) / sizeof(instruction_t)); i++)
	{
	if (strcmp(token_copy, table[i].opcode) == 0
			|| strcmp(copy2, table[i].opcode) == 0)
	{
		table[i].f(stack, line_number);
		free(token_copy);
		return;
	}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
