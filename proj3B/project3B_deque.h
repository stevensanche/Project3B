#ifndef PROJECT3B_DEQUE_H
#define PROJECT3A_DEQUE_H
#include <stddef.h>



typedef struct Node
{
  void *data;
  struct Node *next;
  struct Node *prev;
} Node;


typedef struct Deque
{
  Node *front;
  Node *back;
  int count;
} Deque;


typedef void (*printData)(void *);


Node *newNode(void *data, size_t dataSize);
Deque *createDeque();
void insertFront(Deque *deque, void *data, size_t dataSize);
void insertBack(Deque *deque, void *data, size_t dataSize);
void removeFront(Deque *deque, void *data, size_t dataSize);
void removeBack(Deque *deque, void *data, size_t dataSize);
void freeDeque(Deque *deque);
void printDeque(Deque *deque, printData print);
void printString(void* data);
void printLong(void* data);

#endif 