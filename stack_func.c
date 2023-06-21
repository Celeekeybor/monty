#include "monty.h"
/**
 * _push - push int to a dash
 * @dash: linked lists for monty dash
 * @dash_no: number of line opcode occurs on
 */
void _push(stack_t **dash, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *upper;
	(void)dash_no;

	upper = malloc(sizeof(stack_t));
	if (upper == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	upper->n = var_global.push_arg;
	upper->next = *dash;
	upper->prev = NULL;
	if (*dash != NULL)
		(*dash)->prev = upper;
	*dash = upper;
}

/**
 * _pall - print all function
 * @dash: point to linked list 
 * @dash_no: number of line opcode 
 */
void _pall(stack_t **dash, __attribute__ ((unused))unsigned int dash_no)
{
	stack_t *checker;

	checker = *dash;
	while (checker != NULL)
	{
		printf("%d\n", checker->n);
		checker = checker->next;
	}
}

/**
 * _pint - print int a upper of dash
 * @dash: point to linked list
 * @dash_no: number of line opcode
 *
 */
void _pint(stack_t **dash, unsigned int dash_no)
{
	stack_t *checker;

	checker = *dash;
	if (checker == NULL)
	{
		fprintf(stderr, "L%d: can't pint, dash empty\n", dash_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", checker->n);
}

/**
 * _pop - remove element a list
 *@dash: pointer to first node
 *@dash_no: integer
 *Return: void
 */
void _pop(stack_t **dash, unsigned int dash_no)
{
	stack_t *node = *dash;

	if (dash == NULL || *dash == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty dash\n", dash_no);
		exit(EXIT_FAILURE);
	}
	*dash = node->next;
	if (*dash != NULL)
		(*dash)->prev = NULL;
	free(node);
}

/**
 * free_dlistint - free a list
 * @top: pointer to first node
 *
 */
void free_dlistint(stack_t *top)
{
	stack_t *tempo;

	while (top != NULL)
	{
		tempo = top->next;
		free(top);
		top = tempo;
	}
}
