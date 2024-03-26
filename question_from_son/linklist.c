#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1

typedef int ElemType;

typedef struct QNode{
    ElemType data;
    struct QNode *next; 
}QNode;

typedef struct{
    QNode *rear; 
}LinkQueue;

int createQueue(LinkQueue *q); //创建初始空队列，成功则返回 OK，否则返回 ERROR

int isEmpty(LinkQueue q); //判断队列是否为空，若为空则返回 1，否则返回 0

void printQueue(LinkQueue q); //输出队列中从队头至队尾的所有元素，不修改队列

int inQueue(LinkQueue *q, ElemType e); //元素 e 入队列，成功时返回 OK
 //失败则返回 ERROR

int outQueue(LinkQueue *q, ElemType *e); //非空时队头元素出队（参数 e 返回队头元素）
 //若出队成功则返回 OK，否则返回 ERROR

int inQueue(LinkQueue *q, ElemType e) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if (newNode == NULL) {
        return ERROR;
    }
    newNode->data = e;
    newNode->next = NULL;

    if (isEmpty(*q)) { 
        q->rear = newNode;
        newNode->next = newNode; 
    } else {
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }

    return OK;
}

int outQueue(LinkQueue *q, ElemType *e) {
    if (isEmpty(*q)) {
        return ERROR;
    }

    QNode *head = q->rear->next;
    *e = head->data;

    if (head == q->rear) { 
        q->rear = NULL;
    } else {
        q->rear->next = head->next;
    }
    free(head);
    
    return OK;
}

int main(){ //评测系统中使用这里定义的 main 函数进行测试
    LinkQueue Q; 
    createQueue(&Q);
    ElemType elem;
    char cmd[8] = {0};
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "quit")==0)
            break;
        if (strcmp(cmd, "in")==0) {
            scanf("%d", &elem);
            getchar();
            inQueue(&Q, elem);
        }
    else if (strcmp(cmd, "out")==0){
        if (outQueue(&Q, &elem)!=OK){
            printf("out Error\n");
        }else{
            printf("%d out of Queue\n", elem);
        }
        printQueue(Q); 
    }
    printQueue(Q); 
    return 0;
    }//main
}

int createQueue(LinkQueue *q) {
    q->rear = NULL;
    return OK;
}
int isEmpty(LinkQueue q){
    return (q.rear==NULL);
}
void printQueue(LinkQueue q) {
    printf("Queue: ");
    if (isEmpty(q)) {
        printf("Empty\n"); 
        return;
    }
    QNode *p = q.rear->next; 
    while (p!=q.rear) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}