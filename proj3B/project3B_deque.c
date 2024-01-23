#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "project3B_deque.h"


Node *newNode(void *data, size_t dataSize) 
{

	Node* node = (Node*)malloc(sizeof(Node));

	if (node == NULL) {
		fprintf(stderr, "Error allocating memory for node. \n");
		exit(EXIT_FAILURE);
	}

	node->data = malloc(dataSize);

	if (node->data == NULL) {
		fprintf(stderr, "Error allocating memory for node data. \n");
		exit(EXIT_FAILURE);
	}

	memcpy(node->data, data, dataSize);

	node->next = NULL;
	node->prev = NULL;

	return node;
}


Deque *createDeque()
{

	Deque* deque = (Deque*)malloc(sizeof(deque));

	if (deque == NULL) {
		fprintf(stderr, "Error allocating memory for deque. \n");
		exit(EXIT_FAILURE);
	}

	deque->front = NULL;
	deque->back = NULL;

	return deque;


}


void insertFront(Deque *deque, void *data, size_t dataSize)
{

	Node *node = newNode(data, dataSize);

	if (deque->front == NULL) {
		deque->front = node;
		deque->back = node;
	}

	else {
		node->next = deque->front;
		deque->front->prev = node;
		deque->front = node;
	}
}


void insertBack(Deque *deque, void *data, size_t dataSize)
{
	Node *node = newNode(data, dataSize);

	if (deque->back == NULL) {
		deque->front = node;
		deque->back = node;
	}
	else {
		node->prev = deque->back;
		deque->back->next = node;
		deque->back = node;
	}
}


void removeFront(Deque *deque, void *data, size_t dataSize)
{
	if (deque->front == NULL) {
		fprintf(stderr, "Deque is empty.\n");
		exit(EXIT_FAILURE);
	}

	Node *Remove = deque->front;
	memcpy(data, Remove->data, dataSize);

	if (deque->front == deque->back) {
		deque->front = NULL;
		deque->back = NULL;
	}
	else {
		deque->front = deque->front->next;
		deque->front->prev = NULL;
	}

	free(Remove->data);
	free(Remove);
}


void removeBack(Deque *deque, void *data, size_t dataSize)
{
	if (deque->back == NULL) {
		fprintf(stderr, "Deque is empty.\n");
		exit(EXIT_FAILURE);
	}

	Node *Remove = deque->back;
	memcpy(data, Remove->data, dataSize);

	if (deque->front == deque->back) {
		deque->front = NULL;
		deque->back = NULL;
	}
	else {
		deque->back = deque->back->prev;
		deque->back->next = NULL;
	}

	free(Remove->data);
	free(Remove);
}


void freeDeque(Deque *deque)
{
	Node *current = deque->front;
	while (current != NULL) {
		Node* next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	free(deque);
}


void printDeque(Deque *deque, printData print)
{
	Node *current = deque->front;
	while (current != NULL) {
		print(current->data);
		current = current->next;
	}
	printf("\n");
}

void printString(void* data) {
	printf("%s ", (char*)data);
}

void printLong(void* data) {
	printf("%ld ", *(long*)data);
}