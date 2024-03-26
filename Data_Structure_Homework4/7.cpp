#include <stdio.h>

//基本思想:
//1.先统计出数组中奇数记为odd、偶数个数记为even
//2.然后遍历数组前x个元素，如果是奇数则继续向后遍历
//3.如果是偶数则当前元素与arr[odd+evenIndex]交换数值
//4.evenIndex初始设为0,每进行一次3中操作自增一次
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int CountOdd(int *arr,int n){/*统计奇数个数*/
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==1){
            count++;
        }
    }
    return count;
}

void reorder(int *arr,int n){/*重排数组*/
    int odd=CountOdd(arr,n);/*统计数组中奇偶数个数*/
    int even=n-odd;
    int evenIndex=0;
    int i=0;
    while(i!=odd){
        if(arr[i]%2==0&&evenIndex!=even){
            swap(&arr[i],&arr[odd+evenIndex]);
            evenIndex++;
        }else{
            i++;
        }
    }
}

int main(){
    printf("请输入正整数个数:");
    int n;
    scanf("%d",&n);
    int array[n];
    printf("请输入这一系列数(空格分开):\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    reorder(array,n);
    printf("重排后的数组:\n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}