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

void enQueue(element item) {  //stack의 push() 함수와 유사
	if (rear >= Q_SIZE - 1) {
		isFull();
		exit(1);
	}
	else queue[++rear] = item;
}

element deQueue() { //stack의 삭제함수 pop()와 비교
	if (front == rear) { // top == -1
		isEmpty();
		exit(1);
	}
	else return queue[++front];  //data 반환 후 top 감소
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

	printf("학번 : 18114847, 이름 : 김범준, 5/19 \n");
	printf("실습#7-1, 선형큐에서의 삽입/삭제\n\n");

	element data;

	enQueue('A'); printQ();
	enQueue('B'); printQ();

	deQueue(); printQ();

	enQueue('C'); printQ();

	deQueue(); printQ();

	enQueue('D'); printQ(); //C D -> 입력불가(Queue Full) -> drift 현상 : 데이터가 앞에 비었음에도 들어가지 못함 (티켓 소진) / 예하 명령들 무의미됨

	deQueue(); printQ();

	deQueue(); printQ();

	deQueue();

	deQueue();

	return 0;
}