#include "monty.h"

/**
 * _sub - replace top of stack y 
 * @pile: pointer to lists monty pile
 * @dash_no: number of dash opcode occurs on
 */
void _sub(stack_t **pile, unsigned int dash_no)
{
	stack_t *tmp = *pile;
	int replace = 0, val = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't replace, pile too short\n", dash_no);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		val++;
	}

	if (pile == NULL || (*pile)->next == NULL || val <= 1)
	{
		fprintf(stderr, "L%d: can't replace, pile too short\n", dash_no);
		exit(EXIT_FAILURE);
	}
	replace = (*pile)->next->n - (*pile)->n;
	_pop(pile, dash_no);

	(*pile)->n = replace;
}

/**
 * _mul - mul top of pile y second top pile
 * @pile: pointer to lists for monty pile
 * @dash_no: number of line opcode occurs on
 */
void _mul(stack_t **pile, unsigned int dash_no)
{
	int elem;

	if (*pile == NULL || (*pile)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, pile too short\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*pile);
		exit(EXIT_FAILURE);
	}
	else
	{
		elem = (*pile)->n;
		_pop(pile, dash_no);
		(*pile)->n *= elem;
	}
}

/**
 * _div - split top of pile y second top pile
 * @pile: pointer to lists for monty pile
 * @dash_no: number of line opcode occurs on
 */
void _div(stack_t **pile, unsigned int dash_no)
{
	int split = 0;

	if (*pile == NULL || (*pile)->next == NULL)
	{
		fprintf(stderr, "L%u: can't split, pile too short\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*pile);
		exit(EXIT_FAILURE);
	}
	else if ((*pile)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*pile);
		exit(EXIT_FAILURE);
	}
	else
	{
		split = (*pile)->n;
		_pop(pile, dash_no);
		(*pile)->n /= split;
	}
}

/**
 * _mod - add top of pile y second top pile
 * @pile: pointer to lists for monty pile
 * @dash_no: number of dash opcode
 */
void _mod(stack_t **pile, unsigned int dash_no)
{
	int add = 0;

	if (*pile == NULL || (*pile)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, pile too short\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*pile);
		exit(EXIT_FAILURE);
	}
	else if ((*pile)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", dash_no);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*pile);
		exit(EXIT_FAILURE);
	}
	else
	{
		add = (*stack)->n;
		_pop(stack, dash_no);
		(*stack)->n %= add;
	}
}
