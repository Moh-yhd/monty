#include "monty.h"

/**
 * push - adds element at the top of the stack
 * @stack: is pointer to the head of the stack
 * @token: is pointer to a string containing the push intstruction
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void push(stack_t **stack, char *token, __attribute__((unused))
		unsigned int line_number)
{
	stack_t *temp, *head;
	int data;
	char *endptr, *token2 = NULL;
	char delim[] = " \\$";

	token2 = strtok(token, delim);
	token2 = strtok(NULL, delim);
	data = (int) strtol(token2, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	head = *stack;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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

void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
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
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

}

/**
 * pall - displays elements of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */


void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
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

/**
 * pint - prints the top element of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number whre token is located
 *
 * Return: nothing
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (head != NULL && stack != NULL)
	{
		printf("%d\n", head->n);
	}

	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees a double linked list
 * @stack: is a pointer to the head of the list
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
