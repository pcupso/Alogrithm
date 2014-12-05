#include "HufTree.h"
#include <stdio.h>
#include "HufTreeNode.h"

HufTree::HufTree(void)
{
	InitializeTree();
}

HufTree::~HufTree(void)
{
	
}


void HufTree::InitializeTree(void)
{
	HufTreeNode treeNodes[100];

	printf("###### Initialize tree nodes info first! ######\n");
	int nTreeNodeCount = 0;
	printf("Input your tree nodes count(<50) : ");
	scanf("%d", &nTreeNodeCount);
	

	for(int i = 0; i < nTreeNodeCount; i++)
	{
		printf("Input new node weight : ");
		scanf("%d", &(treeNodes[i].nWeight));
	}
	
	//Sort
	for(int m = 0; m < nTreeNodeCount; m++)
	{
		for(int j = m+1; j < nTreeNodeCount; j++)
		{
			if(treeNodes[m].nWeight > treeNodes[j].nWeight)
			{
				int nTmp = treeNodes[m].nWeight;
				treeNodes[m].nWeight = treeNodes[j].nWeight;
				treeNodes[j].nWeight = nTmp;
			}
		}
	}

	//
	for(int k = nTreeNodeCount; k < (2*nTreeNodeCount -1); k++){
		if(k == nTreeNodeCount){
			treeNodes[k].nWeight = treeNodes[k - nTreeNodeCount].nWeight + treeNodes[k - nTreeNodeCount +1].nWeight;
		}else{
			treeNodes[k].nWeight = treeNodes[k-1].nWeight + treeNodes[k - nTreeNodeCount+1].nWeight;
		}
	}

	printf("New Hufman Tree is : \n");
	for(int i = 0; i < (2*nTreeNodeCount -1); i++){
		printf(" %d -", treeNodes[i].nWeight);
	}

}

