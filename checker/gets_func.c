#include "monty.h"

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
	instruction_t table[] = {{"pop", pop}, {"pall", pall}};
	char *token_copy = NULL, *token2 = NULL, *copy2 = NULL;
	int i;

	if (token != NULL)
	{
	token_copy = malloc(sizeof(char) * strlen(token));
	strcpy(token_copy, token);
	token2 = strtok(token_copy, " ");
	if (strcmp(token2, "push") == 0)
	{
		push(stack, token, line_number);
		return;
	}
	if (token2 != NULL)
	{
	copy2 = malloc(sizeof(char) * strlen(token2));
	strcpy(copy2, token2);
	}
	if (strtok(copy2, "$") == NULL)
		return;
	for (i = 0; i < (sizeof(table) / sizeof(instruction_t)); i++)
	{
	if (strcmp(token2, table[i].opcode) == 0 ||
			strcmp(strtok(copy2, "$"), table[i].opcode) == 0)
	{
		table[i].f(stack, line_number);
		return;
	}
	}
	}
	if (is_line_space(token) == 1)
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
	int i;
	int flag = 0;

	token = strtok(line, "$");
	for (i = 0; i < strlen(token); i++)
	{
		if (token[i] != ' ' && token[i] != '\n')
			flag = 1;
	}
	if (flag == 0)
		return (1);
	else if (flag == 1)
		return (0);
}

