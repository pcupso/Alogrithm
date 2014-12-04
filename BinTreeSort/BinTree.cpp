/************************************************************************/
/*	Author	:	caic 
/*	Mail	:	893710128@qq.com
/*	Date	:	12/04/2014
/*	Category:	Alogrithm
/************************************************************************/

#include "BinTree.h"
#include <stdio.h>

BinTree::BinTree(void)
:nDLRTagedNum_(0),
nLDRTagedNum_(0),
nLRDTagedNum_(0)
{

	InitializeBinTree();
}

BinTree::~BinTree(void)
{

}

void BinTree::clearNodes(void)
{
	node1.bTaged = false;
	node2.bTaged = false;
	node3.bTaged = false;
	node4.bTaged = false;
	node5.bTaged = false;
	node6.bTaged = false;
	node7.bTaged = false;
	node8.bTaged = false;
	node9.bTaged = false;
	node10.bTaged = false;
	node11.bTaged = false;
	node12.bTaged = false;
}

/************************************************************************/
/* Tree Description:
/*
/*				 1
/*			2		   3
/*		  4   5	    6     7
/*		8	 9 10  		11 12
/*
/* Up is the tree map I define
/*	So  FirstOrder(DLR) is	: 1 2 4 8 5 9 10 3 6 7 11 12
/*		MidOrder(LDR) is	: 8 4 2 9 5 10 1 6 3 11 7 12
/*		LastOrder(LRD) is	: 8 4 9 10 5 2 6 11 12 7 3 1
/* then let's begin to order it. 
/************************************************************************/

void BinTree::InitializeBinTree(void)
{
	node1.nNodeNum = 1;
	node2.nNodeNum = 2;
	node3.nNodeNum = 3;
	node4.nNodeNum = 4;
	node5.nNodeNum = 5;
	node6.nNodeNum = 6;
	node7.nNodeNum = 7;
	node8.nNodeNum = 8;
	node9.nNodeNum = 9;
	node10.nNodeNum = 10;
	node11.nNodeNum = 11;
	node12.nNodeNum = 12;

	node1.lChild = &node2;
	node1.rChild = &node3;
	node2.lChild = &node4;
	node2.rChild = &node5;
	node4.lChild = &node8;
	node5.lChild = &node9;
	node5.rChild = &node10;
	node3.lChild = &node6;
	node3.rChild = &node7;
	node7.lChild = &node11;
	node7.rChild = &node12;

	node8.pNode = &node4;
	node9.pNode = &node5;
	node10.pNode = &node5;
	node11.pNode = &node7;
	node12.pNode = &node7;
	node4.pNode = &node2;
	node5.pNode = &node2;
	node6.pNode = &node3;
	node7.pNode = &node3;
	node2.pNode = &node1;
	node3.pNode = &node1;

}

void BinTree::LogNode(TreeNode* node)
{
	printf("%d  ", node->nNodeNum);
}

/************************************************************************/
/* First Order
/************************************************************************/
void BinTree::DLROrder(void)
{
	//Start Node
	clearNodes();

	TreeNode startNode = node1;
	LogNode(&startNode);
	DLRNodeOrder(&startNode);
}

void BinTree::DLRNodeOrder(TreeNode* node)
{
	if(node->lChild != NULL && !node->lChild->bTaged)
	{
		node = node->lChild;
		LogNode(node);
		DLRNodeOrder(node);
	} 
	else if(node->rChild != NULL && !node->rChild->bTaged)
	{
		node = node->rChild;
		LogNode(node);
		DLRNodeOrder(node);
	}
	else if(nDLRTagedNum_ < TREENODE_COUNT-1)
	{
		nDLRTagedNum_++;
		node->bTaged = true;

		node = node->pNode;
		DLRNodeOrder(node);
	}
	else{
		return;
	}
}

/************************************************************************/
/* Mid Order
/************************************************************************/
void BinTree::LDROrder(void)
{
	//Start Node
	clearNodes();

	TreeNode startNode = node1;
	LDRNodeOrder(&startNode);
}

void BinTree::LDRNodeOrder(TreeNode* node)
{
	if(node->lChild != NULL && !node->lChild->bTaged)
	{
		node = node->lChild;
		LDRNodeOrder(node);
	}
	else if(!node->bTaged){
		nLDRTagedNum_++;
		node->bTaged = true;
		LogNode(node);

		if(node->rChild != NULL && !node->rChild->bTaged){
			node = node->rChild;
		}

		LDRNodeOrder(node);
	}
	else if(nLDRTagedNum_ < TREENODE_COUNT-1)
	{
		node = node->pNode;
		LDRNodeOrder(node);
	}
	else
	{
		return;
	}
}


/************************************************************************/
/* Last Order
/************************************************************************/
void BinTree::LRDOrder(void)
{
	//Start Node
	clearNodes();

	TreeNode startNode = node1;
	LRDNodeOrder(&startNode);
}

void BinTree::LRDNodeOrder(TreeNode* node)
{
	if(node->lChild != NULL && !node->lChild->bTaged)
	{
		node = node->lChild;
		LRDNodeOrder(node);
	}
	else if(node->rChild != NULL && !node->rChild->bTaged)
	{
		node = node->rChild;
		LRDNodeOrder(node);
	}
	else if( nLRDTagedNum_ < TREENODE_COUNT-1)
	{
		nLRDTagedNum_++;
		node->bTaged = true;

		LogNode(node);
		node = node->pNode;
		LRDNodeOrder(node);
	}
	else
	{
		LogNode(node);
		return;
	}
}
