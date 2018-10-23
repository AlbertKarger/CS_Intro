typedef char stack_type;

typedef struct stack_element
{
	stack_type data;
    struct stack_element *link;
}	stack_element;

typedef struct result
{
	stack_type op1;
	stack_type op2;
	stack_type oper;
	stack_type answer;
}result;

typedef stack_element *stack;

void create_stack (stack *);

int push (stack_type, stack *);

int pop (stack *, stack_type *);

int stack_top (stack *, stack_type *);

int stack_is_empty (stack *);

int stack_is_full (stack *);