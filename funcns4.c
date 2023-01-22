#include "monty.h"

/**
 * _stack - rotates a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void _stack(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head, *bottom;
	int data;
	unsigned int i, count;

	head = *stack;
	if (head && stack)
	{
	count = 1;
	while (head->next)
	{
		count++;
		bottom = head->next;
		head = head->next;
	}

	head = *stack;
	for (i = 1; i <= count / 2; i++)
	{
		data = head->n;
		head->n = bottom->n;
		bottom->n = data;
		head = head->next;
		bottom = bottom->prev;
	}
	}
}

