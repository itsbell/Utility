//Main.c

#include "BinaryTree.h"
#include <stdio.h>

void Node_Print(BinaryNode* node);

int main(int argc, char* argv[]) {
	BinaryTree binaryTree;
	BinaryNode* index;
	int ret;
	int number;

	Create(&binaryTree);

	number = 20;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index ,&ret, sizeof(int));
	printf("%d\n", ret);

	number = 20;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}

	number = 20;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index ,&ret, sizeof(int));
	printf("%d\n", ret);

	number = 10;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 5;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 15;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 25;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 23;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 35;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 50;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 55;
	index = Insert(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 55;
	index = Search(&binaryTree, &number, sizeof(int),Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 20;
	index = Search(&binaryTree, &number, sizeof(int),Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 35;
	index = Search(&binaryTree, &number, sizeof(int), Compare);
	GetAt(&binaryTree, index, &ret, sizeof(int));
	printf("%d\n", ret);

	number = 20;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}

	number = 55;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}

	number = 25;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}
	
	number = 15;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("���������ϴ�.\n");
	}

	
	MakeBalance(&binaryTree, sizeof(int));

	Node_Print(binaryTree.root);


	

	Destroy(&binaryTree);

	return 0;
}

/*
�Լ���Ī: Node_Print
��    ��: key�� ���� �� ��, Ʈ���� ��� �غ��� �Լ�
��    ��: node
��    ��: ����
*/
void Node_Print(BinaryNode* node) {
	int ret;

	if (node != NULL) {
		memcpy(&ret, node + 1, sizeof(int));
		printf("%d\n", ret);
		Node_Print(node->left);
		Node_Print(node->right);
	}
	else {
		printf("NULL\n");
	}
}