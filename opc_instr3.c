#include "monty.h"

/**
*_div - divides 2nd element by top element of the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _div(stack_t ** doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
*_mul- multiplies top element to 2nd top element of the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}


/**
*_mod- compates the rest of the division of 2nd element by top
*@doubly: head of linked list
*@cline: line number
*
*/
void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}


/**
*_pchar- prints the char value of 1st element
*@doubly: head the linked list
*@cline: line number
*
*/
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}


/**
*_pstr - prints string of stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}
