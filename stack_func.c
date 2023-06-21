#include "monty.h"
/**
 * _push - push  to a stack
 * @stack: lists for monty stack
 * @number: number of line opcode 
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int number)
{
	stack_t *head;
	(void)number;

	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	head->n = var_global.push_arg;
	head->next = *stack;
	head->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = head;
	*stack = head;
}

/**
 * _pall - print all function
 * @stack: linked list stack
 * @number: number of line opcode
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int number)
{
	stack_t *checker;

	checker = *stack;
	while (checker != NULL)
	{
		printf("%d\n", checker->n);
		checker = checker->next;
	}
}

/**
 * _pint - print int a head of stack
 * @stack: pointer to linked list stack
 * @number: number of line opcode
 *
 */
void _pint(stack_t **stack, unsigned int number)
{
	stack_t *checker;

	checker = *stack;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element a list
 *@stack: first node
 *@number: integer
 *Return: zero
 */
void _pop(stack_t **stack, unsigned int number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a list
 * @head:  first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *value;

	while (head != NULL)
	{
		value = head->next;
		free(head);
		head = value;
	}
}
