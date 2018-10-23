typedef unsigned int posInt;

typedef struct polynomial
{
	float coe; //coefficient , requested a real number which can be a fraction as well, this would be indiacted via the print function, if indeed a fraction will be used, the print function will need to be modified.
	posInt exp; //Exponential

}polynomial;

typedef struct Node
{
	polynomial data;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct listPoly
{
	Node *head;
	Node *tail;
}listPoly;

void initListPoly(listPoly *lst);

void listPrintPoly(listPoly *list);

void insertLastPoly(listPoly *lst, float coe, posInt exp);

int isEmptyPoly(listPoly *lst);

int insertAfterPoly(listPoly *lst, float coe, posInt exp, int idx);

int lengthPoly(listPoly *lst);

void insertFirstPoly(listPoly *lst, float coe, posInt exp);

listPoly polyAdd(listPoly *poly1, listPoly *poly2);

void polyInsert(listPoly *poly, float coe, posInt exp);

listPoly polySubtract(listPoly *poly1, listPoly *poly2); //Decreasing 2 polys

void polyInsertSubtract(listPoly *poly, float coe, posInt exp); //Used for polySubtract

int highExp(listPoly *); //Return the highest exponent

void polyMultiply(listPoly *, int); //Multiply poly by number

void freePoly(Node* head);//free polynomial expression