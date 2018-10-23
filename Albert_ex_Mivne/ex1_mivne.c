//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include "ex1_Stack_point.h"
//
////typedef was inserted into stack_point.h
//void aritmeCompile(char *str);
//
//
//
//void main()
//{
//	char str[101];
//	printf("Please enter your arithmetic expression(operand,operation,operand) not over 100 characters in a row\n");
//	gets(str);
//	printf("Your arithmetic expression is as follows\n");
//	puts(str);
//	printf("Operation\tOperand1\tOperand2\tResult\n");
//	aritmeCompile(str);
//}
//
//void aritmeCompile(char *str)
//{
//	int ch_len, i = 0, q = 0, count = 0;//count created in order to indicate the amount of operations.
//	stack_type Z = 90, temp;//temp used in order to host the result of top function.
//	stack s1, s2;
//	ch_len = strlen(str);
//	for (i = 0; i < ch_len; i++){//Will help me to indicate the size of my array, array is created for easier printing.
//		if ((str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-'))
//			count++;
//	}
//	i = 0;
//	result *arr; //Created for easier output in the future and insert of answers into S1.
//	arr = (result*)malloc(sizeof(result)*count);
//	assert(arr);
//	create_stack(&s1);
//	create_stack(&s2);
//	while (i < (ch_len))
//	{//1st if created in order to stop the function in case something incorrect was written.
//		if (!((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '\0') || (str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-')))
//		{
//			printf("Error\n");
//			return;
//		}//insert of operand to s1 stack, using push function.
//		if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
//			push(str[i], &s1);
//			i++;
//		}//insert of operation to s2 stack, using push function.
//		if ((str[i] == '^') || (str[i] == '*') || (str[i] == '/') || (str[i] == '+') || (str[i] == '-')) {
//			if (stack_is_empty(&s2) == 1) {
//				push(str[i], &s2);
//				i++;
//				if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {//insert of operand to s1 stack, using push function, will be pushed only if we had an operation inserted before and the stack of the operations was empty.
//					push(str[i], &s1);
//					i++;
//				}
//			}
//			if ((stack_is_empty(&s2) != 1) && (str[i] == '+' || str[i] == '-')) {
//				stack_top(&s2, &temp);
//				if (temp == '*' || temp == '^' || temp == '/') {//checks if current operation at S2 is higher('*' or '^' or '/') than what suppose to get in('+' or '-')/ if indeed higher, program will initiate pop accordingly to the instructions.
//					if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
//						push(str[i], &s1);//if indeed we have * or ^ or / which is higher than + or - and we have an operand coming in, we will insert the letter into S1.
//						i++;//@@@@@@@@NEED TO CHECK THIS SECTION, IS IT NEEDED!?!?!?!?@@@@@
//					}
//					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
//					pop(&s1, &arr[q].op1);
//					pop(&s2, &arr[q].oper);
//					arr[q].answer = ('Z' - q);
//					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
//					q++;
//				}
//				else {//If the top of S2 was not * or ^ or / then it probably has + or - which are in the same level, means we can initiate the pop.
//					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
//					pop(&s1, &arr[q].op1);
//					pop(&s2, &arr[q].oper);
//					arr[q].answer = ('Z' - q);
//					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
//					q++;
//				}
//			}
//			if ((stack_is_empty(&s2) != 1) && (str[i] == '*' || str[i] == '/')) {
//				stack_top(&s2, &temp);
//				if (temp != '^') {
//					push(str[i], &s2);
//					i++;
//					if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
//						push(str[i], &s1);
//						i++;
//					}
//					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
//					pop(&s1, &arr[q].op1);
//					pop(&s2, &arr[q].oper);
//					arr[q].answer = ('Z' - q);
//					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
//					q++;
//				}
//				else {
//					if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9'))
//						push(str[i], &s1);
//					pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
//					pop(&s1, &arr[q].op1);
//					pop(&s2, &arr[q].oper);
//					arr[q].answer = ('Z' - q);
//					printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//					push(arr[q].answer, &s1);//pushing answer into S1 as requested.
//					q++;
//				}
//			}
//			if ((stack_is_empty(&s2) != 1) && (str[i] == '^')) {
//				push(str[i], &s2);
//				i++;
//				if ((str[i] >= 'A' && str[i] <= 'H') || (str[i] >= '0' && str[i] <= '9')) {
//					push(str[i], &s1);
//					i++;
//				}
//				pop(&s1, &arr[q].op2);//These 3 pops will remove the values from S1 and S2 stacks into our array struct which will assist in printing and returning the answer to S1.
//				pop(&s1, &arr[q].op1);
//				pop(&s2, &arr[q].oper);
//				arr[q].answer = ('Z' - q);
//				printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//				push(arr[q].answer, &s1);//pushing answer into S1 as requested.
//				q++;
//			}
//		}
//		if (str[i] == '\0')//In case we got to end of the string and we still have operands/operations inside our stacks, we will pop them accordingly to the instructions.
//			if (stack_is_empty(&s1) != 1)
//			{
//				pop(&s1, &arr[q].op2);
//				if (stack_is_empty(&s1) != 1)
//					pop(&s1, &arr[q].op1);
//				if (stack_is_empty(&s2) != 1)
//					pop(&s2, &arr[q].oper);
//				arr[q].answer = ('Z' - q);
//				printf("%c\t\t%c\t\t%c\t\t%c\n", arr[q].oper, arr[q].op1, arr[q].op2, arr[q].answer);
//			}
//	}
//	for (i = 0; i < count; i++) {//Free the memory used by the array which created for easier printing.
//		free(arr[i].answer);
//		free(arr[i].op1);
//		free(arr[i].op2);
//		free(arr[i].oper);
//	}
//}
//		