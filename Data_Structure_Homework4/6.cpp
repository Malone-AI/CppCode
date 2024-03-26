#include <stdio.h>
#include <stdlib.h>

void Get_Saddle(int **A,int rows,int cols){/*找出矩阵中的马鞍点*/
    int min;/*min用于存放每行元素的最小值及其下标*/
    int col;/*min所在的列索引*/
    int i;
    for(i=0;i<rows;i++){
        min=A[i][0];
        col=0;
        for(int j=1;j<cols;j++){
            if(A[i][j]<min){
                min=A[i][j];
                col=j;
            }
        }
        int k=0;
        for(k=0;k<rows;k++){
            if(min<A[k][col]){
                break;
            }
        }
        if(k==rows){
            printf("找到马鞍点!\nA[%d][%d] = %d",i,col,A[i][col]);
            return ;
        }
    }
    printf("没有马鞍点\n");
}

int main(){
    int rows,cols;

    printf("请输入矩阵的行数和列数:\n");
    scanf("%d %d",&rows,&cols);

    int **A = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("请输入矩阵:\n");
    for(int i=0;i<rows;i++){/*初始化矩阵*/
        for(int j=0;j<cols;j++){
            scanf("%d",&A[i][j]);
        }
    }

    Get_Saddle(A,rows,cols);

    for (int i = 0; i < rows; i++) {/*释放分配的内存*/
        free(A[i]);
    }
    free(A);

    return 0;
}