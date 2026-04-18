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
		return;
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
	return root==NULL?0: TreeNode(root->left) + TreeNode(root->right) + 1;
}
int main()
{
	BTNode* root=CreatBinaryTree();
	//prevorder(root);
	//printf("\n");
	//inorder(root);
	//printf("\n");
	//postorder(root);
	//printf("\n");
	printf("%d", TreeNode(root));
	return 0;
}