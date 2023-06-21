#include "monty.h"

/**
 * _sub - val top of pile y second top pile
 * @pile: pointer to lists for monty pile
 * @dash_no: number of line opcode occurs on
 */
void _sub(stack_t **pile, unsigned int dash_no)
{
	stack_t *tmp = *pile;
	int val = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't val, pile too short\n", dash_no);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (pile == NULL || (*pile)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: can't val, pile too short\n", dash_no);
		exit(EXIT_FAILURE);
	}
	val = (*pile)->next->n - (*pile)->n;
	_pop(pile, dash_no);

	(*pile)->n = val;
}

/**
 * _mul - mul top of pile y 
 * @pile: pointer to monty pile
 * @dash_no: number of line opcode 
 */
void _mul(stack_t **pile, unsigned int dash_no)
{
	int num;

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
		num = (*pile)->n;
		_pop(pile, dash_no);
		(*pile)->n *= num;
	}
}

/**
 * _div - cee top of pile y 
 * @pile: point to monty pile
 * @dash_no: number of dash code
 */
void _div(stack_t **pile, unsigned int dash_no)
{
	int cee = 0;

	if (*pile == NULL || (*pile)->next == NULL)
	{
		fprintf(stderr, "L%u: can't cee, pile too short\n", dash_no);
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
		cee = (*pile)->n;
		_pop(pile, dash_no);
		(*pile)->n /= cee;
	}
}

/**
 * _mod - rue top of pile y 
 * @pile: point to monty pile
 * @dash_no: number of dashcode
 */
void _mod(stack_t **pile, unsigned int dash_no)
{
	int rue = 0;

	if (*pile == NULL || (*pile)->next == NULL)
	{
		fprintf(stderr, "L%u: can't rue, pile too short\n", dash_no);
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
		rue = (*pile)->n;
		_pop(pile, dash_no);
		(*pile)->n %= rue;
	}
}
