//ListedList.h
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef signed long int Long;

template <typename T>

class LinkedList {
	//Nested class
	public:
		class Node {
			friend class LinkedList;
			public:
				Node() {
					this->previous = this;
					this->next = this;
				}

				Node(T object) {
					this->previous = this;
					this->object = object;
					this->next = this;
				}

				Node(T object, Node* next) {
					this->previous = this;
					this->object = object;
					this->next = next;
				}

				Node(Node* previous, T object) {
					this->previous = previous;
					this->object = object;
					this->next = this;
				}

				Node(T object, Node* previous, Node* next) {
					this->previous = previous;
					this->object = object;
					this->next = next;
				}

				Node(const Node& source) {
					this->previous = source.previous;
					this->object = source.object;
					this->next = source.next;
				}

				~Node() {

				}

				Node& operator = (const Node& source) {
					this->previous = source.previous;
					this->object = source.object;
					this->next = source.next;

					return *this;
				}

				T& GetObject() const {
					return const_cast<T&> (this->object);
				}

			private:
				Node* previous;
				T object;
				Node* next;
		};

	public:
		LinkedList();
		LinkedList(const LinkedList& source);
		~LinkedList();
		Node* InsertBefore(Node* index, T object);
		Node* InsertAfter(Node* index, T object);
		Node* AppendFromHead(T object);
		Node* AppendFromTail(T object);
		Node* Delete(Node* index);
		Node* DeleteFromHead();
		Node* DeleteFromTail();
		void DeleteAllItems();
		Node* LinearSearchUnique(void* key, int(*compare)(void*, void*));
		void LinearSearchDuplicate(void* key, Node** (*indexes), Long* count, int(*compare)(void*, void*));
		Node* First();
		Node* Previous();
		Node* Next();
		Node* Last();
		Node* Move(Node* index);

		T& GetAt(Node* index);
		LinkedList& operator = (const LinkedList& source);
		T& operator [](Long index);
		Node* GetHead() const;
		Node* GetTail() const;
		Node* GetCurrent() const;
		Long GetLength() const;

	private:
		Node* head;
		Node* tail;
		Long length;
		Node* current;
};


