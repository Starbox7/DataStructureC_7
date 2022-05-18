#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;

element cqueue[Q_SIZE];
int front = 0, rear = 0;

void isEmpty() {
	printf("\n Queue is full! \n");
}

void isFull() {
	printf("\n Queue is full! \n");
}

void enQueue(element item) {
	rear = (rear + 1) % Q_SIZE;
	if (rear == front) {
		isFull();
		exit(1);
	}
	else cqueue[rear] = item;
}

element deQueue() {
	if (front == rear) {
		isEmpty();
			exit(1);
	}
	else {
		front = (front + 1) % Q_SIZE;
		return cqueue[front];
	}
}

void del() {
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
	else return cqueue[front + 1];
}

void printQ() {
	int i, first, last;
	first = (front + 1) % Q_SIZE;
	last = (rear + 1) % Q_SIZE;
	printf("\n Queue : [");
	i = first;
	while (i != last) {
		printf("%2c", cqueue[i]);
		i = (i + 1) % Q_SIZE;
	}
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