#include "monty.h"

/**
 * push - adds element at the top of the stack
 * @stack: is pointer to the head of the stack
 * @token: is pointer to a string containing the push intstruction
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void push(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp, *head;
	int data;
	char *endptr, *token2 = NULL;
	char delim[] = " \\$";

	token2 = strtok(token, delim);
	token2 = strtok(NULL, delim);

	data = (int) strtol(token2, &endptr, 10);

	head = *stack;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	temp->n = data;
	temp->next = NULL;
	temp->prev = NULL;

	if (head == NULL)
	{
		*stack = temp;
	}
	else
	{
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}

}

/**
 * pop - removes an element at the top of the stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *head;

	head = *stack;
	if (stack != NULL && head != NULL)
	{
		temp = head;
		head = head->next;
		if (head->next != NULL)
		{
			head->next->prev = NULL;
		}
		free(temp);
	}

}

/**
 * pall - displays elements of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (head != NULL && stack != NULL)
	{
		while (head != NULL)
		{
			printf("%d\n", head->n);
			head = head->next;
		}
	}
}

