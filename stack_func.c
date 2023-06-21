#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @dash_no: number of opcode
 */
void _push(stack_t **stack, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *head;
	(void)dash_no;

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
    {
		(*stack)->prev = head;
    }
	*stack = head;
}
/**
 * _pall - print all function
 * @stack: pointer to stack linked list
 * @dash_no: number of dash opcode
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int dash_no)
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
 * @dash_no: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int dash_no)
{
	stack_t *checker;

	checker = *stack;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", dash_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element from list
 *@stack: point to first node
 *@dash_no: integer
 *Return: zero
 */
void _pop(stack_t **stack, unsigned int dash_no)
{
	stack_t *node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", dash_no);
		exit(EXIT_FAILURE);
	}
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - free a list
 * @head: point to first node
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
