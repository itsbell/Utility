//BinaryTree.h
#ifndef _BINARYTREE_T
#define _BINARYTREE_T

typedef signed long int Long;
template <typename T>
class BinaryTree {
	//Nested Class
	public:
		class Node {
			friend class BinaryTree;

		public:
			Node() {
				this->left = 0;
				this->right = 0;
			}
			Node(T key) {
				this->left = 0;
				this->key = key;
				this->right = 0;
			}
			Node(const Node& source) {
				this->key = source.key;
				if (source.left != 0) {
					this->left = new Node(*(source.left));
				}
				else {
					this->left = 0;
				}
				if (source.right != 0) {
					this->right = new Node(*(source.right));
				}
				else {
					this->right = 0;
				}
			}

			~Node() {
				if (this->left != 0) {
					delete this->left;
				}

				if (this->right != 0) {
					delete this->right;
				}
				
			}

			void MakeKeys(T(*keys), Long* count, Long* i) {
				if (this != 0) {
					this->left->MakeKeys(keys, count, i);
					keys[*i] = this->key;
					(*i)++;
					(*count)++;
					this->right->MakeKeys(keys, count, i);
				}
			}
			
			void DeleteAllItems() {
				if (this != 0) {
					this->left->DeleteAllItems();
					this->left = 0;
					this->right->DeleteAllItems();
					this->right = 0;
					delete this;
				}
			}

			Node* MakeTree(T(*keys), Long low, Long high) {
				Node* index;
				Long middle;

				if (low <= high) {
					middle = (low + high) / 2;
					index = new Node;
					index->key = keys[middle];
					index->left = index->MakeTree(keys, low, middle - 1);
					index->right = index->MakeTree(keys, middle + 1, high);
				}
				else {
					index = 0;
				}

				return index;
			}

			Node& operator = (const Node& source){
				this->key = source.key;
				if (source.left != 0) {
					this->left = new Node;
					*(this->left) = *(source.left);
				}

				if (source.right != 0) {
					this->right = new Node;
					*(this->right) = *(source.right);
				}
				return *this;
			}

			Node* GetLeft() {
				return const_cast<Node*> (this->left);
			}

			T& GetKey() {
				return const_cast<T&>(this->key);
			}

			Node* GetRight() {
				return const_cast<Node*>(this->right);
			}


		private:
			Node* left;
			T key;
			Node* right;
		};


	public:
		BinaryTree();
		BinaryTree(const BinaryTree& source);
		~BinaryTree();
		Node* Insert(T key, int(*compare)(void*, void*));
		Node* Search(T key, int(*compare)(void*, void*));
		Node* Delete(T key, int(*compare)(void*, void*));
		void MakeBalance();
		void MakeKeys(T* (*keys), Long(*count));
		void DeleteAllItems();
		void MakeTree(T(*keys), Long count);
		BinaryTree& operator = (const BinaryTree& source);
		Node* GetRoot() const;
		Long GetLength() const;
		Long GetBalance() const;

