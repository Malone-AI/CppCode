#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

typedef struct node{
    char data;
    struct node *next;
}LinkList;

typedef struct{
    LinkList *head,*tail;
    int length;
}LinkString;

LinkString *CreatString(char ch[]){
    //创建链串

    //创建空串
    LinkString *S=(LinkString *)malloc(sizeof(LinkString));
    S->head=(LinkList*)malloc(sizeof(LinkList));
    S->head->next=NULL;
    S->tail=NULL;
    S->length=0;

    for(unsigned int i=0;i<strlen(ch);i++){
        //头插法插入链串结点
        LinkList *Node=(LinkList *)malloc(sizeof(LinkList));
        Node->data=ch[i];
        Node->next=NULL;
        if(S->head->next==NULL){
            //插入第一个结点时直接接到头结点之后
            S->head->next=Node;
        }else{
            //插入第n个结点(n>=2)时直接插入表尾
            S->tail->next=Node;
        }
        //修改尾结点
        S->tail=Node;
        S->length++;
    }
    return S;
}

void Print(LinkString *S){
    //打印链串
    LinkList *p=S->head->next;
    int i=0;
    while(i++<S->length&&p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}

LinkList *LocNode(LinkList *head,int pos){
    //定位链串p的第pos+1个结点,并返回指向它的指针
    int i=0;
    LinkList *cur=head->next;
    while(i++<pos&&cur){
        cur=cur->next;
    }
    return cur;
}

//KMP算法
LinkList* Index(LinkString *S,LinkString *T,int next[]){
    //主串S,模式串T
    int i=0;
    int j=0;
    while(i<S->length&&j<T->length){
        if(j==-1||LocNode(S->head,i)->data==LocNode(T->head,j)->data){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    //判断是否找到模式串
    if(j==T->length){
        //返回模式串T在主串S中首字符位置的指针
        return LocNode(S->head,i-T->length);
    }
    else{
        return NULL; //未找到模式串
    }
}

void Get_Next(LinkString *T,int next[]){
    int k,j;
    j=0;
    k=-1;
    next[0]=-1;
    while(j<T->length-1){
        if(k==-1||LocNode(T->head,j)->data==LocNode(T->head,k)->data){
            j++;
            k++;           
            if(LocNode(T->head,j)->data!=LocNode(T->head,k)->data)
                next[j]=k;
            else
              next[j] = next[k];
        }else{
            k=next[k];
        }
    }
}

void reverse(LinkString *S,LinkString *T,char ch[]){
    //反转字符串函数
    int next[N];
    Get_Next(T,next);
    LinkList *cur=Index(S,T,next);
    int i=0;
    while(i<T->length&&cur){
        cur->data=ch[T->length-1-i];
        i++;
        cur=cur->next;
    }
}

int main(){
    char ch[N];
    printf("请输入S:\n");
    scanf("%s",ch);
    LinkString *S=CreatString(ch);
    printf("请输入T:\n");
    scanf("%s",ch);
    LinkString *T=CreatString(ch);

    int next[N];//next数组
    Get_Next(T,next);
    reverse(S,T,ch);
    printf("反转后的字符串:\n");
    Print(S);
    system("pause");
    return 0;
}