template <typename T>
LinkedList<T>::LinkedList() {
	this->head = 0;
	this->tail = 0;
	this->length = 0;
	this->current = 0;

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& source) {
	Node* previous = 0;
	Node* it;
	Node* temp = 0;

	this->head = 0;
	this->tail = 0;
	this->length = 0;
	this->current = 0;

	it = source.head;
	while (it != previous) {
		if (this->tail != 0) {
			this->current = new Node(this->tail, it->object);
		}
		else {
			this->current = new Node(it->object);
		}

		if (this->tail != 0) {
			this->tail->next = this->current;
		}

		else {
			this->head = this->current;
		}
			
		this->tail = this->current;
		this->length++;

		if (it == source.current) {
			temp = this->current;
		}

		previous = it;
		it = it->next;
	}
	this->current = temp;

}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* it = this->head;
	Node* previous = 0;

	while (it != previous) {
		this->head = it->next;
		previous = it;
		if (it != 0) {
			delete it;
		}
		it = this->head;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertBefore(Node* index, T object) {
	
	if (this->head != index) {
		this->current = new Node(object, index->previous, index);
	}
	else {
		this->current = new Node(object, index);
	}

	if (this->head != index) {
		index->previous->next = this->current;
	}
	else {
		this->head = this->current;
	}

	index->previous = this->current;
	this->length++;

	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(Node* index, T object) {
	
	if (this->tail != index) {
		this->current = new Node(object, index, index->next);
	}
	else {
		this->current = new Node(index, object);
	}

	if (this->tail != index) {
		index->next->previous = this->current;
	}
	else {
		this->tail = this->current;
	}

	index->next = this->current;
	this->length++;

	return this->current;
		
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromHead(T object) {
	if (this->head != 0) {
		this->current = new Node(object, this->head);
	}
	else {
		this->current = new Node(object);
	}

	if (this->head != 0) {
		this->head->previous = this->current;
	}
	else {
		this->tail = this->current;
	}

	this->head = this->current;
	this->length++;

	return this->current;
}


template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromTail(T object) {
	if (this->tail != 0) {
		this->current = new Node(this->tail, object);
	}
	else {
		this->current = new Node(object);
	}

	if (this->tail != 0) {
		this->tail->next = this->current;
	}
	else {
		this->head = this->current;
	}

	this->tail = this->current;
	this->length++;

	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::LinearSearchUnique(void* key, int(*compare)(void*, void*)) {
	Node* previous = 0;
	Node* index = 0;
	Node* it = this->head;

	while (it != previous && compare(&(it->object), key) != 0) {
		previous = it;
		it = it->next;
	}

	if (it != previous) {
		index = it;
	}

	return index;
}

template <typename T>
void LinkedList<T>::LinearSearchDuplicate(void* key, Node** (*indexes), Long* count, int(*compare)(void*, void*)) {
	Node* it;
	*indexes = new Node * [this->length];
	*count = 0;
	Long i = 0;
	Node* previous = 0;
	it = this->head;

	while (previous != it) {
		if (compare(&(it->object), key)==0) {
			(*indexes)[i] = it;
			i++;
			(*count)++;
		}
		previous = it;
		it = it->next;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromHead() {
	Node* index = this->head;
	if (this->tail != index) {
		index->next->previous = index->next;
		this->head = index->next;
		this->current = index->next;
	}

	else {
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0) {
		delete index;
		index = 0;
	}

	this->length--;

	return index;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromTail() {
	Node* index = this->tail;
	if (this->head != index) {
		index->previous->next = index->previous;
		this->tail = index->previous;
		this->current = index->previous;
	}

	else {
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0) {
		delete index;
		index = 0;
	}
	this->length--;

	return index;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Delete(Node* index) {
	if (this->head != index && this->tail != index) {
		index->previous->next = index->next;
		index->next->previous = index->previous;
		this->current = index->next;
	}

	else if (this->tail == index && this->head != index) {
		index->previous->next = index->previous;
		this->tail = index->previous;
		this->current = index->previous;
	}

	else if (this->head == index && this->tail != index) {
		index->next->previous = index->next;
		this->head = index->next;
		this->current = index->next;
	}
	else {
		this->head = 0;
		this->tail = 0;
		this->current = 0;
	}

	if (index != 0) {
		delete index;
		index = 0;
	}
	this->length--;

	return index;

}

template <typename T>
void LinkedList<T>::DeleteAllItems() {
	Node* previous = 0;
	Node* it = this->head;
	while (it != previous) {
		this->head = it->next;
		previous = it;
		if (it != 0) {
			delete it;
		}
		it = this->head;
	}

	this->head = 0;
	this->tail = 0;
	this->current = 0;
	this->length = 0;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::First() {
	this->current = this->head;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Previous() {
	this->current = this->current->previous;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Next() {
	this->current = this->current->next;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Last() {
	this->current = this->tail;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Move(Node* index) {
	this->current = index;
	return this->current;
}

template <typename T>
T& LinkedList<T>::GetAt(Node* index) {
	return index->object;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList& source) {
	Node* it = this->head;
	Node* previous = 0;
	while (it != previous) {
		this->head = it->next;
		previous = it;
		if (it != 0) {
			delete it;
		}
		it = this->head;
	}
	Node* temp = 0;

	this->head = 0;
	this->tail = 0;
	this->length = 0;
	this->current = 0;
	
	it = source.head;

	while (it != previous) {
		
		if (this->tail != 0) {
			this->current = new Node(this->tail, it->object);
		}
		
		else {
			this->current = new Node(it->object);
		}

		if (this->tail != 0) {
			this->tail->next = this->current;
		}

		else {
			this->head = this->current;
		}

		this->tail = this->current;
		this->length++;

		if (it == source.current) {
			temp = this->current;
		}

		previous = it;
		it = it->next;
			
	}
	this->current = temp;

	return *this;
}

template <typename T>
T& LinkedList<T>::operator[](Long index) {
	Long i = 0;
	Node* it = this->head;
	while (i < index) {
		it = it->next;
		i++;
	}
	return it->object;
}


template <typename T>
typename inline LinkedList<T>::Node* LinkedList<T>::GetHead() const {
	return const_cast<Node*> (this->head);
}

template <typename T>
typename inline LinkedList<T>::Node* LinkedList<T>::GetTail() const {
	return const_cast<Node*>(this->tail);
}

template <typename T>
typename inline LinkedList<T>::Node* LinkedList<T>::GetCurrent() const {
	return const_cast<Node*>(this->current);
}

template <typename T>
typename inline Long LinkedList<T>::GetLength() const {
	return this->length;
}

#endif _LINKEDLIST_H
