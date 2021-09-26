//
// Created by Administrator on 2021/9/26.
//
#include <stdlib.h>
# include "stdio.h"
#define N 5
void consoleIo();
void fileIo();

int main() {

    fileIo();
}

void consoleIo() {
    int a;
    char p[10];
    scanf("%d", &a);
    scanf("%s", p);
    printf("%d\n", a);
    printf("%s\n", p);
}

void fileIo(){

    //从键盘输入的数据放入a，从文件读取的数据放入b
    int a[N], b[N];
    int i, size = sizeof(int);
    FILE *fp;
    if( (fp=fopen("C:\\rere.txt", "rb+")) == NULL ){  //以二进制方式打开
        puts("Fail to open file!");
        return;
    }

    //从键盘输入数据 并保存到数组a
    for(i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    //将数组a的内容写入到文件
    fwrite(a, size, N, fp);
    //将文件中的位置指针重新定位到文件开头
    rewind(fp);
    //从文件读取内容并保存到数组b
    fread(b, size, N, fp);
    //在屏幕上显示数组b的内容
    for(i=0; i<N; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    fclose(fp);

}