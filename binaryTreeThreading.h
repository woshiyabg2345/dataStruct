#ifndef __BinaryTreeThreading_H__

#define __BinaryTreeThreading_H__



#include <stdio.h>
/*

  ����������һ���ܵ�ԭ��    ���û�������� ��ô������ָ��ǰ�������ñ�ʶ ���û��������  ��ô������ָ���̲����ñ�ʶ

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