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
	instruction_t table[] = {{"pop", pop}, {"pall", pall}, {"pint", pint}
		, {"swap", swap}, {"add", add}, {"nop", nop}};
	char *token_copy = NULL,  *copy2 = NULL, *token2 = NULL;
	size_t i;

	if (token == NULL || *token == '\0')
		return;

	token_copy = malloc(sizeof(char) * (strlen(token) + 1));
	strcpy(token_copy, token);
	token2 = strtok(token_copy, " ");
	if (token_copy == NULL)
		return;
	if (strncmp(token2, "push", 4) == 0)
	{
		push(stack, token, line_number);
		free(token_copy);
		return;
	}
	copy2 = strtok(token, "$");
	if (copy2 == NULL)
	{
		free(token_copy);
		return;
	}
	for (i = 0; i < (sizeof(table) / sizeof(instruction_t)); i++)
	{
	if (strcmp(token2, table[i].opcode) == 0
			|| strcmp(copy2, table[i].opcode) == 0)
	{
		table[i].f(stack, line_number);
		free(token_copy);
		return;
	}
	}
	if (is_line_space(copy2) == 1)
		return;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

/**
 * is_line_space - checks if a line is only space
 * @line: is a pointer to a line
 *
 * Return: 1 if line is only space 0 if not
 */
int is_line_space(char *line)
{
	char *token = NULL;
	size_t i;
	int flag = 0;

	token = strtok(line, "$");
	for (i = 0; i < strlen(token); i++)
	{
		if (token[i] != ' ' && token[i] != '\n')
			flag = 1;
	}
	if (flag == 0)
		return (1);
	else
		return (0);

}
