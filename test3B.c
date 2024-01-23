/*--- Tien's Note: This file tests your implementation of _deque ---*/
// createDeque, insertFront, insertBack, removeFront, removeBack are being tested, in various orders
// newNode is being implicitly tested inside insert functions
// printDeque is being tested with the .scr files
// freeDeque can be checked using valgrind
// You're welcome to write more test cases, or report any incorrect cases
// Some higher lv classes actually require you to write your own unittest

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project3B_deque.h"

#define MAX_STR_LEN 256

int main() {
	// Test createDeque()
	Deque * dq = createDeque();
	if (!dq || dq->back || dq->front || dq->count != 0) {
		printf("Creating deque\n");
		printf("deque object created wrong\n");
	}
	
	// Sample data
	long int n1 = 123;
	long int n2 = 456;
	char * s1 = strdup("abc");
	char * s2 = strdup("def");

	// Placeholder for return value
	long int numHolder = 0;
	char stringHolder[MAX_STR_LEN] = "";


	// Test insert front
	insertFront(dq, &n1, sizeof(long int));
	insertFront(dq, s1, strlen(s1) + 1);

	if (!dq->back || !dq->front) {
		printf("Inserting front:\n");
		printf("Nodes shouldn't be NULL!\n");
	} else if (dq->front->next != dq->back || dq->back->prev != dq->front) {
		printf("Inserting front:\n");
		printf("next & prev are not properly assigned\n");
	} else {
		if (*(long int *)dq->back->data != n1) {
			printf("Inserting front:\n");
			printf("long data is not assigned correctly\n");
		}
		if (strcmp((char *)dq->front->data, s1) != 0) {
			printf("Inserting front:\n");
			printf("string data is not assigned correctly\n");
		}
		if (dq->count != 2) {
			printf("Inserting front:\n");
			printf("deque size is wrong\n");
		}
	}


	// Test insert back
	insertBack(dq, &n2, sizeof(long int));
	insertBack(dq, s2, strlen(s2) + 1);

	if (!dq->back || !dq->front) {
		printf("Inserting back:\n");
		printf("Nodes shouldn't be NULL!\n");
	} else if (!dq->front->next || !dq->front->next->next || dq->front->next->next->next != dq->back 
		|| !dq->back->prev || !dq->back->prev->prev || dq->back->prev->prev->prev != dq->front) {
		printf("Inserting back:\n");
		printf("next & prev are not properly assigned\n");
	} else {
		if (*(long int *)dq->back->prev->data != n2
			|| *(long int *)dq->front->next->data != n1) {
			printf("Inserting back:\n");
			printf("long data is not assigned correctly\n");
		}
		if (strcmp((char *)dq->front->data, s1) != 0
			|| strcmp((char*)dq->back->data, s2) != 0 ) {
			printf("Inserting back:\n");
			printf("string data is not assigned correctly\n");
		}
		if (dq->count != 4) {
			printf("Inserting back:\n");
			printf("deque size is wrong\n");
		}
	}


	// Test remove front
	removeFront(dq, stringHolder, MAX_STR_LEN);
	removeFront(dq, &numHolder, sizeof(long int));

	// if (strcmp(stringHolder, "") == 0 || numHolder == 0) {
	// 	printf("Removing front:\n");
	// 	printf("Return string not stored\n");
	// } else if (strcmp(stringHolder, s1) != 0) {
	// 	printf("Removing front:\n");
	// 	printf("Incorrect return string value\n");
	// } else if (numHolder != n1) {
	// 	printf("Removing front:\n");
	// 	printf("Incorrect return long value\n");
	// }

	if (!dq->back || !dq->front) {
		printf("Removing front:\n");
		printf("Nodes shouldn't be NULL!\n");
	} else if (dq->front->next != dq->back || dq->back->prev != dq->front) {
		printf("Removing front:\n");
		printf("next & prev are not properly assigned\n");
	} else {
		if (*(long int *)dq->back->prev->data != n2) {
			printf("Removing front:\n");
			printf("long data is not assigned correctly\n");
		}
		if (strcmp((char *)dq->front->next->data, s2) != 0) {
			printf("Removing front:\n");
			printf("string data is not assigned correctly\n");
		}
		if (dq->count != 2) {
			printf("Removing front:\n");
			printf("deque size is wrong\n");
		}
	}

	// Test remove back
	removeBack(dq, stringHolder, MAX_STR_LEN);
	removeBack(dq, &numHolder, sizeof(long int));

	// if (strcmp(stringHolder, "") == 0 || numHolder == 0) {
	// 	printf("Removing back:\n");
	// 	printf("Return string not stored\n");
	// } else if (strcmp(stringHolder, s2) != 0) {
	// 	printf("Removing back:\n");
	// 	printf("Incorrect return string value\n");
	// } else if (numHolder != n2) {
	// 	printf("Removing back:\n");
	// 	printf("Incorrect return long value\n");
	// }

	if (dq->back || dq->front) {
		printf("Removing back:\n");
		printf("Remove all data, nodes should be EMPTY!\n");
	}
	if (dq->count != 0) {
		printf("Removing back:\n");
		printf("deque size is wrong\n");
	}


	// Test insert, remove one element
	insertBack(dq, &n1, sizeof(long int));
	if (!dq->back || !dq->front) {
		printf("Inserting back:\n");
		printf("Nodes shouldn't be NULL!\n");
	} else if (dq->front != dq->back) {
		printf("Inserting back:\n");
		printf("front & back are not properly assigned\n");
	}

	removeFront(dq, &numHolder, sizeof(long int));
	if (dq->back || dq->front) {
		printf("Removing front:\n");
		printf("Remove all data, nodes should be EMPTY!\n");
	}


	// Note: Memory check needs to bedone separately using valgrind
	freeDeque(dq);
	free(s1);	// strdup also allocates memory, so free it
	free(s2);

	return 0;
}





