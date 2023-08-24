#ifndef MONTY_H
#define MONTY_H

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
*struct globals- global files to be used in functions
*@lifo: stack or queue
*@arg:2nd parameter inside cont
*@buffer: text input
*@head: doubly linked list head
*@cont: current line
*@fd: file descripter
*/
typedef struct globals
{
	int lifo;
	char *arg, *buffer;
	stack_t *head;
	unsigned int cont;
	FILE *fd;
} global_t;


/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

void _div(stack_t ** doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _strcmp(char *s1, char *s2);
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);

void _queue(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);

void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

void _rot1(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);

void _push(stack_t **doubly, unsigned int cline);
void _pall(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);

void free_vglo(void);


#endif
