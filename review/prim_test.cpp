//
// Created by pengxiangzhou on 2021/2/2.
// minimum spanning tree
//
#include <stdio.h>
#include <stdlib.h>
#ifndef C_DS_MST_H
#define C_DS_MST_H

#endif //C_DS_MST_H
typedef char VertexType; //自定义顶点类型
typedef int EdgeType; //自定义边上的权值类型
#define MAXVEX 100 //最大顶点树
#define INFINITY INT_MAX 

typedef struct
{
    VertexType vexs[MAXVEX];  //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵
    int numVertexes,numEdges;  //当前的顶点数和边数
}MGraph;
//建立无向图的邻接矩阵表述
void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);//输入顶点数和边数
    for (i=0;i<G->numVertexes;i++) //读入顶点信息，建立顶点表
        scanf(&G->vexs[i]);
    for (i =0; i<G->numVertexes;i++)
        for (j =0; j<G->numVertexes;j++)
            G->arc[i][j] = INFINITY;  //邻接矩阵初始化
    for (k=0;k<G->numEdges;k++)
    {
        printf("输入边（vi,vj）上的下标i，下标j，和权w：\n");
        scanf("%d,%d,%d",&i,&j,&w); //输入边（vi,vj）的权w
        G->arc[i][j] = w;
        G->arc[j][i]=G->arc[i][j];//无向图，矩阵对称
    }
}

void MiniSpanTree_Prim(MGraph G)
{
    /*
    prim算法
    */
    int min, i, j ,k;
    int adjvex[MAXVEX]; //保存相关顶点下标
    int lowcost[MAXVEX]; //保存相关顶点间的权值
    lowcost[0]=0; //初始化第一个权值为0，cost为0，即下标为0的顶点，v_{0}加入生成树
    adjvex[0] = 0; //初始化第一个顶点 下标为0
    //将第一行的边，存储到lowcost
    for (i=1;i<G.numVertexes;i++)  //循环除了下标为0外的全部顶点
    {
        lowcost[i] = G.arc[0][i]; //将v_{0}顶点与之有边的权值存入数组
        adjvex[i]=0;   //初始化都为v_{0}的下标
    }
    for (i=1;i<G.numVertexes;i++)
    {
        min = INFINITY;
        j = 1; k = 0;
        while (j<G.numVertexes)  //循环全部顶点
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min = lowcost[j];
                k=j;   //将当前最小值的下标存入k，k存储下一步的结点的标记
            }
            j++; //？？为什么要j++
        } //得到min{{生成树的顶点的集合到其他各个顶点的最短距离}
        printf("(%d,%d)",adjvex[k],k); //打印当前顶点边中权值最小边
        lowcost[k] = 0; //将当前顶点的权值设置为0，表示该顶点已经完成任务
        for (j =1; j < G.numVertexes; j++) {   //循环所有顶点
            if (lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {
                //lowcost[j]!=0保证不会重复访问
                lowcost[j]=G.arc[k][j];
                adjvex[j] = k; //将下标为k的顶点存入adjvex，也就是存储下一步的最短边的起点
            }
        } //得到目前已经是生成树的顶点的集合到其他各个顶点的最短距离
    }
}

int main() {
    MGraph PG;
    CreateMGraph(&PG);
    MiniSpanTree_Prim(PG);

};
//9,14  0,1,10 0,5,11 1,2,18 1,6,16 1,8,12 2,3,22 2,8,8 3,4,20 3,7,17 3,8,21 4,5,26 4,7,7 5,6,17 6,7,19
