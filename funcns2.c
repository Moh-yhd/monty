#include "monty.h"

/**
 * add - adds the top top two elements of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	int sum;

	head = *stack;
	if (stack && head && head->next)
	{
		sum = head->n + head->next->n;
		temp = head;
		head = head->next;
		head->n = sum;
		head->prev = NULL;
		*stack = head;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop- does nothing
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
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
