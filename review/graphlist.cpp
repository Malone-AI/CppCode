#include <stdio.h>
#include <stdlib.h>
#define n 4 /*图的顶点数*/
#define e 4 /*图的边数*/

typedef char vextype; /*顶点数据信息类型*/
typedef struct node{
    int adjvex; /*邻接点域，为顶点的下标*/
    struct node *next;
}edgenode;

typedef struct{
    vextype vertex;/*顶点域，放置顶点信息*/
    edgenode *link;
}vexnode;
// vexnode ga[n]; /*顶点表*/

void CreatGraphlist(vexnode ga[]){
    /*建立无向图的邻接表*/
    int i,j,k;
    edgenode *s;

    for(i=0;i<n;i++){
        /*顶点表初始化*/
        ga[i].vertex=getchar();/*读入顶点信息*/
        ga[i].link=NULL;/*对边表头指针进行初始化*/
    }

    getchar();/*清空缓冲区*/

    for(k=0;k<e;k++){
        /*头插法建立边表*/
        scanf("%d%d",&i,&j);/*读入边表(vi,vj)的顶点序号(数组下标)*/

        s=(edgenode *)malloc(sizeof(edgenode)); /*生成序号为j的边表结点*s*/
        s->adjvex=j;
        s->next=ga[i].link; /*将*s插入顶点vi的边表头部*/
        ga[i].link=s;

        s=(edgenode *)malloc(sizeof(edgenode)); /*生成序号为j的边表结点*s*/
        s->adjvex=i;
        s->next=ga[j].link; /*将*s插入顶点vj的边表头部*/
        ga[j].link=s;
    }
}/*CreatGraphlist*/

int main(){
    vexnode ga[n]; /*顶点表*/
    CreatGraphlist(ga);
    return 0;
}