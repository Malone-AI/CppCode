/*
    以邻接矩阵为存储结构的深度优先遍历
*/


#include <stdio.h>

#define n 8 /*图的顶点数*/
#define e 9 /*图的边数*/
typedef char vextype; /*顶点数据类型*/
typedef float adjtype; /*顶点权值数据类型*/

typedef struct{
    vextype vexs[n];/*顶点数组*/
    adjtype arcs[n][n];/*邻接矩阵*/
}graph;

void CreatGraph(graph *g){
    /*
    建立无向图
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
        g->arcs[i-1][j-1]=w;/*写入邻接矩阵*/
        g->arcs[j-1][i-1]=w;/*对于有向网络只需要去掉这一行即可*/
    }
}/*CreatGraph*/

graph g;/*g为全局变量*/
int visted[n];/*定义visted为全局变量，n为顶点数*/

void DFSA(int i){
    /*从顶点vi出发深度优先搜索图g，g用邻接矩阵表示*/
    int j;
    printf("node : %c\n",g.vexs[i]);/*访问出发点vi*/
    visted[i] = 1;/*标记已访问vi*/
    for(j = 0;j < n;j++){/*按顶点序号从小到大依次搜索*/
        if(g.arcs[i][j] == 1 && visted[j] == 0)
            DFSA(j);/*如果vi的邻接点vj未被访问过，则从vj开始进行深度优先搜索*/
    }
}

int main(){
    CreatGraph(&g);
    DFSA(0);
}