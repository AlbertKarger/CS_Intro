//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "ex2_list.h"
//
//
//
//void main()
//{
//	listPoly poly1, poly2, result;//
//	//Node *result;
//	initListPoly(&poly1);
//	initListPoly(&poly2);
//	int coe, exp; //start of 1st poly insert
//	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
//	scanf("%d", &coe);
//	scanf("%d", &exp);
//	while (coe != 0) 
//	{
//		polyInsert(&poly1, coe, exp);
//		scanf("%d", &coe);
//			if (coe != 0)
//				scanf("%d", &exp);
//	}
//	listPrintPoly(&poly1);
//	//freePoly(poly1.head); //requiers modification
//	//listPrintPoly(&poly1);
//	printf("Size of Polynomial expression is: %d\n",highExp(&poly1));
//	//start of 2nd poly insert
//	printf("Please enter the coe and exp you would like to add, enter coe as 0 if you would like to stop\n");
//	scanf("%d", &coe);
//	scanf("%d", &exp);
//	while (coe != 0)
//	{
//		polyInsert(&poly2, coe, exp);
//		scanf("%d", &coe);
//		if (coe != 0)
//			scanf("%d", &exp);
//	}
//	listPrintPoly(&poly2);
//	printf("Size of Polynomial expression is: %d\n", highExp(&poly2));
//	result = polySubtract(&poly1, &poly2);
//	listPrintPoly(&result);
//	//printf("%d\n", highExp(&result)); //needs modification@@@@
//	//freePoly(&result->head); //needs verification@@@
//	//listPrintPoly(&result); 
//	//used for E
//	//printf("Please enter the number you would like to multiply with\n");
//	//int c;
//	//scanf("%d", &c);
//	//polyMultiply(&poly1, c);
//	//listPrintPoly(&poly1);
//
//}