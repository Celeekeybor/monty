#include "monty.h"

/**
 * _pstr - mod top of stack y 
 * @stack: point to the lists in monty stack
 * @number: number of line opcode 
 */
void _pstr(stack_t **stack, unsigned int number)
{
	stack_t *tmp = *stack;
	int num = 0;

	(void)number;


	while (tmp)
	{
		num = tmp->n;
		if (num == 0 || _isalpha(num) == 0)
			break;
		putchar(num);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * _rotl - mod top of stack y
 * @stack: lists for monty stack
 * @number: number of line opcode 
 */
void _rotl(stack_t **stack, unsigned int number)
{
	stack_t *runner = *stack;


	int val = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	val = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = val;
}

/**
 * _rotr - mod top of stack y
 * @stack: lists for monty stack
 * @number: number of line opcode 
 */
void _rotr(stack_t **stack, unsigned int number)
{
	stack_t *checker = *stack;

	int val = 0;

	if (!number || !stack || !*stack || !(*stack)->next)
		return;

	while (checker->next)
		checker = checker->next;

	val = checker->n;

	while (checker->prev)
	{
		checker = checker->prev;
		checker->next->n = checker->n;
	}

	checker->n = val;
}
