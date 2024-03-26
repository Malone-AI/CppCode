#include <stdio.h>
#define m 6

typedef int datatype;

//声明
void SetNull(int *p,int *q);
int GetLen(int *front,int *rear);
int isFull(int *front,int *rear);
int Enqueue(datatype *sq,int *front,int *rear,datatype x);
int Dequeue(datatype *sq,int *front,int *rear,datatype *x);

//循环队列置空
void SetNull(int *p,int *q){
    *p=*q=0;
}

//计算循环队列元素个数
int GetLen(int *front,int *rear){
    return (*rear-*front+m)%m;
}

//判读循环队列是否队满
//若尾指针向后挪一位即操作(*rear+1)%m之后,front与rear指向相同,则说明队列已满
int isFull(int *front,int *rear){
    //队满返回1，否则返回0
    if(*front==(*rear+1)%m){
        return 1;
    }
    return 0;
}

//判断队空
int isNull(int *front,int *rear){
    //若front与rear指向相同,则说明队空,返回1;否则返回0
    if(*front==*rear){
        return 1;
    }
    return 0;
}

//循环队列插入元素
int Enqueue(datatype *sq,int *front,int *rear,datatype x){
    //若队空或队未满,则将元素x插入队列sq的队尾，成功返回1，否则返回0
    if(isNull(front,rear)||!isFull(front,rear)){
        *rear=(*rear+1)%m;
        sq[*rear]=x;
        return 1;
    }else{
        printf("队列上溢\n");
        return 0; 
    }
}

//循环队列出队，若尾指针与头指针指向相同，则说明队空,出队失败，返回0；否则返回1
int Dequeue(datatype *sq,int *front,int *rear,datatype *x){
    if(*front==*rear){
        printf("队列下溢\n");
        return 0;
    }else{
        *front=(*front+1)%m;
        *x=sq[*front];
        return 1;
    }
}

int main(){
    datatype cycque[m];
    //front对头指针
    int i,front,rear;
    int *p=&front,*q=&rear;
    //队列初始化,把front头指针与rear尾指针都置为0
    SetNull(p,q);
    printf("队列中元素个数=%d\n",GetLen(&front,&rear));
    //临时变量temp用来辅助入队操作,当遇到-1时结束入队
    printf("-----开始入队-----\n");
    printf("请输入入队元素,以空格相邻,以-1为结束标志\n");
    datatype temp;
    scanf("%d",&temp);
    while(temp!=-1){
        if(isFull(&front,&rear)){
            printf("队列上溢\n");
            break;
        }
        Enqueue(cycque,&front,&rear,temp);
        scanf("%d",&temp);
    }
    printf("-----入队结束-----\n");
    printf("队列中元素个数=%d\n",GetLen(&front,&rear));
    printf("-----开始出队-----\n");
    printf("请输入出队元素个数:\n");
    //清空标准输入缓冲区
    fflush(stdin);
    scanf("%d",&temp);
    for(i=0;i<temp;i++){
        datatype x;
        if(isNull(&front,&rear)){
            printf("队列下溢\n");
            break;
        }
        Dequeue(cycque,&front,&rear,&x);
        printf("出队的第%d个元素为%d\n",i+1,x);
    }
    printf("-----出队结束-----\n");
    printf("队列中元素个数=%d\n",GetLen(&front,&rear));
}