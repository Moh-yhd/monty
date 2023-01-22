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
/**
 * pchar - prints the char value of the top of the stack
 * top elements of a stack by the second most top element
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (stack && head)
	{
		if (head->n >= 0 && head->n <= 127)
		{
			putchar(head->n);
			putchar('\n');
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string representation of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (head != NULL && stack != NULL)
	{
		while (head != NULL)
		{
			if (head->n == 0 || !(head->n >= 0 && head->n <= 127))
				break;
			putchar(head->n);
			head = head->next;
		}
	}
	putchar('\n');

}


/**
 * rotl - makes the second value of the stack the top one
 * and the first value of the stack the last one
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head, *bottom, *new;
	int data;

	head = *stack;
	if (head == NULL || head->next == NULL || stack == NULL)
		;
	else
	{
	while (head->next)
	{
		bottom = head->next;
		head = head->next;
	}

	head = *stack;
	data = head->n;
	*stack = head->next;
	(*stack)->prev = NULL;
	new = malloc(sizeof(stack_t));
	new->n = data;
	new->next = NULL;
	new->prev = bottom;
	bottom->next = new;
	free(head);
	}
}
/**
 * rotr - it rotates a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head, *bottom;

	head = *stack;
	if (head == NULL || stack == NULL)
		;
	else
	{
	while (head->next)
	{
		bottom = head->next;
		head = head->next;
	}

	head = *stack;

	bottom->next = head;
	*stack = head->next;
	head->next->prev = NULL;
	head->next = NULL;
	head->prev = bottom;
	}
}



