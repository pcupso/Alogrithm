/************************************************************************/
/*	Author	:	caic 
/*	Mail	:	893710128@qq.com
/*	Date	:	12/04/2014
/*	Category:	Alogrithm
/************************************************************************/
#include "stdafx.h"
#include "BinTree.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//Init Bin Tree
	printf("*************** Bin Tree *******************\n");
	printf("                   1                        \n");
	printf("        2                      3            \n");
	printf("     4      5               6      7        \n");
	printf("   8      9   10                11   12     \n");
	printf("********************************************\n");


	BinTree bt;
	printf("BinTree DLR Order is : ");
	bt.DLROrder();
	printf("\n\n");
	printf("BinTree LDR Order is : ");
	bt.LDROrder();
	printf("\n\n");
	printf("BinTree LRD Order is : ");
	bt.LRDOrder();
	printf("\n");

	return 0;
}

