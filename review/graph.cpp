/*
    无向网络邻接矩阵建立算法
*/


#include <stdio.h>

#define n 4 /*图的顶点数*/
#define e 4 /*图的边数*/
typedef char vextype; /*顶点数据类型*/
typedef float adjtype; /*顶点权值数据类型*/

typedef struct{
    vextype vexs[n];/*顶点数组*/
    adjtype arcs[n][n];/*邻接矩阵*/
}graph;

void CreatGraph(graph *g){
    /*
    建立无向网络 
    */
    int i,j,k;
    float w;
    for(i=0;i<n;i++){
        scanf("%c",&g->vexs[i]);/*读入顶点信息，建立顶点表*/
        getchar();
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g->arcs[i][j]=0;/*邻接矩阵初始化*/
    for(k=0;k<e;k++){/*读入边(vi,vj)的权值*/
        scanf("%d%d%f",&i,&j,&w);
        g->arcs[i][j]=w;/*写入邻接矩阵*/
        g->arcs[j][i]=w;/*对于有向网络只需要去掉这一行即可*/
    }
}/*CreatGraph*/

int main(){
    graph g;
    CreatGraph(&g);
    return 0;
}