#ifndef CAIC_BIN_TREE_H_H
#define CAIC_BIN_TREE_H_H

#include <vector>
#include "TreeNode.h"

#define TREENODE_COUNT	12

class BinTree
{
public:
	BinTree(void);
	~BinTree(void);

	//Init Tree Data
	void InitializeBinTree(void);

	//Order
	void DLROrder(void);
	void LDROrder(void);
	void LRDOrder(void);

private:
	void clearNodes(void);
	void LogNode(TreeNode* node);

	// 	TreeNode* DLRFindFstElement(void);
	// 	TreeNode* LDRFindFstElement(void);
	// 	TreeNode* LRDFindFstElement(void);

	void DLRNodeOrder(TreeNode* node);
	void LDRNodeOrder(TreeNode* node);
	void LRDNodeOrder(TreeNode* node);

private:
	TreeNode node1;
	TreeNode node2;
	TreeNode node3;
	TreeNode node4;
	TreeNode node5;
	TreeNode node6;
	TreeNode node7;
	TreeNode node8;
	TreeNode node9;
	TreeNode node10;
	TreeNode node11;
	TreeNode node12;

	int nDLRTagedNum_;
	int nLDRTagedNum_;
	int nLRDTagedNum_;
};

#endif