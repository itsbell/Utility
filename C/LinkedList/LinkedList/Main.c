//Main.c

#include "LinkedList.h"
#include <stdio.h>

int CompareNumbers(void* one, void* other);

int main(int argc, char* argv[]) {
	LinkedList linkedList;
	Node* it;
	Node* previous;
	Node* (*indexes);
	int count;
	int i;
	int object;
	int ret;

	Create(&linkedList);
	
	object = 5;
	it = AppendFromTail(&linkedList, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	object = 7;
	it = AppendFromTail(&linkedList, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 3;
	it = AppendFromHead(&linkedList, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

	it = First(&linkedList);
	object = 1;
	it = InsertBefore(&linkedList, it, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);
	
	it = First(&linkedList);
	object = 2;
	it = InsertAfter(&linkedList, it, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 3;
	it = LinearSearchUnique(&linkedList, &object, sizeof(int), CompareNumbers);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 7;
	it = AppendFromTail(&linkedList, &object, sizeof(int));
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

#if 0

	DeleteAllItems(&linkedList);
	if (linkedList.length == 0) {
		printf("지워졌습니다.\n");
	}
#endif


	printf("-------------------------------------------------------------------------------\n");
	object = 7;
	LinearSearchDuplicate(&linkedList, &object,sizeof(int), &indexes, &count, CompareNumbers);

	i = 0;
	while (i < count) {
		GetAt(&linkedList, indexes[i], &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}

	if (indexes != NULL) {
		free(indexes);
	}
	printf("-------------------------------------------------------------------------------\n");

	it = DeleteFromHead(&linkedList);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}

	printf("-------------------------------------------------------------------------------\n");
	it = DeleteFromTail(&linkedList);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}

	printf("-------------------------------------------------------------------------------\n");
	it = First(&linkedList);
	it = Next(&linkedList);
	it = Next(&linkedList);
	it = Delete(&linkedList, it);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}


	printf("-------------------------------------------------------------------------------\n");
	it = First(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	printf("-------------------------------------------------------------------------------\n");
	it = Previous(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	printf("-------------------------------------------------------------------------------\n");
	it = Next(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	printf("-------------------------------------------------------------------------------\n");

	it = Last(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	printf("-------------------------------------------------------------------------------\n");
	it = Next(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);


	printf("-------------------------------------------------------------------------------\n");
	it = Previous(&linkedList);
	GetAt(&linkedList, it, &ret, sizeof(int));
	printf("%d\n", ret);

	printf("-------------------------------------------------------------------------------\n");
	it = First(&linkedList);
	it = Next(&linkedList);
	it = Delete(&linkedList, it);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}

	printf("-------------------------------------------------------------------------------\n");

	it = First(&linkedList);
	it = Delete(&linkedList, it);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}

	printf("-------------------------------------------------------------------------------\n");

	it = First(&linkedList);
	it = Delete(&linkedList, it);
	if (it == NULL) {
		printf("지워졌습니다.\n");
	}

	Destroy(&linkedList);

	return 0;
}

int CompareNumbers(void* one, void* other) {
	int* one_ = (int*)one;
	int* other_ = (int*)other;
	int ret;

	if (*one_ > *other_) {
		ret = 1;
	}

	else if (*one_ == *other_) {
		ret = 0;
	}

	else if (*one_ < *other_) {
		ret = -1;
	}
	return ret;
}