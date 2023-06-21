#include "monty.h"
/**
 * _push - push into the pile
 * @pile: monty list
 * @count_no: number of opcode pile
 */
void _push(stack_t **pile, __attribute__ ((unused))unsigned int count_no)
{
	stack_t *up;
	(void)count_no;

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
 * @pile: monty list
 * @count_no: number of opcode pile
 */
void _pall(stack_t **pile, __attribute__ ((unused))unsigned int count_no)
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
 * @pile: pointer to linked list pile
 * @count_no: number of opcode pile
 *
 */
void _pint(stack_t **pile, unsigned int count_no)
{
	stack_t *checker;

	checker = *pile;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, pile empty\n", count_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element a list
 *@pile: pointer to first node
 *@count_no: number of opcode pile
 *Return: zero
 */
void _pop(stack_t **pile, unsigned int count_no)
{
	stack_t *node = *pile;

	if (pile == NULL || *pile == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty pile\n", count_no);
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
	stack_t *value;

	while (head != NULL)
	{
		value = head->next;
		free(head);
		head = value;
	}
}
