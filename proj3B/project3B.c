#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "project3B_deque.h"

int main(int argc, char* argv[]) 
{
	Deque* longQue = createDeque();
	Deque* strQue = createDeque();
	long number = 0;

	char input[100];
	char* endptr;

	int i = 1; 
	int j = 1;

	do {
		printf("Please enter an integer or a string (empty to exit): ");
		fgets(input, sizeof(input), stdin);
		printf("\n");

		if (input[0] == '\n') {
			break;
		}

		if (input[strlen(input) - 1] == '\n') {
			input[strlen(input) - 1] = '\0';
		}
		number = strtol(input, &endptr, 10);

		if (*endptr == '\0') {
			if (i % 2 == 1) {
				insertFront(longQue, &number, sizeof(long));
			} else {
				insertBack(longQue, &number, sizeof(long));
			}
			printf("You entered the number: %ld\n", number);
			i++;
		} else {
			if (j % 2 == 1) {
				insertFront(strQue, input, strlen(input) + 1);
			} else {
				insertBack(strQue, input, strlen(input) + 1);
			}
			printf("You entered the string: \"%s\"\n", input);
			j++;
		}
	} while (1);

	printf("\n");
	printf("Printing string deque\n");
	printDeque(strQue, printString);
	printf("\n");
	printf("Printing long deque\n");
	printDeque(longQue, printLong);
	printf("\n");
	printf("Removing string deque data using count\n");
	j = strQue->count;
	while (j != 0) {
		if (j % 2 == 1) {
			removeFront(strQue, input, sizeof(input));
		} else {
			removeBack(strQue, input, sizeof(input));
		}
		printf("Removing %s\n", input);
		j--;
	}
	printf("\n");
	printf("Removing long deque data using count\n");
	i = longQue->count;
	while (i != 0) {
		if (i % 2 == 1) {
			removeFront(longQue, &number, sizeof(long));
		} else {
			removeBack(longQue, &number, sizeof(long));
		}
		printf("Removing %ld\n", number);
		i--;
	}

	freeDeque(longQue);
	freeDeque(strQue);

	return 0;
}
