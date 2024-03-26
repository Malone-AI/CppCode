// C语言文件读写
#include <stdio.h>

int main(){
    FILE *fp = NULL;
    fp = fopen("test/test4.text","w+");
    fprintf(fp,"This is a test for fprintf...\n");
    fputs("This is a test for fputs...\n",fp);
    fclose(fp);
    return 0;
}