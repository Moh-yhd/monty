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
 * sub - substracts the top most element of
 * the stack from the second top element
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	int dif;

	head = *stack;
	if (stack && head && head->next)
	{
		dif = head->next->n - head->n;
		temp = head;
		head = head->next;
		head->n = dif;
		head->prev = NULL;
		*stack = head;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - divided the second most element of
 * the stack  by top element of the stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	int qot;

	head = *stack;
	if (stack && head && head->next)
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}

		qot = head->next->n / head->n;
		temp = head;
		head = head->next;
		head->n = qot;
		head->prev = NULL;
		*stack = head;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiplies the first two elements of a stack
 * @stack: is pointer to the head of the stack
 * @line_number: is the line number where token is located
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	int prod;

	head = *stack;
	if (stack && head && head->next)
	{
		prod = head->next->n * head->n;
		temp = head;
		head = head->next;
		head->n = prod;
		head->prev = NULL;
		*stack = head;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
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


