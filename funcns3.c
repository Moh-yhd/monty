#include "monty.h"

/**
 * mod - computes the remainder of the division of the most
 * top elements of a stack by the second most top element
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	int rem;

	head = *stack;
	if (stack && head && head->next)
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}

		rem = head->next->n % head->n;
		temp = head;
		head = head->next;
		head->n = rem;
		head->prev = NULL;
		*stack = head;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
