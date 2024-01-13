//
// Created by xulei on 2021/11/27.
//

#include "server.h"

/*
名字与地址转换
过时，仅用于IPv4，线程不安全
gethostbyaddr--此函数智能获取域名解析服务器的url和/etc/hosts里面登记的IP对应的域名

*/

int main(int argc, char *argv[]){
    char str[128];

    // 1.将IP地址转换成addr
    struct in_addr addr;
    char *ip = "127.0.0.1";
    inet_pton(AF_INET, ip, &addr);

    struct hostent *host;
    host = gethostbyaddr((char*)&addr,4,AF_INET);
    printf("official name of host:%s\n", host->h_name);
    while (*(host->h_aliases) != NULL)
        printf("alias name of host--:%s\n", *host->h_aliases++);
    switch (host->h_addrtype) {
        case AF_INET:
            while (*(host->h_addr_list) != NULL)
                printf("addresses:---%s\n", inet_ntop(AF_INET, (*host->h_addr_list++), str, sizeof(str)));
            break;
        default:
            printf("unknown address type\n");
            break;
    }

    return 0;
}