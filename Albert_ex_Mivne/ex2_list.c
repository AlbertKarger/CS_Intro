#include <stdlib.h>
#include "ex2_list.h"

//Ex2 A, Initiate list, sets head & tail of list as NULL
void initListPoly(listPoly *lst)
{
	lst->head = lst->tail = NULL;
}

//Ex2 B
void polyInsert(listPoly *poly, float coe, posInt exp) //insert & sort.
{
	Node *temp = NULL;
	int count = 0, x = 1; //Will help the function to indicate where do we need to insert the current node, more detailed explanation below.
	temp = poly->head;
	if (isEmptyPoly(poly)) {
		insertFirstPoly(poly, coe, exp);//If list empty, insert 1st.
	}
	else {
		while (temp != NULL)//Going through the list.
		{
			if (temp->data.exp == exp)//If the exponential is the same, coefficient will be added. 
			{
				temp->data.coe += coe;//Adding coefficient.
				x = 0;//Will prevent the function from getting into the functions below as I only needed to add the coefficient without inserting any nodes.
				count = 0; //count set to 0 in order to prevent a situation of incorrect count because count is used at insertAfterPoly.
			}
			else if (temp->data.exp < exp)
				count++;
			temp = temp->next;
		}
		if ((count != 0) && (count < (lengthPoly(poly))) && (x != 0))//In this case, we are inserting in the middle, count got to the point which the exp is higher then some node's exp, as we are using insertAfter, the count reduced by 1.
			insertAfterPoly(poly, coe, exp, count - 1);
		if ((count == lengthPoly(poly)) && (x != 0))//In this case the exponential pending to get in is the highest as count reached the size of the list, thats why insertLast.
			insertLastPoly(poly, coe, exp);
		if ((count == 0) && (x != 0))//At this point the exponential is lower then all the exponential in the list, as count is still 0, insertFirst.
			insertFirstPoly(poly, coe, exp);
	}
}

//Ex2 C
listPoly polyAdd(listPoly *poly1, listPoly *poly2)//Adding two lists into 1.
{
	Node *temp1 = NULL, *temp2 = NULL;
	int exp = 1, i, count = 0;
	listPoly poly3;
	initListPoly(&poly3);
	temp1 = poly1->head;
	for (i = 0; i < lengthPoly(poly1); i++)	{ //Inseration of 1st list into the new one via insertLast function as the list already came sorted.
		insertLastPoly(&poly3, temp1->data.coe, temp1->data.exp);
		temp1 = temp1->next;
	}
	//temp1 = poly3.head;//is it indeed needed.
	temp2 = poly2->head;
	while (temp2 != NULL) //Going through the 2nd list and inserting it into the new list, via polyInsert function it will insert the new list as requested
	{
		polyInsert(&poly3, temp2->data.coe, temp2->data.exp);
		temp2 = temp2->next;
	}
	temp1 = poly3.head; //Start of section which will verify if indeed the list is "empty"(all coefficient are '0').
	count = 0;
	while (temp1 != NULL) {//Verification of all coefficient, if they are all 0
		if (temp1->data.coe != 0)
			count++;
		temp1 = temp1->next;
	}
	freePoly(poly1->head);
	freePoly(poly2->head);
	if (count == 0) { //If all coefficient were '0' than we will initiate function initList which will set head to NULL which will help in printing empty list,free will be initiated at main.
		initListPoly(&poly3);//Free will be initaited at main.
		return poly3;
	}
	else//If the list is not empty.
	{
		return poly3;
	}
}

