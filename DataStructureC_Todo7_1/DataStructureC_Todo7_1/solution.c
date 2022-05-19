#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 5 //3

typedef char element;

element queue[Q_SIZE];
int front = -1, rear = -1;

void isEmpty() {
	printf("\n Queue is empty! \n");
}

void isFull() {
	printf("\n Queue is full! \n");
}

void enQueue(element item) {  //stack�� push() �Լ��� ����
	if (rear >= Q_SIZE - 1) {
		isFull();
		exit(1);
	}
	else queue[++rear] = item;
}

element deQueue() { //stack�� �����Լ� pop()�� ��
	if (front == rear) { // top == -1
		isEmpty();
		exit(1);
	}
	else return queue[++front];  //data ��ȯ �� top ����
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

	printf("�й� : 18114847, �̸� : �����, 5/19 \n");
	printf("�ǽ�#7-1, ����ť������ ����/����\n\n");

	element data;

	enQueue('A'); printQ();
	enQueue('B'); printQ();

	deQueue(); printQ();

	enQueue('C'); printQ();

	deQueue(); printQ();

	enQueue('D'); printQ(); //C D -> �ԷºҰ�(Queue Full) -> drift ���� : �����Ͱ� �տ� ��������� ���� ���� (Ƽ�� ����) / ���� ��ɵ� ���ǹ̵�

	deQueue(); printQ();

	deQueue(); printQ();

	deQueue();

	deQueue();

	return 0;
}