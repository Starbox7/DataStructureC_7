#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct DQNode {
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
} DQNode;

typedef struct {
    DQNode *front, *rear;
}DQueType;

DQueType *createDQue() {
    DQueType *DQ;
    DQ = (DQueType *)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isEmpty(DQueType *DQ) { // isFull() 함수는 없음!!!!
    if (DQ->front == NULL) {
        printf("\n Linked Queue is empty! \n");
        return 1;
    }
    else 
        return 0;
}

void insertFront(DQueType *DQ, element item) {
    DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
    newNode->data = item;
    if (DQ->front == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        DQ->front = newNode;
    }
}

void insertRear(DQueType *DQ, element item) {
    DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
    newNode->data = item;
    if (DQ->front == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->rear->rlink = newNode;
        newNode->rlink = NULL;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

element deleteFront(DQueType *DQ) {
    DQNode *old = DQ->front;
    element item;
    if (isEmpty(DQ)) {
        return 0;
    }
    else {
        item = old->data;
        if (DQ->front->rlink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    }
}

element deleteRear(DQueType *DQ) {
    DQNode *old = DQ->rear;
    element item;
    if (isEmpty(DQ)) 
        return 0;
    else {
        item = old->data;
        if (DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

void removeFront(DQueType *DQ) {
    DQNode *old = DQ->front;
    if (isEmpty(DQ)) 
        return 0;
    else if (DQ->front->rlink == NULL) {
        DQ->front = NULL;
        DQ->rear = NULL;
    }
    else {
        DQ->front = DQ->front->rlink;
        DQ->front->llink = NULL;
    }
    free(old);
}

void removeRear(DQueType *DQ) {
    DQNode *old = DQ->front;
    if (isEmpty(DQ)) 
        return 0;
    else if (DQ->rear->llink == NULL) {
        DQ->front = NULL;
        DQ->rear = NULL;
    }
    else {
        DQ->rear = DQ->rear->llink;
        DQ->rear->rlink = NULL;
    }
    free(old);
}

element peekFront(DQueType *DQ) {
    element item;
    if (isEmpty(DQ)) {
        return 0;
    }
    else {
        item = DQ->front->data;
        return item;
    }
}

element peekRear(DQueType *DQ) {
    element item;
    if (isEmpty(DQ)) 
        return 0;
    else {
        item = DQ->rear->data;
        return item;
    }
}

void printDQ(DQueType *DQ) {
    DQNode *temp = DQ->front;
    printf("\n DeQue : [");
    while (temp) {
        printf("%3c", temp->data);
        temp = temp->rlink;
    }
    printf(" ]");
}

int main(void) {
    printf("학번 : 18114847, 이름 : 김범준, 5/19 \n");
    printf("실습#7-3, 데크의 삽입/삭제 -> 연결리스트를 사용해서 구현\n\n");  //deque:double-ended Queue

    DQueType *DQ1 = createDQue();
    element data;

    insertFront(DQ1, 'A');
    printDQ(DQ1);

    insertFront(DQ1, 'B');
    printDQ(DQ1);

    insertFront(DQ1, 'C');
    printDQ(DQ1);

    deleteFront(DQ1);
    printDQ(DQ1);

    deleteRear(DQ1);
    printDQ(DQ1);

    insertRear(DQ1, 'D');
    printDQ(DQ1);

    insertFront(DQ1, 'E');
    printDQ(DQ1);

    insertFront(DQ1, 'F');
    printDQ(DQ1);

    data = peekFront(DQ1);
    printf("\n peek Front item : %c", data);

    data = peekRear(DQ1);
    printf("\n peek Rear item : %c", data);

    getchar();
    return 0;
}

