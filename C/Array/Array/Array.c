//Array.c

#include "Array.h"
#include <stdlib.h>
#include <memory.h>

void Create(Array* array, Long capacity, size_t size) {
	array->front = calloc(capacity, size);
	array->capacity = capacity;
	array->length = 0;
}

Long Store(Array* array, Long index, void* object, size_t size) {
	memcpy(((char(*))array->front) + (index * size), object, size);
	(array->length)++;
	
	return index;
}

Long Insert(Array* array, Long index, void* object, size_t size) {
	void(*temp);
	Long i = 0;

	temp = calloc(array->capacity + 1, size);

	while (i < index) {
		memcpy(((char(*))temp) + (i * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	while (i < array->length) {
		memcpy(((char(*))temp) + ((i + 1) * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
	}
	array->front = temp;
	(array->capacity)++;
	memcpy(((char(*))array->front) + (index * size), object, size);
	(array->length)++;
	
	return index;
}

Long AppendFromFront(Array* array, void* object, size_t size) {
	Long index = 0;
	void(*temp);
	Long i = 0;

	temp = calloc(array->capacity + 1, size);
	while (i < array->length) {
		memcpy(((char(*))temp + ((i + 1)) * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
	}
	array->front = temp;
	(array->capacity)++;
	memcpy(((char(*))array->front) + (index * size), object, size);
	(array->length)++;

	return index;
}

Long AppendFromRear(Array* array, void* object, size_t size) {
	Long index;
	void(*temp);
	Long i = 0;

	temp = calloc(array->capacity + 1, size);
	while (i < array->length) {
		memcpy(((char(*))temp) + (i * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
	}
	array->front = temp;
	(array->capacity)++;
	index = array->capacity - 1;
	memcpy(((char(*))array->front) + (index * size), object, size);
	(array->length)++;

	return index;
}

Long Delete(Array* array, Long index, size_t size) {
	void(*temp) = NULL;
	Long i = 0;

	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
		
	}
	while (i < index) {
		memcpy(((char(*))temp) + (i * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	i++;
	while (i < array->length) {
		memcpy(((char(*))temp) + ((i - 1) * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1) {
		array->front = temp;
	}
	(array->length)--;
	(array->capacity)--;
	index = -1;

	return index;
}

Long DeleteFromFront(Array* array, size_t size) {
	void(*temp) = NULL;
	Long i = 1;
	Long index;

	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}
	while (i < array->length) {
		memcpy(((char(*))temp) + ((i - 1) * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1) {
		array->front = temp;
	}
	(array->length)--;
	(array->capacity)--;
	index = -1;

	return index;
}

Long DeleteFromRear(Array* array, size_t size) {
	void(*temp)=NULL;
	Long i = 0;
	Long index;

	if (array->capacity > 1) {
		temp = calloc(array->capacity - 1, size);
	}
	while (i < array->capacity-1) {
		memcpy(((char(*))temp) + (i * size), ((char(*))array->front) + (i * size), size);
		i++;
	}
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	if (array->capacity > 1) {
		array->front = temp;
	}
	(array->length)--;
	(array->capacity)--;
	index = -1;
	return index;
}

void Clear(Array* array) {
	if (array->front != NULL) {
		free(array->front);
		array->front = NULL;
	}
	array->length = 0;
	array->capacity = 0;
}

Long Modify(Array* array, Long index, void* object, size_t size) {
	memcpy(((char(*))array->front) + (index * size), object, size);
	return index;
}

Long LinearSearchUnique(Array* array, void* key, size_t size, int (*compare)(void*, void*)) {
	Long index = -1;
	Long i = 0;

	while (i < array->length && compare(((char(*))array->front) + (i * size), key) != 0) {
		i++;
	}
	if (i < array->length) {
		index = i;
	}

	return index;
}

void LinearSearchDuplicate(Array* array, void* key, Long* (*indexes), Long* count, size_t size, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j = 0;

	*count = 0;
	
	*indexes = (Long(*))calloc(array->length, sizeof(Long));
	while (i < array->length) {
		

		if (compare(((char(*))array->front) + (i * size), key) == 0) {
			(*indexes)[j] = i;
			j++;
			(*count)++;
		}
		i++;
	}
	
}

Long BinarySearchUnique(Array* array, void* key, size_t size, int (*compare)(void*, void*)) {
	Long index = -1;
	Long low = 0;
	Long high = array->length - 1;
	Long middle = (low + high) / 2;

	while (low <= high && compare(((char(*))array->front) + (middle * size), key) != 0) {
		if (compare(((char(*))array->front) + (middle * size), key) < 0) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
		middle = (low + high) / 2;
	}
	if (low <= high) {
		index = middle;
	}
	return index;
}

void BinarySearchDuplicate(Array* array, void* key, Long* (*indexes), Long* count, size_t size, int(*compare)(void*, void*)) {
	Long low = 0;
	Long high = array->length - 1;
	Long middle = (low + high) / 2;
	Long i = 0;
	Long index = -1;
	*count = 0;
	
	*indexes = (Long(*))calloc(array->length, sizeof(Long));
	while (low <= high && compare(((char(*))array->front) + (middle * size), key) != 0) {
		if (compare(((char(*))array->front) + (middle * size),key) < 0) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
		middle = (low + high) / 2;
	}
	index = middle - 1;
	while (index >= 0 && compare(((char(*))array->front) + (index * size), key) == 0) {
		index--;
	}
	index++;
	while (index < array->length && compare(((char(*))array->front) + (index * size), key) == 0) {
		(*indexes)[i] = index;
		i++;
		(*count)++;
		index++;
	}
}

void SelectionSort(Array* array, size_t size, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j;
	Long indexLow;
	void* temp;
	
	temp = malloc(size);

	while (i < array->length - 1) {
		indexLow = i;
		j = i + 1;
		while (j < array->length) {
			if (compare(((char(*))array->front) + (indexLow * size), ((char(*))array->front) + (j * size)) > 0) {
				indexLow = j;
			}
			j++;
		}
		memcpy(temp, ((char(*))array->front) + (i * size), size);
		memcpy(((char(*))array->front) + (i * size), ((char(*))array->front) + (indexLow * size), size);
		memcpy(((char(*))array->front) + (indexLow * size), temp, size);
		i++;
	}
	if (temp != NULL) {
		free(temp);
	}
}

void BubbleSort(Array* array, size_t size, int(*compare)(void*, void*)) {
	Long i;
	void* temp;
	Long k = array->length;
	Long count = 1;

	temp = malloc(size);
	while (k >= 0 && count > 0) {
		count = 0;
		i = 0;
		while (i < k - 1) {
			if (compare(((char(*))array->front) + (i * size), ((char(*))array->front) + ((i + 1) * size)) > 0) {
				memcpy(temp, ((char(*))array->front) + (i * size), size);
				memcpy(((char(*))array->front) + (i * size), ((char(*))array->front) + ((i+1) * size), size);
				memcpy(((char(*))array->front) + ((i + 1) * size), temp, size);
				count++;
			}
			i++;
		}
		k--;
	}
	if (temp != NULL) {
		free(temp);
	}
}

void InsertionSort(Array* array, size_t size, int(*compare)(void*, void*)) {
	void* temp;
	Long i = 1;
	Long j;
	
	temp = malloc(size);
	while (i < array->length) {
		memcpy(temp, ((char(*))array->front) + (i * size), size);
		j = i - 1;
		while (j >= 0 && compare(((char(*))array->front) + (j * size), temp) > 0) {
			memcpy(((char(*))array->front) + ((j + 1) * size), ((char(*))array->front) + (j * size), size);
			j--;
		}
		memcpy(((char(*))array->front) + ((j + 1) * size), temp, size);
		i++;
	}
	if (temp != NULL) {
		free(temp);
	}
}

void Merge(Array* array, Array* one, Array* other, size_t size, int(*compare)(void*, void*)) {
	Long i = 0;
	Long j = 0;
	Long k = 0;

	if (array->front != NULL) {
		free(array->front);
	}
	array->front = calloc(one->length + other->length, size);
	array->capacity = one->length + other->length;
	array->length = 0;

	while (i < one->length && j < other->length) {
		if (compare(((char(*))one->front) + (i * size), ((char(*))other->front) + (j * size)) < 0) {
			memcpy(((char(*))array->front) + (k * size), ((char(*))one->front) + (i * size), size);
			k++;
			(array->length)++;
			i++;
		}
		else {
			memcpy(((char(*))array->front) + (k * size), ((char(*))other->front) + (j * size), size);
			k++;
			(array->length)++;
			j++;
		}

	}
	while (i < one->length) {
		memcpy(((char(*))array->front) + (k * size), ((char(*))one->front) + (i * size), size);
		k++;
		(array->length)++;
		i++;
	}
	while (j < other->length) {
		memcpy(((char(*))array->front) + (k * size), ((char(*))other->front) + (j * size), size);
		k++;
		(array->length)++;
		j++;
	}
}

void GetAt(Array* array, Long index, void* object, size_t size) {
	memcpy(object, ((char(*))array->front) + (index * size), size);
}


void Destroy(Array* array) {
	if (array->front != NULL) {
		free(array->front);
	}
}
