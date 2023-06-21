#include "monty.h"
/**
 * _push - push int to a pile
 * @pile: linked lists for monty pile
 * @dash_no: number of line opcode occurs on
 */
void _push(stack_t **pile, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *top;
	(void)dash_no;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.push_arg;
	top->next = *pile;
	top->prev = NULL;
	if (*pile != NULL)
		(*pile)->prev = top;
	*pile = top;
}

/**
 * _pall - print all function
 * @pile: pointer to  pile linked list
 * @dash_no: number of line opcode 
 */
void _pall(stack_t **pile, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *checker;

	checker = *pile;
	while (checker != NULL)
	{
		printf("%d\n", checker->n);
		checker = checker->next;
	}
}

/**
 * _pint - print int a top of pile
 * @pile: pointer to linked list pile
 * @dash_no: number of line opcode occurs on
 *
 */
void _pint(stack_t **pile, unsigned int dash_no)
{
	stack_t *checker;

	checker = *pile;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, pile empty\n", dash_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element of a list
 *@pile: pointer to first node
 *@dash_no: integer
 *Return: zero
 */
void _pop(stack_t **pile, unsigned int dash_no)
{
	stack_t *node = *pile;

	if (pile == NULL || *pile == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty pile\n", dash_no);
		exit(EXIT_FAILURE);
	}
	*pile = node->next;
	if (*pile != NULL)
		(*pile)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - free a list
 * @head: first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *cele;

	while (head != NULL)
	{
		cele = head->next;
		free(head);
		head = cele;
	}
}
