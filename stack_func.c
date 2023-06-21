#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists
 * @line_number: number of line opcode
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

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
 * @stack: point to the linked list
 * @line_number: number of line opcode 
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
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
 * @stack: point to the linked list stack
 * @line_number: number of line opcode 
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *checker;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
