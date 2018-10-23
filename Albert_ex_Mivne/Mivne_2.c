#define _CRT_SECURE_NO_WARNINGS
/*
Assigned by:
Albert Karger ID 314355728, Group 61104
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ex1_Stack_point.h"
#include "ex2_list.h"

/*Ex1 & Ex2 defines included at ex1_Stack_point & ex2_list headers*/

/* Function declarations */

void Ex1();
void Ex2_A();
void Ex2_B();
void Ex2_C();
void Ex2_D();
void Ex2_E();
void Ex2_F();
void Ex2_G();
void Ex2_H();

/* Declarations of other functions */
void aritmeCompile(char *str); //Ex1 function, Bonus included.
/*Ex1 other functions are used from ex1_Stack_point,h header*/
/*Ex2 functions were included at the header ex2_list.h*/
int main()
{
	int select = 0, i = 1, c = 65, a = 2, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			printf("Ex%d--->%d\n", i, i);
			for (i = 2, c=65; i <= 9; i++, c++)
				printf("Ex%d_%c--->%d\n",a , c, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-9 : ");
				scanf("%d", &select);
			} while ((select<0) || (select>9));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2_A(); break;
			case 3: Ex2_B(); break;
			case 4: Ex2_C(); break;
			case 5: Ex2_D(); break;
			case 6: Ex2_E(); break;
			case 7: Ex2_F(); break;
			case 8: Ex2_G(); break;
			case 9: Ex2_H(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
/* Function definitions */
//Ex1, Bonus included.
void Ex1()
{
	printf("Reordering properly an mathematical expression\n");
	char str[101];
	printf("Please enter your arithmetic expression(operand,operation,operand) not over 100 characters in a row\n");
	rewind(stdin);
	gets(str);
	printf("Your arithmetic expression is as follows\n");
	puts(str);
	printf("Operation\tOperand1\tOperand2\tResult\n");
	aritmeCompile(str);
}
//Ex2, initiate list(Empty polynomial expression)
void Ex2_A()
{
	printf("Initiate list function\n");
	listPoly poly1;
	initListPoly(&poly1);
}
//Ex2, Insert into list(Polynomial expression)
void Ex2_B()
{
	printf("Insert polynomial expression function\n");
	listPoly poly1;
	initListPoly(&poly1);
	int coe, exp;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	freePoly(poly1.head);
}
//Ex2, Add 2 polynomials expressions
void Ex2_C()
{
	printf("Summing 2 polynomial expressions\n");
	listPoly poly1, poly2, result;				  
	initListPoly(&poly1);
	initListPoly(&poly2);
	//start of 1st poly insert
	int coe, exp; 
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	//start of 2nd poly insert
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly2, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly2);
	result = polyAdd(&poly1, &poly2);
	listPrintPoly(&result);
	freePoly(result.head);
}
//Ex2, Subtract 2 polynomials expressions
void Ex2_D()
{
	printf("Subtracting 2 polynomial expressions\n");
	listPoly poly1, poly2, result;
	initListPoly(&poly1);
	initListPoly(&poly2);
	//start of 1st poly insert
	int coe, exp;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	//start of 2nd poly insert
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly2, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly2);
	result = polySubtract(&poly1, &poly2);
	listPrintPoly(&result);
	freePoly(result.head);
}
//Ex2, Multiply polynomial expression
void Ex2_E()
{
	printf("Multiplying polynomial expression\n");
	listPoly poly1;
	initListPoly(&poly1);
	int coe, exp, c;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	printf("Please enter the number you would like to multiply with\n");
	scanf("%d", &c);
	polyMultiply(&poly1, c);
	listPrintPoly(&poly1);
	freePoly(poly1.head);
}
//Ex2, Returns order of polynomial expression
void Ex2_F()
{
	printf("Returns order of polynomial expression\n");
	listPoly poly1;
	initListPoly(&poly1);
	int coe, exp;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	printf("Size of Polynomial expression is: %d\n", highExp(&poly1));
	freePoly(poly1.head);
}
//Ex2, Reset polynomial expression into empty polynomial expression
void Ex2_G()
{
	printf("Reset polynomial expression into empty one\n");
	listPoly poly1;
	initListPoly(&poly1);
	int coe, exp;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	freePoly(poly1.head);
	initListPoly(&poly1);//Created in order to print the result properly, eventually we won't be able to print an unallocated memory properly, it will print junk.
	listPrintPoly(&poly1);
}
//Ex2, Printing polynomial expression
void Ex2_H()
{
	printf("Printing polynomial expression function\n");
	listPoly poly1;
	initListPoly(&poly1);
	int coe, exp;
	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
	scanf("%d", &coe);
	scanf("%d", &exp);
	while (coe != 0)
	{
		polyInsert(&poly1, coe, exp);
		scanf("%d", &coe);
		if (coe != 0)
			scanf("%d", &exp);
	}
	listPrintPoly(&poly1);
	freePoly(poly1.head);
}
//Ex1 function, Bonus included.
void aritmeCompile(char *str)
{
	int ch_len, i = 0, q = 0, count = 0;//count created in order to indicate the amount of operations.
	stack_type Z = 90, temp;//temp used in order to host the result of top function.
	stack s1, s2;
	ch_len = strlen(str);
	for (i = 0; i < ch_len; i++) {//Will help me to indicate the size of my array, array is created for easier printing.
		if ((str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-'))
			count++;
	}
	i = 0;
	result *arr; //Created for easier output in the future and insert of answers into S1.
	arr = (result*)malloc(sizeof(result)*count);
	assert(arr);
	create_stack(&s1);
	create_stack(&s2);
	while (i < (ch_len))
	{//1st if created in order to stop the function in case something incorrect was written.
		if (!((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '\0') || (str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-')))
		{
			printf("Error\n");
			return;
		}//insert of operand to s1 stack, using push function.
		if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
			push(str[i], &s1);
			i++;
		}//insert of operation to s2 stack, using push function.
		if ((str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-')) {
			if (stack_is_empty(&s2) == 1) {
				push(str[i], &s2);
				i++;
				if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {//insert of operand to s1 stack, using push function, will be pushed only if we had an operation inserted before and the stack of the operations was empty.
					push(str[i], &s1);
					i++;
				}
			}
			if ((stack_is_empty(&s2) != 1) && (str[i] == '+' || str[i] == '-')) {
				stack_top(&s2, &temp);
				if (temp == '*' || temp == '^' || temp == '/') {//checks if current operation at S2 is higher('*' or '^' or '/') than what suppose to get in('+' or '-')/ if indeed higher, program will initiate pop accordingly to the instructions.
					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
					pop(&s1, &arr[q].op1);
					pop(&s2, &arr[q].oper);
					arr[q].answer = ('Z' - q);
					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
					q++;
				}
				else {//If the top of S2 was not * or ^ or / then it probably has + or - which are in the same level, means we can initiate the pop.
					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
					pop(&s1, &arr[q].op1);
					pop(&s2, &arr[q].oper);
					arr[q].answer = ('Z' - q);
					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
					q++;
				}
			}
			if ((stack_is_empty(&s2) != 1) && (str[i] == '*' || str[i] == '/')) {//If the current pending value is '*' or '/' and S2 is not empty.
				stack_top(&s2, &temp);//Checking top value at S2
				if (temp != '^') {//If the top is not '^' which is higher than '*' or '/'
					push(str[i], &s2);//Insert '*' or '/'
					i++;
					if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
						push(str[i], &s1);//Insert operand
						i++;
					}
					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
					pop(&s1, &arr[q].op1);
					pop(&s2, &arr[q].oper);
					arr[q].answer = ('Z' - q);
					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
					q++;
				}
				else {//If indeed the current value was '*' which is the highest, we will intiate the pops
					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
					pop(&s1, &arr[q].op1);
					pop(&s2, &arr[q].oper);
					arr[q].answer = ('Z' - q);
					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
					q++;
				}
			}
			if ((stack_is_empty(&s2) != 1) && (str[i] == '^')) {//If the current value is the highest operation '^', will intiate push of '^', then push of operand and then pops.
				push(str[i], &s2);
				i++;
				if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
					push(str[i], &s1);
					i++;
				}
				pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
				pop(&s1, &arr[q].op1);
				pop(&s2, &arr[q].oper);
				arr[q].answer = ('Z' - q);
				printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
				push(arr[q].answer, &s1);//pushing answer into S1 as requested.
				q++;
			}
		}
		if (str[i] == '\0')//In case we got to end of the string and we still have operands/operations inside our stacks, we will pop them accordingly to the instructions.
			if (stack_is_empty(&s1) != 1)
			{
				pop(&s1, &arr[q].op2);
				if (stack_is_empty(&s1) != 1)
					pop(&s1, &arr[q].op1);
				if (stack_is_empty(&s2) != 1)
					pop(&s2, &arr[q].oper);
				arr[q].answer = ('Z' - q);
				printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
			}
	}
	free(arr);
	printf("\n");
}