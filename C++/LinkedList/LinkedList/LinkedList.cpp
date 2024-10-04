//LinkedList.cpp
#include "LinkedList.h"
#include <iostream>
using namespace std;

int CompareIntegers(void* one, void* other);

int main(int argc, char* argv[]) {
	LinkedList<int> linkedList;
	LinkedList<int>::Node* it;
	int ret;

	it = linkedList.AppendFromTail(5);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.AppendFromTail(7);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.AppendFromHead(3);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.First();
	it = linkedList.InsertBefore(it, 1);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.First();
	it = linkedList.InsertAfter(it, 2);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.AppendFromTail(7);
	ret = linkedList.GetAt(it);
	cout << ret << endl;


	LinkedList<int> anotherLinkedList(linkedList);
	anotherLinkedList.First();
	LinkedList<int>::Node* previous = 0;
	it = anotherLinkedList.GetHead();
	cout << " * 복사생성자 * "<< endl;
	while (it != previous) {
		ret = anotherLinkedList.GetAt(it);
		cout << ret << endl;
		previous = it;
		it = anotherLinkedList.Next();
	}
	cout << " * --------- * " << endl;

	LinkedList<int> otherLinkedList;
	otherLinkedList = anotherLinkedList;
	otherLinkedList.First();
	previous = 0;
	it = otherLinkedList.GetHead();
	cout << " * 치환연산자 * " << endl;
	while (it != previous) {
		ret = otherLinkedList.GetAt(it);
		cout << ret << endl;
		previous = it;
		it = otherLinkedList.Next();
	}
	cout << " * --------- * " << endl;
	
	int key = 3;
	it = linkedList.LinearSearchUnique(&key, CompareIntegers);
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	LinkedList<int>::Node* (*indexes);
	Long count;
	key = 7;
	linkedList.LinearSearchDuplicate(&key, &indexes, &count, CompareIntegers);
	Long i = 0;
	while (i < count) {
		ret = linkedList.GetAt(indexes[i]);
		cout << ret << endl;
		i++;
	}
	if (indexes != 0) {
		delete indexes;
	}

	it = linkedList.DeleteFromHead();
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	it = linkedList.DeleteFromTail();
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	it = linkedList.First();
	it = linkedList.Next();
	it = linkedList.Next();
	it = linkedList.Delete(it);
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	it = linkedList.First();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.Previous();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.Next();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.Last();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.Next();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	it = linkedList.Previous();
	ret = linkedList.GetAt(it);
	cout << ret << endl;

	ret = linkedList[0];
	cout << "[1]번째: " << ret << endl;

	ret = linkedList[1];
	cout << "[2]번째: " << ret << endl;

	ret = linkedList[2];
	cout << "[3]번째: " << ret << endl;

	it = linkedList.First();
	it = linkedList.Next();
	it = linkedList.Delete(it);
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	it = linkedList.First();
	it = linkedList.Delete(it);
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	it = linkedList.First();
	it = linkedList.Delete(it);
	if (it == 0) {
		cout << "지워졌습니다." << endl;
	}

	ret = linkedList.GetLength();
	cout << "남은개수: " << ret << endl;

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