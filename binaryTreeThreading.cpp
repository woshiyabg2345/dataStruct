#include "binaryTreeThreading.h"

/*

  线索二叉树一个总的原则    如果没有左子树 那么左子树指向前驱并设置标识 如果没有右子树  那么右子树指向后继并设置标识
  原理很重要，线索二叉树的遍历只有在 某种遍历中止的时候才会利用后继去继续遍历，有的结点虽然做了遍历但是不见得在对线索二叉树进行
  遍历时就会用到
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

// 先序 线索二叉树
void PreOrderThreading(BinaryTreeThreadingNode* root, BinaryTreeThreadingNode*& pre)
{
	if (!root)
		return;
	printf("%0xp  ", root);
	// 首先判断结点的左子树是否满足为空 并且tag 为link
	
	if (!root->lchild && root->ltag == PointTag::Link)
	{
		// 如果满足 说明当前结点的前驱结点为pre
		root->lchild = pre;
		root->ltag = PointTag::Thread;
	}

	// 当前 结点是否为pre 的后继结点, 如果pre 结点的右子树不为空 需要为pre 结点添加后继结点
	if (pre && !pre->rchild)
	{
		pre->rchild = root;
		pre->rtag = PointTag::Thread;
	}


	pre = root; //当前结点作为下一个结点的前驱结点
	if( root->ltag == PointTag::Link)
		PreOrderThreading(root->lchild, pre);
	if( root->rtag == PointTag::Link)  // 如果之前已经遍历过的结点的右节点为空 上面的递归已经把右节点的线索化做好了，如果不做判断相当于无线循环
		PreOrderThreading(root->rchild, pre); // 当前结点变成前驱结点 右子树如果为空，那么右子树的后继将在遍历下一个结点是赋值

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
		//	// 如果当前右节点 有左节点并且不是指向前驱
		//	if (curNode->lchild && curNode->ltag == PointTag::Link)
		//		break;
		//	printf("%c ", curNode->data);
		//	curNode = curNode->rchild;
		//}
	}
}
// 遍历在pre 变量的赋值之中
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

	// 以当前结点作为对象进行观察  每一次大的循环都是立足于当前结点
	while (curNode)
	{
		
		while (curNode->lchild && curNode->ltag == PointTag::Link)
		{
			curNode = curNode->lchild;
		}

		printf("%c ", curNode->data);

		//curNode = curNode->rchild;

		// 判断右子树指向的是后继结点还是 子树
			while (curNode->rchild && curNode->rtag == PointTag::Thread)
			{
				// 如果是后继结点
				curNode = curNode->rchild;
				printf("%c ", curNode->data);
				
			}
			// 如果是子树
			curNode = curNode->rchild;


	}
}
