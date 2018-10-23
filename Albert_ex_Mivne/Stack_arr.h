#define MaxStack 10

typedef char stack_type;

typedef struct
{
	stack_type top;
	stack_type items [MaxStack];
}	stack;


void create_stack (stack *);

int push (stack_type, stack *);

int pop (stack *, stack_type *);

int stack_top (stack *, stack_type *);

int stack_is_empty (stack *);

int stack_is_full (stack *);
