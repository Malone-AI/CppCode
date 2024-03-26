#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

//链表结构体
typedef struct node{
    datatype data;
    struct node *next;
}QueueNode;

//链队列队尾指针结构体
typedef struct{
    QueueNode *rear;
}LinkQueue;

//链队列初始化
void InitQueue(LinkQueue **Lq){
    //产生队尾指针结构体
    (*Lq)=(LinkQueue *)malloc(sizeof(LinkQueue));
    //为队尾指针和队首指针分配空间,并生成头结点
    (*Lq)->rear=(QueueNode*)malloc(sizeof(QueueNode));
    (*Lq)->rear->next=(QueueNode*)malloc(sizeof(QueueNode));
    //头结点指针域置空
    (*Lq)->rear->next->next=NULL;
}

//链队列入队
void EnQueue(QueueNode *rear,datatype x){
    //将元素x添加进链队列*Lq

    //生成新结点
    QueueNode *p;
    p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=x;

    //新结点入队
    p->next=rear->next;//新结点指针域指向头结点
    rear->next=p;//尾指针指针域指向新结点
    rear=p;//链队列尾指针指向新结点

}

//链队列出队,成功返回1，否则返回0
int DeQueue(QueueNode *rear,datatype *x){
    //尾指针的指针域指向自己时说明队列为空
    if(rear->next==rear){
        //printf("队列下溢\n");
        return 0;
    }
    QueueNode *p=(QueueNode *)malloc(sizeof(QueueNode));

    //p为链队列中第一个有效节点
    p=rear->next->next;

    if(p==rear){
        //若p与尾指针指向的结点相同,则队列长度为1
        rear=rear->next;
        rear->next=rear;
    }else{
        //队列长度大于1
        rear->next->next=p->next;//将头结点的指针域指向所要删除结点的下一个结点
    }
    *x=p->data;
    free(p);
    return 1;
}

int main(){
    LinkQueue *Lq;
    InitQueue(&Lq);
    int i,n;
    printf("------开始入队------\n");
    printf("请输入一个值n(n>0):\n");
    scanf("%d",&n);
    printf("比%d小的正整数全部入队\n",n);
    for(i=1;i<=n;i++){
        EnQueue(Lq->rear,i);
    }
    printf("------入队结束------\n");
    printf("------开始打印------\n");
    printf("----一边出队一边打印----\n");
    datatype x;
    while(DeQueue(Lq->rear,&x)){
        printf("%d ",x);
    }
    printf("------打印结束------\n");
    free(Lq->rear);
    free(Lq);
    return 0;
}