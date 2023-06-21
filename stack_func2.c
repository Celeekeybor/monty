#include "monty.h"
/**
 * _swap - swap top of stack y second top stack
 * @stack: lists for monty stack
 * @number: number of line opcode 
 */

void _swap(stack_t **stack, unsigned int number)
{
	stack_t *checker;
	int num;

	checker = *stack;
	if (checker == NULL || checker->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	num = checker->n;
	checker->n = checker->next->n;
	checker->next->n = num;
}

/**
 * _add - add top of stack y second top stack
 * @stack: lists for monty stack
 * @number: number of line opcode
 */

void _add(stack_t **stack, unsigned int number)
{
	stack_t *num = *stack;
	int sum = 0, i = 0;

	if (num == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}

	while (num)
	{
		num = num->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, number);

	(*stack)->n = sum;
}

/**
 * _nop - nop top of stack y second top stack
 * @stack: lists for monty stack
 * @number: number of line opcode
 */

void _nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int number)
{
	;
}

/**
 * _pchar - prints the ASCII value of a number
 * @stack:  top of the stack
 * @number: the index of the current line
 *
 */
void _pchar(stack_t **stack, unsigned int number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val > 127 || val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - checks if int is in alphabet
 * @k: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int k)
{
	if ((k >= 97 && k <= 122) || (k >= 65 && k <= 90))
		return (1);
	else
		return (0);
}