	private:
		Node* root;
		Long length;
		Long balance;
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	this->root = 0;
	this->length = 0;
	this->balance = 0;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& source) {
	if (source.root != 0) {
		this->root = new Node(*(source.root));
	}
	else {
		this->root = 0;
	}

	this->length = source.length;
	this->balance = source.balance;
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
	if (this->root != 0) {
		delete this->root;
	}
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::Insert(T key, int (*compare)(void*, void*)) {
	Node* index;
	Node* parents = 0;
	Node* it;

	index = new Node(key);
	it = this->root;
	while (it != 0) {
		parents = it;
		if (compare(&(it->key), &key) > 0) {
			it = it->left;
		}
		else {
			it = it->right;
		}
	}

	if (parents != 0) {
		if (compare(&(parents->key), &key) > 0) {
			parents->left = index;
		}
		else {
			parents->right = index;
		}
		if (compare(&(this->root->key), &(index->key)) > 0) {
			(this->balance)--;
		}
		else {
			(this->balance)++;
		}
	}
	else {
		this->root = index;
	}

	(this->length)++;

	return index;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::Search(T key, int (*compare)(void*, void*)) {
	Node* index;
	index = this->root;

	while (index != 0 && compare(&(index->key), &key) != 0) {
		if (compare(&(index->key), &key) > 0) {
			index = index->left;
		}
		else {
			index = index->right;
		}
	}
	return index;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::Delete(T key, int (*compare)(void*, void*)) {
	Node* index;
	Node* parents = 0;
	Node* change = 0;
	Node* changeParents;
	Node* it;

	index = this->root;

	while (compare(&(index->key), &key) != 0){
		parents = index;
		if (compare(&(index->key), &key) > 0) {
			index = index->left;
		}
		else{
			index = index->right;
		}
	}

	if (this->root->left != 0 || this->root->right != 0) {
		it = index->left;
		while (it != 0) {
			change = it;
			it = it->right;
		}
		if (index->left != 0) {
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

		while (index->left == 0 && it != 0) {
			change = it;
			it = it->left;
		}

		if (index->left == 0 && index->right != 0) {
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
		if (compare(&(this->root->key), &(index->key)) > 0) {
			(this->balance)++;
		}
		else if (compare(&(this->root->key), &(index->key)) < 0) {
			(this->balance)--;
		}
		else if (compare(&(this->root->key), &(change->key)) > 0) {
			(this->balance)++;
		}
		else {
			(this->balance)--;
		}

		if (parents != 0) {
			if (change != 0) {
				if (compare(&(parents->key), &(change->key)) > 0) {
					parents->left = change;
				}
				else {
					parents->right = change;
				}
			}
			else if (compare(&(parents->key), &(index->key)) > 0) {
				parents->left = 0;
			}
			else {
				parents->right = 0;
			}
		}
		else {
			this->root = change;
		}

		if (change != 0 && change != index->left) {
			change->left = index->left;
		}

		if (change != 0 && change != index->right) {
			change->right = index->right;
		}
	}

	else {
		this->root = 0;
	}

	if (index != 0) {
		index->left = 0;
		index->right = 0;
		delete index;
		index = 0;
	}

	(this->length)--;

	return index;
}



template <typename T>
void BinaryTree<T>::MakeBalance() {
	T(*keys);
	Long count;
	
	this->MakeKeys(&keys, &count);
	this->DeleteAllItems();
	this->MakeTree(keys, count);

	if (keys != 0) {
		delete[]keys;
	}
}

template <typename T>
void BinaryTree<T>::MakeKeys(T* (*keys), Long(*count)) {
	Long i = 0;
	*count = 0;
	*keys = new T[this->length];
	this->root->MakeKeys(*keys, count, &i);
}

template <typename T>
void BinaryTree<T>::DeleteAllItems() {
	this->root->DeleteAllItems();
	this->root;
	this->length = 0;
	this->balance = 0;
}

template <typename T>
void BinaryTree<T>::MakeTree(T(*keys), Long count) {
	Long middle;
	Long remainder;
	this->root = this->root->MakeTree(keys, 0, count - 1);
	this->length = count;
	middle = count / 2;
	remainder = count % middle;
	if (remainder == 1) {
		this->balance = 0;
	}
	else {
		this->balance = 1;
	}
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator = (const BinaryTree& source) {
	if (this->root != 0) {
		delete this->root;
	}
	if (source.root != 0) {
		this->root = new Node;
		*(this->root) = *(source.root);
	}
	this->length = source.length;
	this->balance = source.balance;

	return *this;
}

template <typename T>
typename inline BinaryTree<T>::Node* BinaryTree<T>::GetRoot() const {
	return const_cast<Node*>(this->root);
}

template <typename T>
inline Long BinaryTree<T>::GetLength() const{
	return this->length;
}

template<typename T>
inline Long BinaryTree<T>::GetBalance() const {
	return this->balance;
}

#endif //_BINARYTREE_H