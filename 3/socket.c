//
// Created by Administrator on 2021/9/26.
//



#include <winsock.h>
#include <io.h>
#include "stdio.h"

#define PORT 8090
#define SIZE 1024

/**
 *
 * 服务端
 * @return
 */
int server_socket()    //创建套接字和初始化以及监听函数
{
    //af ,地址族（Address Family）,常用AF_INET(IPv4) 和 AF_INET6(IPv6)。
    //type ,数据传输方式，常用的有 SOCK_STREAM(面向连接)和 SOCK_DGRAM(无连接)
    //protocol 表示传输协议，常用的有 IPPROTO_TCP(TCP协议) 和 IPPTOTO_UDP(UDP协议)
    int listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);   //创建一个负责监听的套接字
    if (listen_socket == -1) {
        perror("socket");
        return -1;
    }
    //struct sockaddr_in{
    //    sa_family_t     sin_family;   //地址族（Address Family），也就是地址类型
    //    uint16_t        sin_port;     //16位的端口号
    //    struct in_addr  sin_addr;     //32位IP地址
    //    char            sin_zero[8];  //不使用，一般用0填充
    //};
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));//每个字节都用0填充

    addr.sin_family = AF_INET;  /* Internet地址族 使用IPv4地址*/
    addr.sin_port = htons(PORT);  /* 端口号 */
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* IP地址 */
    //将套接字与特定的IP地址和端口绑定起来
    int ret = bind(listen_socket, (struct sockaddr *) &addr, sizeof(addr));  //连接
    if (ret == -1) {
        perror("bind");
        return -1;
    }
    //sock 需要进入监听状态的套接字
    //backlog 请求队列的最大长度
    //套接字进入被动监听状态
    ret = listen(listen_socket, 20);        //监听
    if (ret == -1) {
        perror("listen");
        return -1;
    }

    struct sockaddr_in cliaddr;
    int addrlen = sizeof(cliaddr);
    printf("等待客户端连接。。。。\n");
    //套接字进入被动监听状态
    //sock 为服务器端套接字
    //addr 为 sockaddr_in 结构体变量
    //addrlen 为参数 addr 的长度，可由 sizeof() 求得
    int client_socket = accept(listen_socket, (struct sockaddr *) &cliaddr, &addrlen);
    if (client_socket == -1) {
        perror("accept");
        return -1;
    }
    printf("成功接收到一个客户端：%s\n", inet_ntoa(cliaddr.sin_addr));


    //接受请求
    char buf[SIZE];
    while (1) {
        //读取数据
        //fd 为要写入的文件的描述符
        //buf 为要写入的数据的缓冲区地址
        //nbytes 为要写入的数据的字节数。
        int ret = read(client_socket, buf, SIZE - 1);
        if (ret == -1) {
            perror("read");
            break;
        }
        if (ret == 0) {
            break;
        }
        buf[ret] = '\0';
        int i;
        for (i = 0; i < ret; i++) {
            buf[i] = buf[i] + 'A' - 'a';
        }

        printf("%s\n", buf);
        write(client_socket, buf, ret);

        if (strncmp(buf, "end", 3) == 0) {
            break;
        }
    }
    close(client_socket);


    return 0;
}


int  main(){
    server_socket();

}