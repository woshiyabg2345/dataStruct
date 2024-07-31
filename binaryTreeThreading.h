#ifndef __BinaryTreeThreading_H__

#define __BinaryTreeThreading_H__



#include <stdio.h>
/*

  线索二叉树一个总的原则    如果没有左子树 那么左子树指向前驱并设置标识 如果没有右子树  那么右子树指向后继并设置标识

*/

enum PointTag
{
	Link,
	Thread,
};


struct BinaryTreeThreadingNode
{
	BinaryTreeThreadingNode()
	{
		lchild = rchild = nullptr;
		ltag = rtag = PointTag::Link;
	}
	int data;
	BinaryTreeThreadingNode* lchild;
	BinaryTreeThreadingNode* rchild;
	PointTag ltag;
	PointTag rtag;
};

void creatTreeX(BinaryTreeThreadingNode** root, const char* data, int size, int& index);
void preOrderTravel(BinaryTreeThreadingNode* root);
void inOrderTravel(BinaryTreeThreadingNode* root);

void PreOrderThreading(BinaryTreeThreadingNode* root, BinaryTreeThreadingNode*& pre);
void PreOrderThreadingTravel(BinaryTreeThreadingNode* root);
void InOrderThreading(BinaryTreeThreadingNode* root, BinaryTreeThreadingNode*& pre);
void InOrderThreadingTravel(BinaryTreeThreadingNode* root);


#endif