//Ex2 D
listPoly polySubtract(listPoly *poly1, listPoly *poly2) //same as polyAdd function, the only difference is that we will use polyInsertSubstract function instead of polyInsertAdd function.
{
	Node *temp1 = NULL, *temp2 = NULL;
	int exp = 1, i, count = 0;
	listPoly poly3;
	initListPoly(&poly3);
	temp1 = poly1->head;
	for (i = 0; i < lengthPoly(poly1); i++)
	{
		insertLastPoly(&poly3, temp1->data.coe, temp1->data.exp);
		temp1 = temp1->next;
	}
	temp2 = poly2->head;
	while (temp2 != NULL)
	{
		polyInsertSubtract(&poly3, temp2->data.coe, temp2->data.exp);
		temp2 = temp2->next;
	}
	temp1 = poly3.head;
	count = 0;
	while (temp1 != NULL) {
		if (temp1->data.coe != 0)
			count++;
		temp1 = temp1->next;
	}
	freePoly(poly1->head);
	freePoly(poly2->head);
	if (count == 0) {
		initListPoly(&poly3);//Free will be initaited at main.
		return poly3;
	}
	else
	{
		return poly3;
	}
}

//Ex2 D
void polyInsertSubtract(listPoly *poly, float coe, posInt exp) //same as polyInsertAdd function, the only difference is that we will substract the coefficient instead of adding, used in polySubtract function.
{
	Node *temp = NULL;
	int count = 0, x = 1;
	temp = poly->head;
	if (isEmptyPoly(poly)) {
		insertFirstPoly(poly, coe, exp);
	}
	else {
		while (temp != NULL)
		{
			if (temp->data.exp == exp)
			{
				temp->data.coe -= coe;
				x = 0;
				count = 0;
			}
			else if (temp->data.exp < exp)
				count++;
			temp = temp->next;
		}

		if ((count != 0) && (count < (lengthPoly(poly))) && (x != 0))
			insertAfterPoly(poly, coe, exp, count - 1);
		if ((count == lengthPoly(poly)) && (x != 0))
			insertLastPoly(poly, coe, exp);
		if ((count == 0) && (x != 0))
			insertFirstPoly(poly, coe, exp);
	}
}

//Ex2 E
void polyMultiply(listPoly *poly, int c)
{
	Node *temp = NULL;
	if (c == 0)
		freePoly(poly->head);//Will free the list as we are multiplying by zero.
	else {
		temp = poly->head;
		while (temp != NULL)
		{
			temp->data.coe *= c; //Going through each coefficient and multiplying by 'c'.
			temp = temp->next;
		}
	}
}

//Ex2 F
int highExp(listPoly *poly)
{
	if (isEmptyPoly(poly))
		return -1;
	return poly->tail->data.exp;//As the list already sorted, we will send the last exponential which is the highest.
}

//Ex2 G Free list, going through each node and freeing.
void freePoly(Node* head)
{
	Node* to_free = head;
	while (to_free != NULL)
	{
		head = head->next;
		free(to_free);
		to_free = head;
	}
}

