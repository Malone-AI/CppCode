/*第11题*/
#include <stdio.h>
#include <string.h>
#define n 8 /*叶子数*/
#define m (2 * n - 1) /*结点总数*/
#define Maxval __FLT_MAX__ /*float类型最大值*/

typedef char datatype;
typedef struct{
    /*哈夫曼树结构体*/
    float weight;
    datatype data;
    int left,right,parent;/*左右孩子及双亲指针*/
}hufmtree;
hufmtree tree[m];/*哈夫曼树设为全局变量*/

typedef struct {
    /*哈夫曼编码结构体*/
    char bits[n];/*存储编码位串*/
    int start;/*指示位串在bits中的起始位置*/
    datatype data;/*存储的字符*/
}codetype;
codetype code[n];/*设置哈夫曼编码数组为全局变量*/

void CreateHufmtree(){
    /*构造哈夫曼树,返回树根节点的指针*/
    for(int i = 0;i < m;i++){
        /*哈夫曼树初始化*/
        tree[i].data = '0';
        tree[i].weight = 0.0;
        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].parent = -1;
    }

    printf("请输入字符及其对应的权值:\n");
    for(int i = 0;i < n;i++){
        /*输入n个叶子结点字符及其权值至tree[0]~tree[n-1]*/
        scanf(" %c",&tree[i].data);
        scanf("%f",&tree[i].weight);
    }

    for(int i = n;i <= m - 1;i++){
        /*进行n-1次合并，产生n-1个新结点存入tree[n]~tree[m-1]*/
        int p1 = 0; /*p1和p2分别存放最小权值结点和次最小权值结点*/
        int p2 = 0;
        float s1 = Maxval;/*s1,s2分别存放最小权值和次最小权值*/
        float s2 = Maxval;
        for(int j = 0;j <= i - 1;j++){
            if(tree[j].parent == -1){
                if(tree[j].weight < s1){
                    s2 = s1;/*改变最小权值和次最小权值*/
                    s1 = tree[j].weight;
                    p2 = p1;/*改变最小权值下标和次最小权值下标*/
                    p1 = j;
                }else if(tree[j].weight <s2){
                    s2 = tree[j].weight;/*改变次最小权值*/
                    p2 = j;/*次最小权值下标*/
                }
            }
        }
        tree[p1].parent = tree[p2].parent = i;/*指定合并的两个结点的双亲结点为新结点*/
        tree[i].left = p1;/*最小权值结点时新结点的左孩子*/
        tree[i].right = p2;/*次小权值结点时新结点的右孩子*/
        tree[i].weight = tree[p1].weight + tree[p2].weight;/*新结点的权值为左右孩子权值之和*/
    }
}

void HUFencode(){
    /*哈夫曼编码算法*/
    codetype tmp;/*临时存放编码的变量*/
    int p,c;
    for(int i = 0;i < n;i++){
        tmp.start = n;/*从叶子结点开始向上回溯*/
        c = i;/*c代表第i个叶子结点*/
        p = tree[c].parent;/*p代表当前结点双亲*/
        tmp.data = tree[c].data;
        while(p != -1){
            tmp.start--;
            if(tree[p].left == c)
                tmp.bits[tmp.start] = '0';/*若结点是左孩子则置为'0'*/
            else
                tmp.bits[tmp.start] = '1';/*若结点是右孩子则置为'1'*/
            c = p;/*双亲结点p称为其双亲的孩子结点*/
            p = tree[c].parent;
        }
        code[i] = tmp;/*编码好的字符放入code[]数组*/
    }
}

int main(){
    CreateHufmtree();
    HUFencode();

    for(int i = 0;i < n;i++){
        printf("%c -> ",code[i].data);
        for(int j = code[i].start;j < n;j++){
            printf("%c",code[i].bits[j]);
        }
        printf("\n");
    }
    return 0;
}