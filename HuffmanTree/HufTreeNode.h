#ifndef TREE_NODE_H_H
#define TREE_NODE_H_H

typedef struct _tagHufTreeNode 
{
	int nWeight;
	_tagHufTreeNode* lChild;
	_tagHufTreeNode* rChild;
	_tagHufTreeNode* pNode;

	_tagHufTreeNode(){
		nWeight = -1;
		lChild = 0;
		rChild = 0;
		pNode = 0;
	}

	void operator = (const struct _tagHufTreeNode& node)
	{
		nWeight = node.nWeight;
		lChild = node.lChild;
		rChild = node.rChild;
		pNode = node.pNode;
	}

}HufTreeNode, *LPHufTreeNode;

#endif