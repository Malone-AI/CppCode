/*第四题*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 64

typedef char datatype;
typedef struct node{
    datatype data;
    struct node *left,*right;
}bitree;

bitree* CreateTree(){
    /*建立二叉树*/
    bitree *root,*cur;
    int front,rear;
    bitree** queue = (bitree**)malloc(sizeof(bitree*) * maxsize);
    char ch;
    root = NULL;
    cur = NULL;
    front = 1;
    rear = 0;
    printf("请输入二叉树序列:\n");
    while((ch = getchar()) != '#'){
        cur = NULL;
        if(ch != '@'){
            cur = (bitree *)malloc(sizeof(bitree));
            cur->data = ch;
            cur->left = NULL;
            cur->right = NULL;
        }
        rear++;
        queue[rear] = cur;
        if(rear == 1){
            root = cur;
        }else{
            if(cur && queue[front]){
                if(rear % 2 == 0)
                    queue[front]->left = cur;
                else
                    queue[front]->right = cur;
            }
            if(rear % 2 == 1)
                front++;
        }
    }
    free(queue);/*释放内存*/
    return root;
}

void transpose(bitree *root){
    /*交换所有二叉树左右子树的位置*/
    /*该函数是递归的，递归结束条件为当前结点不为空*/
    if(root == NULL){
        return ;
    }else{
        transpose(root->left);
        transpose(root->right);
        bitree *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
}

void Print(bitree *root){
    /*广度优先遍历二叉树*/
    bitree** queue = (bitree**)malloc(sizeof(bitree*) * maxsize);
    int front,rear;
    front = 1;
    rear = 0;

    if(root){
        queue[++rear] = root;/*根节点入队*/
        while(front <= rear){
            root = queue[front++];
            printf("%c",root->data);
            if(root->left)/*左节点不为空时入队*/
                queue[++rear] = root->left;
            if(root->right)/*右节点不为空时入队*/
                queue[++rear] = root->right;
        }
    }
    free(queue);/*释放内存*/
}

int main(){
    bitree *root = CreateTree();
    transpose(root);
    printf("进行转换后的二叉树:\n");
    Print(root);
    printf("\n");
    return 0;
}