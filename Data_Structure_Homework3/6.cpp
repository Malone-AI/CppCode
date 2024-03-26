#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

void strDelete(char *S,int i,int m){
    //删除所用辅助字符串
    if(i>=strlen(S)){
        return;
    }else if(i+m>=strlen(S)){
        S[i]='\0';
    }else{
        //用S中第i+m后的字符串覆盖S中第i个单元格后的字符串
        strcpy(S+i,S+i+m);
    }
}

int main(){
    char ch[N];
    printf("请输入字符串S:\n");
    scanf("%s",ch);
    int i,m;
    printf("请输入i m\n");
    scanf("%d %d",&i,&m);
    strDelete(ch,i,m);
    printf("删除操作后的字符串S:\n");
    printf("%s\n",ch);
    system("pause");
    return 0;
}