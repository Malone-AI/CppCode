#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node{
    datatype data;
    struct node *next;
}linklist;

linklist* CreateListF( ){
    /*
    带头结点的头插法，返回单链表的头指针
    */
    linklist *head,*p;  char ch;
    head = (linklist*)malloc(sizeof(linklist));      
    //产生头结点
    head->next=NULL;
    while((ch=getchar( ))!='\n'){
        //输入abc…　 
        p=(linklist*)malloc(sizeof(linklist));
        //生成新结点　　  
        p->data=ch;                      
        //对结点的数据域赋值 
        p->next=head->next;
        //新结点指针域指向原第一个结点
        head->next=p;
        //修改头结点的指针域
    }
    return head;
}    

int main(){
    return 0;
}