#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(int x)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (tmp == NULL)
	{
		perror("malloc error");
		return NULL;
	}
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}
//前序遍历
void prevorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	prevorder(root->left);
	prevorder(root->right);
	return;

}
//中序遍历
void inorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
	return;

}
//后序遍历
void postorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	postorder(root->left);
	
	postorder(root->right);
	printf("%d ", root->data);
	return;

}
int TreeNode(BTNode* root)
{
	/*if (root == NULL)
	{
		return 0;
	}
	return TreeNode(root->left) + TreeNode(root->right) + 1;*/
	return root == NULL ? 0 : TreeNode(root->left) + TreeNode(root->right) + 1;
}
//给出前序遍历，建造树
BTNode* Creat(char* a, int* pi)
{
	if (a[*(pi)]=='#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (tmp == NULL)
	{
		perror("malloc error");
		return NULL;
	}
	tmp->data = a[(*pi)++];
	tmp->left = Creat(a, pi);
	tmp->right = Creat(a, pi);
	//处理完毕，返回根节点
	return tmp;
}
//求叶子节点数
int TreeLeaves(BTNode* root)
{
	if (root == NULL)return 0;
	if (!root->left && !root->right)
		return 1;
	return TreeLeaves(root->left) + TreeLeaves(root->right);
}
int TreeHeight(BTNode* root)
{
	if (root == NULL)return 0;
	/*int left = TreeHeight(root->left);
	int right = TreeHeight(root->right);
	return (left > right ? left : right) + 1;*/
	return TreeHeight(root->left) > TreeHeight(root->right) ? 
		TreeHeight(root->left) + 1 :TreeHeight(root->right) + 1;
}
//求k层节点数
int TreekNode(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreekNode(root->left, k - 1) + TreekNode(root->right, k - 1);
}
// 二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//前序遍历查找，减少消耗
	if (root == NULL)return NULL;
	if (root->data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->left, x);
	if (left)
		return left;
	//BTNode* right = BinaryTreeFind(root->right, x);
	//if (right)
	//	return right;
	////左右都没有找到
	//return NULL;
	return BinaryTreeFind(root->right, x);
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
//BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void TreeDestory(BTNode** root)
{
	if (*root == NULL)return;
	TreeDestory((*root)->left);
	TreeDestory((*root)->right);
	free(*root);
	*root = NULL;
}
#include"Queue.h"
//层序遍历
void TreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* tmp = QueueFront(&q);
		QueuePop(&q);
		
			printf("%d ", tmp->data);
			if (tmp->left)
				QueuePush(&q, tmp->left);
			if (tmp->right)
				QueuePush(&q, tmp->right);
	}
	QueueDestroy(&q);
}
// 判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root);


int main()
{
	BTNode* root=CreatBinaryTree();
	//char a[] = "abc##de#g##f###";
	/*int i = 0;
	BTNode* root = Creat(a, &i);
	prevorder(root);
	printf("\n");*/
	//inorder(root);
	//printf("\n");
	//postorder(root);
	//printf("\n");
	//printf("%d", TreeNode(root));
	printf("叶子节点数目：%d\n", TreeLeaves(root));
	printf("树高度：%d\n", TreeHeight(root));
	printf("第三层节点数：%d\n", TreekNode(root,3));
	printf("查找6：%d\n", BinaryTreeFind(root, 6)->data);
	TreeLevelOrder(root);
	

	
	return 0;
}