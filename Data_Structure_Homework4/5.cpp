#include <stdio.h>
#include <stdlib.h>

#define maxsize 1000
typedef int datatype;

//三元组结构体
typedef struct{
    int i,j;//行号，列号
    datatype v;//元素值
}Node;

//稀疏矩阵
typedef struct{
    int m,n,t;//行数，列数，非零元素个数
    Node data[maxsize];//存放三元组表的向量
}spmatrix;

//创建稀疏矩阵
void CreatMat(spmatrix *matrix){
    int rows,cols,amount;
    printf("矩阵的行数  矩阵的列数  非零元素个数:\n");
    scanf("%d %d %d",&rows,&cols,&amount);
    matrix->m=rows;
    matrix->n=cols;
    matrix->t=amount;
    int row,col,val;
    printf("非零元素的行号  非零元素的列号  非零元素:\n");
    scanf("%d %d %d",&row,&col,&val);
    matrix->data[0].i=row;
    matrix->data[0].j=col;
    matrix->data[0].v=val;
    int i=1;
    while(i!=amount){
        printf("非零元素的行号  非零元素的列号  非零元素:\n");
        scanf("%d %d %d",&row,&col,&val);
        matrix->data[i].i=row;
        matrix->data[i].j=col;
        matrix->data[i].v=val;
        i++;
    }
}

//稀疏矩阵相加函数,返回指向相加结果的矩阵的指针
spmatrix* matrix_add(spmatrix* a, spmatrix* b) {
    if(a->m != b->m || a->n != b->n){
        printf("ERROR!矩阵形状不同!\n");
        return NULL;
    }

    spmatrix* res = (spmatrix*)malloc(sizeof(spmatrix)); // 创建结果矩阵
    res->m=a->m;
    res->n=a->n;
    res->t=0;

    //遍历a矩阵和b矩阵中非零元素的"指针"
    int pa = 0, pb = 0; 
    //遍历结果矩阵res的三元组"指针"
    int pc=0;
    while (pa < a->t || pb < b->t) {
        if ((a->data[pa].i < b->data[pb].i || (a->data[pa].i == b->data[pb].i && a->data[pa].j < b->data[pb].j))&&a->data[pa].v!=0) {
            //a的非零元素的行下标小于b的    或者它们的行下标相同,但列下标a的小于b
            //则先将a中元素插入
            res->data[pc]=a->data[pa];
            pa++;
        } else if ((a->data[pa].i > b->data[pb].i || (a->data[pa].i == b->data[pb].i && a->data[pa].j > b->data[pb].j))&&b->data[pb].v!=0) {
            //a的非零元素的行下标大于b的    或者它们的行下标相同,但列下标a的大于b
            //则先将a中元素插入
            res->data[pc]=b->data[pb];
            pb++;
        } else {
            //a和b的非零元素行下标和列下标均相等
            //相加后加入到新矩阵中
            if(a->data[pa].v==0){
                res->data[pc]=b->data[pb];
            }else if(b->data[pb].v==0){
                res->data[pc]=b->data[pb];
            }else{
                res->data[pc]=a->data[pa];
            }
            res->data[pc].v=a->data[pa].v+b->data[pb].v;
            pa++;
            pb++;
        }
        if(res->data[pc].v != 0) {
           res->t++; // 只有当结果矩阵中的非零元素不为0时，才增加res->t的值
           pc++;
        }
    }
    return res;
}

int main(){
    printf("输入矩阵A:\n");
    spmatrix A;
    CreatMat(&A);
    printf("输入矩阵B:\n");
    spmatrix B;
    CreatMat(&B);
    spmatrix *res=matrix_add(&A,&B);
    printf("相加后的矩阵:\n");
    printf("矩阵的行数  矩阵的列数  非零元素个数\n%d      %d      %d\n",res->m,res->n,res->t);
    printf("行号    列号    值\n");
    for(int i=0;i<res->t;i++){
        printf("%d     %d     %d\n",res->data[i].i,res->data[i].j,res->data[i].v);
    }
    return 0;
}