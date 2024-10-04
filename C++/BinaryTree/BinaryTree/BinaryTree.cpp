//BinaryTree.cpp
#define TREELEVEL 10
#include "BinaryTree.h"
#include <iostream>
using namespace std;

void ShowAll(BinaryTree<int>::Node* index);
int CompareNumbers(void* one, void* other);
void RecursivePrintTree(BinaryTree<int>::Node* node, Long level, Long currentLevel);
void PrintTree(BinaryTree<int>::Node* node, Long level);

int main(int argc, char* argv[]) {
	BinaryTree<int> binaryTree;
	BinaryTree<int>::Node* index;
	
	cout << "Insert: 20 " << endl;
	index = binaryTree.Insert(20, CompareNumbers);
	cout << index->GetKey()<<"\n" << endl;

	cout << "Delete: 20 " << endl;
	index = binaryTree.Delete(20, CompareNumbers);
	if (index == 0) {
		cout << "지워졌습니다.\n" << endl;
	}

	cout << "Insert: 20 " << endl;
	index = binaryTree.Insert(20, CompareNumbers);
	cout << index->GetKey()<<"\n" << endl;

	cout << "Insert: 10 " << endl;
	index = binaryTree.Insert(10, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 5 " << endl;
	index = binaryTree.Insert(5, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 15 " << endl;
	index = binaryTree.Insert(15, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 25 " << endl;
	index = binaryTree.Insert(25, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 23 " << endl;
	index = binaryTree.Insert(23, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 35 " << endl;
	index = binaryTree.Insert(35, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 50 " << endl;
	index = binaryTree.Insert(50, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Insert: 55 " << endl;
	index = binaryTree.Insert(55, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Search: 55 " << endl;
	index = binaryTree.Search(55, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Search: 20 " << endl;
	index = binaryTree.Search(20, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;

	cout << "Search: 35 " << endl;
	index = binaryTree.Search(35, CompareNumbers);
	cout << index->GetKey() << "\n" << endl;
	
	cout << "\n전체출력" << endl;
	ShowAll(binaryTree.GetRoot());
	cout << "===========\n" << endl;


	BinaryTree<int> copyBinaryTree(binaryTree);
	cout << "\n복사생성자" << endl;
	ShowAll(copyBinaryTree.GetRoot());
	cout << "===========\n" << endl;

	BinaryTree<int> otherBinaryTree;
	otherBinaryTree = binaryTree;
	cout << "\n치환연산자" << endl;
	ShowAll(copyBinaryTree.GetRoot());
	cout << "===========\n" << endl;

	cout << "Delete: 55 " << endl;
	index = binaryTree.Delete(55, CompareNumbers);
	if (index == 0) {
		cout << "지워졌습니다.\n"<< endl;
	}
	
	cout << "Delete: 25 " << endl;
	index = binaryTree.Delete(25, CompareNumbers);
	if (index == 0) {
		cout << "지워졌습니다.\n" << endl;
	}

	cout << "Delete: 15 " << endl;
	index = binaryTree.Delete(15, CompareNumbers);
	if (index == 0) {
		cout << "지워졌습니다.\n" << endl;
	}

	int(*keys);
	Long count ;
	
	binaryTree.MakeKeys(&keys, &count);

	cout << "MakeKeys of binaryTree" << endl;
	Long i = 0;
	while (i < count) {
		cout << keys[i] << endl;
		i++;
	}
	cout << "=====================\n" << endl;


	binaryTree.DeleteAllItems();
	
	binaryTree.MakeTree(keys,count);

	cout << "MakeTree of BinaryTree" << endl;
	ShowAll(binaryTree.GetRoot());
	cout << "=====================\n" << endl;


	if (keys != 0) {
		delete[] keys;
	}

	copyBinaryTree.MakeBalance();
	cout << "MakeTree of copyBinaryTree" << endl;
	PrintTree(copyBinaryTree.GetRoot(), 1);

	cout << "=====================\n" << endl;


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


void ShowAll(BinaryTree<int>::Node* index) {
	if (index != 0) {
		ShowAll(index->GetLeft());
		cout << index->GetKey() << endl;
		ShowAll(index->GetRight());
	}
}

void RecursivePrintTree(BinaryTree<int>::Node* node, Long level, Long currentLevel) {
	if (node != 0 && currentLevel <= level) {
		if (currentLevel == level) {
			cout << node->GetKey() << " ";
		}
		RecursivePrintTree(node->GetLeft(), level, currentLevel + 1);
		RecursivePrintTree(node->GetRight(), level, currentLevel + 1);
	}
}

void PrintTree(BinaryTree<int>::Node* node, Long level) {
	while (level <= TREELEVEL) {
		RecursivePrintTree(node, level, 1);
		cout << endl;
		level++;
	}
}