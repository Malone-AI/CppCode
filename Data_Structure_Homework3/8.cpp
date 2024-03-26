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

int SearchValue(LinkList *head,char ch){
    //在链表中按值查找
    //查找到返回1,否则返回0
    LinkList *cur=head->next;
    while(cur!=NULL){
        if(cur->data==ch)
            return 1;
        cur=cur->next;
    }
    return 0;
}

void find(LinkString *S,LinkString *T){
    LinkList *cur=S->head->next;
    while(cur!=NULL){
        char ch=cur->data;
        if(SearchValue(T->head,ch)){
            cur=cur->next;
        }else{
            printf("S中第一个不在T中出现的字符是:  %c\n",ch);
            return ;
        }
    }
    printf("S中没有不在T中出现的字符\n");
}

int main(){
    char ch[N];
    printf("请输入S:\n");
    scanf("%s",ch);
    LinkString *S=CreatString(ch);
    printf("请输入T:\n");
    scanf("%s",ch);
    LinkString *T=CreatString(ch);
    find(S,T);
    system("pause");
}
