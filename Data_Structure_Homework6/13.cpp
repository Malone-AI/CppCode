/*第13题*/
/*利用二叉树的先序遍历*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 64

typedef char datatype;
typedef struct node{
    datatype data;
    struct node *left;
    struct node *right;
}bitree;

bitree* CreateTree(){
    char ch;
    bitree *root = NULL;
    bitree *cur = NULL;
    bitree **queue = (bitree **)malloc(sizeof(bitree *) * maxsize);
    int front = 1,rear = 0;
    printf("请输入二叉树广度优先遍历序列:\n");
    while((ch = getchar()) != '#'){
        cur = NULL;
        if(ch != '@'){
            cur = (bitree *)malloc(sizeof(bitree));
            cur->data = ch;
            cur->left = NULL;
            cur->right = NULL;
        }
        queue[++rear] = cur;
        if(rear == 1){
            root = cur;
        }else{
            if(cur && queue[front]){
                if(rear % 2 == 0)
                    queue[front]->left = cur;
                if(rear % 2 == 1)
                    queue[front]->right = cur;
            }
            if(rear % 2 == 1)
                front++;
        }
    }
    free(queue);
    return root;
}

bitree* Find_n(bitree *root,char n){
    /*寻找结点n*/
    bitree **stack = (bitree **)malloc(sizeof(bitree *) * maxsize);
    int top = 0;
    while(root || top > 0){
        /*当前结点不为空或者栈不为空*/
        if(root){
            if(root->data == n)
                return root;
            stack[++top] = root;
            root = root->left;
        }else{
            root = stack[top--];
            root = root->right;
        }
    }
    free(stack);
    return NULL;
}

bitree* Find_Parent(bitree *root,char n){
    /*寻找值为ch的结点的双亲结点,返回指向双亲结点的指针*/
    bitree **stack = (bitree **)malloc(sizeof(bitree *) * maxsize);
    int top = 0;
    bitree *pre = NULL;/*当前遍历结点的前驱结点*/
    while(root || top > 0){
        /*当前结点不为空或者栈不为空*/
        if(root){
            if(root->data == n)
                return pre;
            stack[++top] = root;
            pre = root;
            root = root->left;
        }else{
            root = stack[top--];
            pre = root;
            root = root->right;
        }
    }
    free(stack);
    return NULL;
}

int main(){
    bitree *t = CreateTree();
    getchar();/*清空缓冲区*/
    printf("请输入要删除结点的值:\n");
    char n;
    scanf("%c",&n);
    bitree *has_n = Find_n(t,n);
    if(has_n){
        printf("找到了结点n\n");
        bitree *parent = Find_Parent(t,n);
        if(parent)
            printf("结点n的双亲结点的值为%c\n",parent->data);
        else
            printf("结点n没有双亲结点\n");
    }else{
        printf("没有结点n\n");
    }
    return 0;
}