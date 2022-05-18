#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 3

typedef char element;

element queue[Q_SIZE];
int front = -1, rear = -1;

void isEmpty() {
	printf("\n Queue is full! \n");
}

void isFull() {
	printf("\n Queue is full! \n");
}

void enQueue(element item) {
	if (rear >= Q_SIZE - 1) {
		isFull();
		exit(1);
	}
	else queue[++rear] = item;
}

element deQueue() {
	if (front == rear) {
		isEmpty();
		exit(1);
	}
	else return queue[++front];
}

void dek() {
	if (front == rear) {
		isEmpty();
		exit(1);
	}
	else front++;
}

element peek() {
	if (front == rear) {
		isEmpty();
		exit(1);
	}
	else return queue[front + 1];
}

void printQ() {
	int i;
	printf("\n Queue :[");
	for (i = front + 1; i <= rear; i++)
		printf("%3c", queue[i]);
	printf(" ]");
	printf("\t front = %d, rear = %d\n", front, rear);
}

int main(void) {
	element data;

	enQueue('A'); printQ();
	enQueue('B'); printQ();

	deQueue(); printQ();

	enQueue('C'); printQ();

	deQueue(); printQ();

	enQueue('D'); printQ();

	deQueue(); printQ();

	deQueue(); printQ();

	deQueue();

	deQueue();

	return 0;
}