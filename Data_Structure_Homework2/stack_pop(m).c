#include <stdio.h>
#include <stdlib.h>

#define maxsize 1024
typedef int datatype;

//顺序栈结构体
typedef struct{
    datatype data[maxsize];
    int Top;
}SeqStack;

//建立空的顺序栈
SeqStack* InitStack(){
    //构造一个空栈
    SeqStack *S;
    S=(SeqStack *)malloc(sizeof(SeqStack));//生成顺序栈空间
    S->Top=-1;//栈顶指针置为-1
    return S;
}

//顺序栈置空
void SetNull(SeqStack *S){
    S->Top=-1;//栈顶指针置为-1
}

//顺序栈入栈
int Push(SeqStack *S,datatype x){
    //若栈S未满，则将元素x插入栈顶，并返回1，表示入栈成功
    //若栈S已满，即S->Top=maxsize-1,此时返回0，表示入栈不成功
    if(S->Top!=maxsize-1){
        S->data[++S->Top]=x;
        return 1;
    }else{
        printf("栈上溢\n");
        return 0;
    }
}

//顺序栈栈顶元素出栈
//int Pop(SeqStack *S,datatype *x){
int Pop(SeqStack *S){
    //若栈不为空，则删除栈顶元素，由指针x带回栈顶元素，并返回1,表示出栈成功
    //否则返回0,表示出栈失败
    if(S->Top!=-1){
        //*x=S->data[S->Top];
        S->Top--;
        return 1;
    }else{
        printf("栈下溢\n");
        return 0;
    }
}

//删除顺序栈中所有值为m的元素
int Delete(SeqStack *S,datatype m){
    //将要进行操作的栈复制一份
    SeqStack copy=*S;
    //置空要执行操作的栈
    SetNull(S);
    //对copy栈进行出栈操作直至栈空
    while (copy.Top!=-1)
    {
        //如果copy栈顶元素不等于m，则将该元素压入S栈内,并弹出copy栈的栈顶元素
        //否则直接弹出copy栈的栈顶元素
        if(copy.data[copy.Top]!=m){
            Push(S,copy.data[copy.Top]);
        }
        Pop(&copy);
    }
    return 1;
}

int main(){
    SeqStack *stk=InitStack();
    datatype temp;
    scanf("%d",&temp);
    //进行多次入栈操作,以-1为结束标志
    while(temp!=-1){
    	Push(stk,temp);
    	scanf("%d",&temp);
	}
    printf("请输入需要删除的元素的值:\n");
    datatype m;
    scanf("%d",&m);
    Delete(stk,m);
    //逐个弹出删除所有值等于m的元素后的栈
    while (stk->Top!=-1)
    {
        printf("%d ",stk->data[stk->Top]);
        Pop(stk);
    }
    return 0;    
}