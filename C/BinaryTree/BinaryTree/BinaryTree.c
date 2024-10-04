//BinaryTree.c

#include "BinaryTree.h"

void Create(BinaryTree* binaryTree) {
	binaryTree->root = NULL;
	binaryTree->length = 0;
	binaryTree->balance = 0;
}


BinaryNode* Insert(BinaryTree* binaryTree, void* key, size_t size, int (*compare)(void*, void*)) {
	BinaryNode* parents = NULL;
	BinaryNode* it = NULL;
	BinaryNode* index;

	index = (BinaryNode*)malloc(sizeof(BinaryNode) + size);

	index->left = NULL;
	memcpy(index + 1, key, size);
	index->right = NULL;

	it = binaryTree->root;
	while (it != NULL) {
		parents = it;
		if (compare(it + 1, key) > 0) {
			it = it->left;
		}
		else {
			it = it->right;
		}
	}

	if (parents != NULL) {
		if (compare(parents + 1, key) > 0) {
			parents->left = index;
		}
		else {
			parents->right = index;
		}

		if (compare(binaryTree->root + 1, index + 1) > 0) {
			(binaryTree->balance)--;
		}
		else {
			(binaryTree->balance)++;
		}
	}
	else {
		binaryTree->root = index;
	}
	(binaryTree->length)++;

	return index;
}

BinaryNode* Search(BinaryTree* binaryTree, void* key, size_t size, int(*compare)(void*, void*)) {
	BinaryNode* index;

	index = binaryTree->root;
	while (index != NULL && compare(index + 1, key) != 0) {
		if (compare(index + 1, key) > 0) {
			index = index->left;
		}
		else {
			index = index->right;
		}
	}
	return index;
}

BinaryNode* Delete(BinaryTree* binaryTree, void* key, size_t size, int(*compare)(void*, void*)) {
	BinaryNode* index;
	BinaryNode* parents = NULL;
	BinaryNode* change = NULL;
	BinaryNode* changeParents;
	BinaryNode* it;

	index = binaryTree->root;
	while (compare(index + 1, key) != 0) {
		parents = index;
		if (compare(index + 1, key) > 0) {
			index = index->left;
		}
		else {
			index = index->right;
		}
	}

	if (binaryTree->root->left != NULL || binaryTree->root->right != NULL) {
		it = index->left;
		while (it != NULL) {
			change = it;
			it = it->right;
		}

		if (index->left != NULL) {
			changeParents = index;
			it = index->left;
			while (it != change) {
				changeParents = it;
				it = it->right;
			}
			if (changeParents != index) {
				changeParents->right = change->left;
			}
		}

		it = index->right;
		while (index->left == NULL && it != NULL) {
			change = it;
			it = it->left;
		}

		if (index->left == NULL && index->right != NULL) {
			changeParents = index;
			it = index->right;
			while (it != change) {
				changeParents = it;
				it = it->left;
			}
			if (changeParents != index) {
				changeParents->left = change->right;
			}
		}
		if (compare(binaryTree->root + 1, index + 1) > 0) {
			(binaryTree->balance)++;
		}
		else if (compare(binaryTree->root + 1, index + 1) < 0) {
			(binaryTree->balance)--;
		}
		else if (compare(binaryTree->root + 1, change + 1) > 0) {
			(binaryTree->balance)++;
		}
		else {
			(binaryTree->balance)--;
		}

		if (parents != NULL) {
			if (change != NULL) {
				if (compare(parents + 1, change + 1) > 0) {
					parents->left = change;
				}
				else {
					parents->right = change;
				}
			}
			else {
				if (compare(parents + 1, index + 1) > 0) {
					parents->left = NULL;
				}
				else {
					parents->right = NULL;
				}
			}
		}
		else {
			binaryTree->root = change;
		}

		if (change != NULL && change != index->left) {
			change->left = index->left;
		}
		if (change != NULL && change != index->right) {
			change->right = index->right;
		}
	}
	else {
		binaryTree->root = NULL;
	}

	if (index != NULL) {
		free(index);
		index = NULL;
	}
	(binaryTree->length)--;

	return index;
}

void MakeBalance(BinaryTree* binaryTree, size_t size) {
	void(*keys);
	int count;
	
	MakeKeys(binaryTree, &keys, &count, size);

	DeleteAllItems(binaryTree);

	MakeTree(binaryTree, keys, count, size);
	
	if (keys != NULL) {
		free(keys);
	}

}

void MakeKeys(BinaryTree* binaryTree, void* (*keys), Long* count, size_t size) {
	Long i = 0;
	
	*count = 0;
	*keys = calloc(binaryTree->length, size);
	Node_MakeKeys(binaryTree->root, *keys, count, &i, size);
}

void Node_MakeKeys(BinaryNode* node, void(*keys), Long* count, Long* i, size_t size) {
	
	if (node != NULL) {
		Node_MakeKeys(node->left, keys, count, i,size);
		memcpy(((char(*))keys) + ((*i) * size), node + 1, size);
		(*i)++;
		(*count)++;
		Node_MakeKeys(node->right, keys, count, i, size);
	}
}

void DeleteAllItems(BinaryTree* binaryTree) {
	Node_DeleteAllItems(binaryTree->root);
	binaryTree->root = NULL;
	binaryTree->length = 0;
	binaryTree->balance = 0;
}

void Node_DeleteAllItems(BinaryNode* node) {
	if (node != NULL) {
		Node_DeleteAllItems(node->left);
		Node_DeleteAllItems(node->right);
		free(node);
	}
}

void MakeTree(BinaryTree* binaryTree, void(*keys), Long count, size_t size) {
	Long remainder;

	binaryTree->root = Node_MakeTree(keys, 0, count - 1, size);
	binaryTree->length = count;
	
	remainder = count % 2;
	if (remainder == 1) {
		binaryTree->balance = 0;
	}
	else {
		binaryTree->balance = 1;
	}
}

BinaryNode* Node_MakeTree(void(*keys), Long low, Long high, size_t size) {
	BinaryNode* node;
	Long middle;

	if (low <= high) {
		middle = (low + high) / 2;
		node = (BinaryNode*)malloc(sizeof(BinaryNode) + size);
		memcpy(node + 1, ((char(*))keys) + (middle * size), size);
		node->left = Node_MakeTree(keys, low, middle - 1, size);
		node->right = Node_MakeTree(keys, middle + 1, high, size);
	}
	else {
		node = NULL;
	}

	return node;
}

void GetAt(BinaryTree* binaryTree, BinaryNode* index, void* key, size_t size) {
	memcpy(key, index + 1, size);
}

void Node_Destroy(BinaryNode* node) {
	if (node != NULL) {
		Node_Destroy(node->left);
		Node_Destroy(node->right);
		free(node);
	}
}


void Destroy(BinaryTree* binaryTree) {
	Node_Destroy(binaryTree->root);
}

int Compare(void* one, void*other) {
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