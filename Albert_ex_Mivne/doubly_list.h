typedef char list_type;

typedef struct node 
{
   list_type value;	
   struct node *next;
   struct node *prev;
}node;

typedef struct list
{
	node *head;
	node *tail;
}list;

void init_list(list *lst);

int isEmpty(list *lst);

int length(list *lst);

void insertFirst(list *lst, list_type value);

void insertLast(list *lst, list_type value);

int deleteFirst(list *lst);

int deleteLast(list *lst);

int deleteLink(list *lst, int idx);

int insertAfter(list *lst, list_type value, int idx);

int insertBefore(list *lst, list_type value, int idx);