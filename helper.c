#include "monty.h"

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