//Ex2 H, If indeed we would like to print a fraction, we will need to change the 0 after the dot to the amount of digits we would like to print after the dot.
void listPrintPoly(listPoly *list)
{
	printf("Printing the Polynomial expression\n");
	Node *temp; //Created for easier printing, point the node to the head of the list.
	temp = list->tail;
	if (list->head == NULL)
		printf("Zero(Empty Polynomial)\n");
	int count = 0; //Created for 1st print and only for positive numbers as we don't want to have + before the 1st value printed.
	while (temp != NULL)//Basically this area divided into 3 main areas, what if exponential=0/exponential=1/exponential>1, each subarea has the section of what if coefficient is 1/-1/<0/>0
	{
		if (temp->data.coe == 0)//Skips the element from printing as coefficient is '0'
			if(temp->prev != NULL)
				temp = temp->prev;
		if (temp->data.exp == 0) {//Print area when exponential is 0
			if ((temp->data.coe > 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				if (count != 0)
					printf("+%.0f", temp->data.coe);
				else
					printf("%.0f", temp->data.coe);
			else if ((temp->data.coe < 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				printf("%.0f", temp->data.coe);
			else if (temp->data.coe == 1)
				if (count != 0)
					printf("+1");
				else
					printf("1");
			else if (temp->data.coe == -1)
				printf("-1");
		}
		if (temp->data.exp == 1) {//Print area when exponential is 1
			if ((temp->data.coe > 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				if (count != 0)
					printf("+%.0fx", temp->data.coe);
				else
					printf("%.0fx", temp->data.coe);
			else if ((temp->data.coe < 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				printf("-%.0fx", temp->data.coe);
			else if (temp->data.coe == 1)
				if (count != 0)
					printf("+x");
				else
					printf("x");
			else if (temp->data.coe == -1)
				printf("-x");
		}
		if (temp->data.exp > 1) {//Print area when exponential is higher than 1
			if ((temp->data.coe > 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				if (count != 0)
					printf("+%.0fx^%lu", temp->data.coe, temp->data.exp);
				else
					printf("%.0fx^%lu", temp->data.coe, temp->data.exp);
			else if ((temp->data.coe < 0) && (temp->data.coe != 1) && (temp->data.coe != -1))
				printf("%.0fx^%lu", temp->data.coe, temp->data.exp);
			else if (temp->data.coe == 1)
				if (count != 0)
					printf("+x^%lu", temp->data.exp);
				else
					printf("x^%lu", temp->data.exp);
			else if (temp->data.coe == -1)
				printf("-x^%lu", temp->data.exp);
		}
		temp = temp->prev;
		count++;//After 1st iteration the count will be different from '0' so we could print properly with '+'
	}
	printf("\n\n");
}

//insert link at the last location
void insertLastPoly(listPoly *lst, float coe, posInt exp)
{
	//create a new link
	Node *link = (Node*)malloc(sizeof(Node));
	link->data.coe = coe;
	link->data.exp = exp;
	link->next = NULL;
	link->prev = NULL;

	if (isEmptyPoly(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;
	}
	else
	{
		//make link a new last link
		lst->tail->next = link;
		//mark old last node as prev of new link
		link->prev = lst->tail;
		//point last to new last node
		lst->tail = link;
	}
}

//Insert after given index.
int insertAfterPoly(listPoly *lst, float coe, posInt exp, int idx)
{
	if (!isEmptyPoly(lst))
	{
		int i;
		//start from the first link
		Node* current = lst->head;
		Node* newLink = NULL;

		//navigate through list
		for (i = 0; i<idx && current != NULL; i++)
			current = current->next;

		if (current == NULL)
			return 0;
		if (current == lst->tail)
		{
			insertLastPoly(lst, coe, exp);
			return 1;
		}

		//create a link
		newLink = (Node*)malloc(sizeof(Node));
		newLink->data.coe = coe;
		newLink->data.exp = exp;
		//assign new link pointers
		newLink->prev = current;
		newLink->next = current->next;
		//chain current and current->next to new link
		current->next->prev = newLink;
		current->next = newLink;
		return 1;
	}
	return 0;
}

//is list empty, if head indeed NULL, which means list is empty, used in many functions.
int isEmptyPoly(listPoly *lst)
{
	return lst->head == NULL;
}

//Returns the length of the list, how many nodes exists in that list, used in many functions.
int lengthPoly(listPoly *lst)
{
	int length = 0;
	Node *current;

	for (current = lst->head; current != NULL; current = current->next)
		length++;

	return length;
}

//insert link at the first location
void insertFirstPoly(listPoly *lst, float coe, posInt exp)
{
	//create a new link
	Node *link = (Node*)malloc(sizeof(Node));
	link->data.coe = coe;
	link->data.exp = exp;
	link->next = NULL;
	link->prev = NULL;

	if (isEmptyPoly(lst))
	{
		//make head & tail pointing to link
		lst->head = lst->tail = link;
	}
	else
	{
		//update first prev link
		lst->head->prev = link;
		//point it to old first link
		link->next = lst->head;
		//point first to new first link
		lst->head = link;
	}
}