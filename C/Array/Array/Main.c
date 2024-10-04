//Main.c
#include "Array.h"
#include <stdio.h>

int CompareIntegers(void* one, void* other);

int main(int argc, char* argv[]) {
	Array array;
	Array one;
	Array other;
	Long index;
	Long(*indexes);
	Long count;
	int object;
	int ret;
	int key;
	Long i;

	Create(&array, 4, sizeof(int));

	object = 3;
	index = Store(&array, 0, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 2;
	index = Store(&array, 1, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 1;
	index = Store(&array, 2, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 5;
	index = Store(&array, 3, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	SelectionSort(&array, sizeof(int), CompareIntegers);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}

	printf("이분검색유니크\n");
	key = 5;
	index = BinarySearchUnique(&array, &key, sizeof(int), CompareIntegers);
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);
	
	object = 2;
	index = Insert(&array, 1, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 2;
	index = AppendFromFront(&array, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(index));
	printf("%d\n", ret);

	object = 2;
	index = AppendFromRear(&array, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);


	key = 2;
	LinearSearchDuplicate(&array, &key, &indexes, &count, sizeof(int), CompareIntegers);
	
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}
	if (indexes != NULL) {
		free(indexes);
	}

	BubbleSort(&array, sizeof(int), CompareIntegers);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}

	printf("이분검색중복\n");
	key = 3;
	BinarySearchDuplicate(&array, &key, &indexes, &count, sizeof(int), CompareIntegers);
	i = 0;
	while (i < count) {
		GetAt(&array, indexes[i], &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}
	if (indexes != NULL) {
		free(indexes);
	}

	index = Delete(&array, 2, sizeof(int));
	if (index == -1) {
		printf("지워졌습니다.\n");
	}

	index = DeleteFromFront(&array, sizeof(int));
	if (index == -1) {
		printf("지워졌습니다.\n");
	}

	index = DeleteFromRear(&array, sizeof(int));
	if (index == -1) {
		printf("지워졌습니다.\n");
	}

	object = 10;
	index = Modify(&array, 0, &object, sizeof(int));
	GetAt(&array, index, &ret, sizeof(int));
	printf("%d\n", ret);

	Clear(&array);

	Create(&one, 3, sizeof(int));

	object = 3;
	index = Store(&one, 0, &object, sizeof(int));
	GetAt(&one, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 10;
	index = Store(&one, 1, &object, sizeof(int));
	GetAt(&one, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 1;
	index = Store(&one, 2, &object, sizeof(int));
	GetAt(&one, index, &ret, sizeof(int));
	printf("%d\n", ret);

	InsertionSort(&one, sizeof(int), CompareIntegers);
	i = 0;
	while (i < one.length) {
		GetAt(&one, i, &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}

	Create(&other, 3, sizeof(int));

	object = 2;
	index = Store(&other, 0, &object, sizeof(int));
	GetAt(&other, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 3;
	index = Store(&other, 1, &object, sizeof(int));
	GetAt(&other, index, &ret, sizeof(int));
	printf("%d\n", ret);

	object = 5;
	index = Store(&other, 2, &object, sizeof(int));
	GetAt(&other, index, &ret, sizeof(int));
	printf("%d\n", ret);

	Merge(&array, &one, &other, sizeof(int), CompareIntegers);
	i = 0;
	while (i < array.length) {
		GetAt(&array, i, &ret, sizeof(int));
		printf("%d\n", ret);
		i++;
	}
	
	
	Destroy(&one);
	Destroy(&other);
	Destroy(&array);

	return 0;
}

int CompareIntegers(void* one, void* other) {
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