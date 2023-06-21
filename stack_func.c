#include "monty.h"
/**
 * _push - push into a pile
 * @pile: monty list
 * @dash_no: number of opcode
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
 * @pile: pointer to linked list pile
 * @dash_no: number of line opcode occurs on
 */
void _pall(stack_t **pile, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *runner;

	runner = *pile;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
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
	stack_t *runner;

	runner = *pile;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, pile empty\n", dash_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * _pop - remove element a list
 *@pile: pointer to first node
 *@dash_no: integer
 *Return: void
 */
void _pop(stack_t **pile, unsigned int dash_no)
{
	stack_t *nodo = *pile;

	if (pile == NULL || *pile == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty pile\n", dash_no);
		exit(EXIT_FAILURE);
	}
	*pile = nodo->next;
	if (*pile != NULL)
		(*pile)->prev = NULL;
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
