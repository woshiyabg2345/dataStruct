#include "binaryTreeThreading.h"

/*

  ����������һ���ܵ�ԭ��    ���û�������� ��ô������ָ��ǰ�������ñ�ʶ ���û��������  ��ô������ָ���̲����ñ�ʶ
  ԭ�����Ҫ�������������ı���ֻ���� ĳ�ֱ�����ֹ��ʱ��Ż����ú��ȥ�����������еĽ����Ȼ���˱������ǲ������ڶ���������������
  ����ʱ�ͻ��õ�
*/

void creatTreeX(BinaryTreeThreadingNode** root, const char* data, int size, int& index)
{

	if (!root || size <= index)
	{
		return;
	}

	if (size > index && data[index] != '#')
	{
		*root = new BinaryTreeThreadingNode();
		if (*root)
		{
			(*root)->data = data[index];
			index++;
			creatTreeX(&(*root)->lchild, data, size, index);
			creatTreeX(&(*root)->rchild, data, size, index);
		}
	}
	else
	{
		index++;
	}
}

void preOrderTravel(BinaryTreeThreadingNode* root)
{

	if (root)
	{
		printf("%c ", root->data);
		preOrderTravel(root->lchild);
		preOrderTravel(root->rchild);
	}

}

void inOrderTravel(BinaryTreeThreadingNode* root)
{
	if (root)
	{
		inOrderTravel(root->lchild);
		printf("%c ", root->data);
		inOrderTravel(root->rchild);
	}

}

// ���� ����������
void PreOrderThreading(BinaryTreeThreadingNode* root, BinaryTreeThreadingNode*& pre)
{
	if (!root)
		return;
	printf("%0xp  ", root);
	// �����жϽ����������Ƿ�����Ϊ�� ����tag Ϊlink
	
	if (!root->lchild && root->ltag == PointTag::Link)
	{
		// ������� ˵����ǰ����ǰ�����Ϊpre
		root->lchild = pre;
		root->ltag = PointTag::Thread;
	}

	// ��ǰ ����Ƿ�Ϊpre �ĺ�̽��, ���pre ������������Ϊ�� ��ҪΪpre �����Ӻ�̽��
	if (pre && !pre->rchild)
	{
		pre->rchild = root;
		pre->rtag = PointTag::Thread;
	}


	pre = root; //��ǰ�����Ϊ��һ������ǰ�����
	if( root->ltag == PointTag::Link)
		PreOrderThreading(root->lchild, pre);
	if( root->rtag == PointTag::Link)  // ���֮ǰ�Ѿ��������Ľ����ҽڵ�Ϊ�� ����ĵݹ��Ѿ����ҽڵ�������������ˣ���������ж��൱������ѭ��
		PreOrderThreading(root->rchild, pre); // ��ǰ�����ǰ����� ���������Ϊ�գ���ô�������ĺ�̽��ڱ�����һ������Ǹ�ֵ

}

void PreOrderThreadingTravel(BinaryTreeThreadingNode* root)
{

	if (!root)
		return;
	BinaryTreeThreadingNode* curNode = root;
	while (curNode)
	{
		while (curNode->lchild && curNode->ltag == PointTag::Link)
		{
			printf("%c ", curNode->data);
			curNode = curNode->lchild;
		}
		printf("%c ", curNode->data);
		
		curNode = curNode->rchild;

		
		//while (curNode)
		//{
		//	// �����ǰ�ҽڵ� ����ڵ㲢�Ҳ���ָ��ǰ��
		//	if (curNode->lchild && curNode->ltag == PointTag::Link)
		//		break;
		//	printf("%c ", curNode->data);
		//	curNode = curNode->rchild;
		//}
	}
}
// ������pre �����ĸ�ֵ֮��
void InOrderThreading(BinaryTreeThreadingNode* root, BinaryTreeThreadingNode*& pre)
{
	if (!root)
		return;
	///if( root->ltag == PointTag::Link)
		InOrderThreading(root->lchild, pre);
	if (root && !root->lchild)
	{
		root->lchild = pre;
		root->ltag = PointTag::Thread;
	}
	if (pre && !pre->rchild)
	{
		pre->rchild = root;
		pre->rtag = PointTag::Thread;
	}

	pre = root;
	//if (root->ltag == PointTag::Link)
		InOrderThreading(root->rchild, pre);
}


void InOrderThreadingTravel(BinaryTreeThreadingNode* root)
{


	if (!root)
		return;
	BinaryTreeThreadingNode* curNode = root;

	// �Ե�ǰ�����Ϊ������й۲�  ÿһ�δ��ѭ�����������ڵ�ǰ���
	while (curNode)
	{
		
		while (curNode->lchild && curNode->ltag == PointTag::Link)
		{
			curNode = curNode->lchild;
		}

		printf("%c ", curNode->data);

		//curNode = curNode->rchild;

		// �ж�������ָ����Ǻ�̽�㻹�� ����
			while (curNode->rchild && curNode->rtag == PointTag::Thread)
			{
				// ����Ǻ�̽��
				curNode = curNode->rchild;
				printf("%c ", curNode->data);
				
			}
			// ���������
			curNode = curNode->rchild;


	}
}
