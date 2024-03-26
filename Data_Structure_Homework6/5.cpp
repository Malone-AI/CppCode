/*第5题*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 64

/*算法*/
/*广度优先该二叉树，对于符合条件的结点将其从树中删除，对其及其子节点进行广度优先遍历*/

typedef char datatype;
typedef struct node{
    datatype data;
    struct node *left;
    struct node *right;
}bitree;

bitree* CreatTree();
void release(bitree *root);
void Pop(bitree *root,datatype ch);
void BFS(bitree *root);

bitree* CreatTree(){
    /*创建二叉树*/
    datatype ch;
    bitree *root = NULL;/*根节点*/
    bitree *cur = NULL;/*工作指针*/
    bitree **queue = (bitree **)malloc(sizeof(bitree *) * maxsize);/*队列*/
    int front,rear;/*队列指针*/
    front = 1;
    rear = 0;
    while((ch = getchar()) != '#'){
        /*新建结点*/
        cur = NULL;
        if(ch != '@'){
        /*'@'代表虚结点*/
        cur = (bitree *)malloc(sizeof(bitree));
        cur->data = ch; 
        cur->left = NULL;
        cur->right = NULL;
        }

        queue[++rear] = cur;/*新建结点入队*/
        if(rear == 1){
            root = queue[rear];/*当新建的第一个结点设为根节点*/
        }else{
            if(cur && queue[front]){
                /*当新建结点和队头结点都不是虚结点*/
                if(rear % 2 == 0){
                    /*rear为偶数，新结点为左孩子*/
                    queue[front]->left = cur;
                }else{
                    /*rear为奇数，新结点为右孩子*/
                    queue[front]->right = cur;
                }
            }
            if(rear % 2 == 1)
            /*对头结点的左右孩子均设置完毕,出队*/
                front++;
        }
    }
    free(queue);
    return root;
}

void Pop(bitree *root,datatype ch){
    /*删除二叉树中所有结点值为ch的结点及其子树*/
    bitree **queue = (bitree **)malloc(sizeof(bitree *) * maxsize);/*队列*/
    int front = 1,rear =0;/*队列队头、队尾指针*/
    if(root){
        /*root不为空结点时开始广度优先遍历*/
        queue[++rear] = root;/*根节点入队*/
        while(front <= rear){
            /*队列不为空*/
            root = queue[front++];/*root作为工作指针处理队头结点，队头结点同时出队*/
            if(root->data == ch){
                printf("删除的结点及其子树的广度优先遍历序列:\n");
                BFS(root);/*输出该节点及其子树*/
                release(root);/*释放该节点所占用内存*/
            }else{
                if(root->left)/*左节点不为空时入队*/
                    queue[++rear] = root->left;
                if(root->right)/*右节点不为空时入队*/
                    queue[++rear] = root->right;
            }
        }
    }
}

void release(bitree *root){
    /*递归删除结点root及其子树*/
    if(!root){
        /*递归结束条件*/
        return ;
    }
    release(root->left);
    release(root->right);
    free(root);
}

void BFS(bitree *root){
    /*广度优先遍历*/
    if(root){
        bitree **queue = (bitree **)malloc(sizeof(bitree *) * maxsize);
        int front = 1,rear =0;
        queue[++rear] = root;
        while(front <= rear){
            root = queue[front++];
            if(root){
                printf("%c",root->data);
            }
            if(root->left)/*左节点不为空时入队*/
                queue[++rear] = root->left;
            if(root->right)/*右节点不为空时入队*/
                queue[++rear] = root->right;
        }
        printf("\n");
        free(queue);
    }
}

int main(){
    bitree *root = CreatTree();
    getchar();/*清空缓存区*/
    datatype ch;
    printf("请输入要删除结点的值:\n");
    scanf("%c",&ch);
    Pop(root,ch);
    return 0;
}