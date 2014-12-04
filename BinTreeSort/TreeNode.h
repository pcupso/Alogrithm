#ifndef CAIC_TREE_NODE_H_H
#define CAIC_TREE_NODE_H_H

typedef struct _tagTreeNode
{
	int nNodeNum;
	bool bTaged;
	_tagTreeNode* lChild;
	_tagTreeNode* rChild;
	_tagTreeNode* pNode;

	_tagTreeNode()
	{
		nNodeNum = -1;
		bTaged = false;
		lChild = NULL;
		rChild = NULL;
		pNode = NULL;
	}

	bool operator == (const struct _tagTreeNode &stInNode) const
	{
		return nNodeNum == stInNode.nNodeNum;
	}

	void operator = (const struct _tagTreeNode &stInNode)
	{
		nNodeNum = stInNode.nNodeNum;
		bTaged = stInNode.bTaged;
		lChild = stInNode.lChild;
		rChild = stInNode.rChild;
		pNode = stInNode.pNode;
	}

}TreeNode, *LPTreeNode;

#endif