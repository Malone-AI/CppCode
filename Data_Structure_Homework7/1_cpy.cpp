/*第一题*/
/*无向图的邻接矩阵转换成邻接表*/
#include <stdio.h>
#include <stdlib.h>
#define n 4 /*顶点个数*/
#define e 4 /*边数*/

typedef char vextype;/*顶点数据类型*/
typedef float adjtype;/*顶点权值数据类型*/

/*邻接矩阵结构体*/
typedef struct{
    vextype vexs[n];/*顶点数组*/
    adjtype arcs[n][n];/*邻接矩阵*/
}graph;

/*邻接表结构体*/
typedef struct node{
    /*顶点结构体*/
    int adjvex;/*邻接点域*/
    struct node *next;/*链域*/
}edgenode;
typedef struct{
    /*"边"结构体*/
    vextype vertex;/*顶点数据域*/
    edgenode *link;/*边表头指针域*/
}vexnode;

void CreateGraph(graph *G){
    /*创建邻接矩阵*/
    int i,j;
    // for(i = 0;i < n;i++){
        // G->vexs[i] = getchar();/*读入顶点信息，建立顶点表*/
    // }
    G->vexs[0] = 'a';
    G->vexs[1] = 'b';
    G->vexs[2] = 'c';
    G->vexs[3] = 'd';

    for(i = 0;i < n;i++){
        /*邻接矩阵初始化*/
        for(j = 0;j < n;j++)
            G->arcs[i][j] = 0;
    }

    // for(int k = 0;k < e;k++){
        // /*读入边(vi,vj)*/
        // scanf("%d%d",&i,&j);
        // G->arcs[i][j] = 1;
        // G->arcs[j][i] = 1;
    // }
    G->arcs[0][1] = 1;
    G->arcs[1][0] = 1;
    G->arcs[0][3] = 1;
    G->arcs[2][3] = 1;
}

void Matrix2List(graph *G,vexnode Ga[]){
    /*邻接矩阵转邻接表*/
    /*G为邻接矩阵,Ga[]为邻接表*/
    for(int i = 0;i < n;i++){
        Ga[i].vertex = G->vexs[i];/*读入顶点信息*/
        Ga[i].link = NULL;/*边表头指针初始化*/
    }

    edgenode *s = NULL;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            /*遍历邻接矩阵*/
            if(G->arcs[i][j] != 0){
                s = (edgenode *)malloc(sizeof(edgenode));/*生成序号为vj的边表结点*/
                s->adjvex = j;
                s->next = Ga[i].link;
                Ga[i].link = s;/*头插法将顶点s插入顶点表*/
            }
        }
    }
}

int main(){
    graph g;
    CreateGraph(&g);
    vexnode Ga[n];
    Matrix2List(&g,Ga);
    return 0;
}