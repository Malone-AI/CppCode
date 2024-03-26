#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void strDelete(char *S,int m,int t){
    //temp存储被删除的部分
    char temp[N];
    strncpy(temp,S+m,t);

    strcpy(S+m,S+m+t);
    //将删除的部分追加到字符串中
    strncat(S,temp,sizeof(temp));
    printf("最终的字符串:\n%s\n",S);
}

int main(){
    char ch[N];
    printf("请输入字符串S:\n");
    scanf("%s",ch);
    int m,t;
    printf("请输入m t\n");
    scanf("%d %d",&m,&t);
    strDelete(ch,m,t);
    system("pause");
    return 0;
}