#include <stdio.h>

//
// Created by Administrator on 2021/9/23.
//
/**
 * 基本数据类型
 *
 *
 * @return
 */
int main() {

    int a = 1;

    printf("int的长度为：%llu\n",sizeof(a));
    long b = 1L;
    printf("long的长度为：%llu\n",sizeof(b));
    short c = 1;
    printf("short的长度为：%llu\n",sizeof(c));
    float dd = 1;
    printf("float的长度为：%llu\n",sizeof(dd));

    double d = 1.0;
    printf("double的长度为：%llu\n",sizeof(d));
    char e = 'e';
    printf("char的长度为：%llu\n",sizeof(e));


    long int qq = 1;
    printf("long int的长度为：%llu\n",sizeof(qq));
    short int cs =1;
    printf("short int的长度为：%llu\n",sizeof(cs));
    long  long  qqc = 13L;
    printf("long long的长度为：%llu\n",sizeof(qqc));
    long double ld =0.1;
    printf("long double的长度为：%llu\n",sizeof(qqc));

    unsigned char cc = 31;
    unsigned int ac = 31;
    unsigned long bc = 31;
    unsigned short dc = 31;

    int *A = &a;
    long *B = &b;
    char *C = &e;
    printf("int指针的长度为：%llu\n",sizeof(A));
    printf("long 指针的长度为：%llu\n",sizeof(B));
    printf("char 指针的长度为：%llu\n",sizeof(C));


    return 0;
}