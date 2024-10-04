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
		printf("지워졌습니다.\n");
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
		printf("지워졌습니다.\n");
	}

	number = 55;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("지워졌습니다.\n");
	}

	number = 25;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("지워졌습니다.\n");
	}
	
	number = 15;
	index = Delete(&binaryTree, &number, sizeof(int), Compare);
	if (index == NULL) {
		printf("지워졌습니다.\n");
	}

	
	MakeBalance(&binaryTree, sizeof(int));

	Node_Print(binaryTree.root);


	

	Destroy(&binaryTree);

	return 0;
}

/*
함수명칭: Node_Print
기    능: key가 정수 일 때, 트리를 출력 해보는 함수
입    력: node
출    력: 없음
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