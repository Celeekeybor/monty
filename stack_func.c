#include "monty.h"
/**
 * _push - push  to a pile
 * @pile: monty pile linked list
 * @queue_no: number of line opcode 
 */
void _push(stack_t **pile, __attribute__ ((unused))unsigned int queue_no)
{
	stack_t *up;
	(void)queue_no;

	up = malloc(sizeof(stack_t));
	if (up == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	up->n = var_global.push_arg;
	up->next = *pile;
	up->prev = NULL;
	if (*pile != NULL)
		(*pile)->prev = up;
	*pile = up;
}

/**
 * _pall - print all function
 * @pile: pointer to linked list pile
 * @queue_no: number of line opcode 
 */
void _pall(stack_t **pile, __attribute__ ((unused))unsigned int queue_no)
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
 * _pint - print int a up of pile
 * @pile: point to linked list pile
 * @queue_no: number of line opcode 
 *
 */
void _pint(stack_t **pile, unsigned int queue_no)
{
	stack_t *checker;

	checker = *pile;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, pile empty\n", queue_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element a list
 *@pile: point to first node
 *@queue_no: integer
 *Return: zero
 */
void _pop(stack_t **pile, unsigned int queue_no)
{
	stack_t *node = *pile;

	if (pile == NULL || *pile == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty pile\n", queue_no);
		exit(EXIT_FAILURE);
	}
	*pile = node->next;
	if (*pile != NULL)
		(*pile)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - free a list
 * @head: point to the first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
