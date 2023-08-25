#include "monty.h"

/**
*_push - pushes an element to the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _push(stack_t **doubly, unsigned int cline)
{
	int n , j;

	if (!vglo.arg)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
*_pall- print all values on the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _pall(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			fprintf(stderr, "L%u: ", cline);
			fprintf(stderr, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
*_pint - prints value  at top of the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly  == NULL)
	{
		fprintf(stderr, "L%u: ", cline);
		fprintf(stderr, "can't print, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}


/**
*_pop - removes the top element of stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}


/**
*_swap- swaps the top 2 element of the stack
*@doubly: head of linked list
*@cline: line number
*
*/
void _swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
