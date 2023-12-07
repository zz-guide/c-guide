//
// Created by xulei on 2022/2/17.
//

#include "server.h"


#define PORT 20000
#define IP "127.0.0.1"
#define BUF_SIZE 1024
#define _FD_NUM_ 512
#define _FD_DEFAULT_VAL_ -1

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

typedef struct select_fd_t {
    int max_fd;                //记录最大文件描述符
    int fd_arr[_FD_NUM_];    //保存放到select监控集中的fd
} select_fd_t;

//初始化结构体
void init_select_set(select_fd_t *select_fd, int listen_fd) {
    select_fd->max_fd = listen_fd;  //监听新的链接
    select_fd->fd_arr[0] = listen_fd;
    for (int i = 1; i < _FD_NUM_; i++) {
        select_fd->fd_arr[i] = _FD_DEFAULT_VAL_;
    }
}

//把fd添加进数组里面，同时更新最大文件描述符
static void add_read_fd(fd_set *set, select_fd_t *select_fd) {
    for (int i = 0; i < _FD_NUM_; i++) {
        // 先判断有没有文件句柄
        if (select_fd->fd_arr[i] != _FD_DEFAULT_VAL_) {
            // 有的话加入，用来将一个给定的文件描述符加入集合之中
            FD_SET(select_fd->fd_arr[i], set);
            // 文件句柄最大值变更
            if (select_fd->fd_arr[i] > select_fd->max_fd) {
                select_fd->max_fd = select_fd->fd_arr[i];
            }
        }
    }
}

//在数组中为监听到的新的文件描述符分配最小的未被使用的数组下标，来存储
static int add_new_fd(select_fd_t *select_fd, int new_fd) {
    //当数组满了就会添加失败
    int i = 1;
    for (; i < _FD_NUM_; i++) {
        if (select_fd->fd_arr[i] == _FD_DEFAULT_VAL_) {
            select_fd->fd_arr[i] = new_fd;
            return 0;//yes
        }
    }
    return -1;
}

//读事件就绪后，对数据进行读取
static int read_data_show(int new_fd) {
    char buf[1024];
    ssize_t sz = 0;
    int total = 0;
    while ((sz = read(new_fd, buf + total, 64)) > 0) {
        total += sz;
    }
    if (sz == 0) {//success
        buf[total] = '\0';
        printf("client data : %s\n", buf);
        return 0;
    } else if (sz < 0) {
        perror("read");
        return -1;
    } else {
        //do nothing
        return 0;
    }
}

//将完成任务的文件描述符从文件描述符集中删除
static void delete_new_fd(select_fd_t *select_fd, int fd) {
    int i = 1;
    for (; i < _FD_NUM_; i++) {
        if (select_fd->fd_arr[i] == fd) {
            select_fd->fd_arr[i] = _FD_DEFAULT_VAL_;
        }
    }
}


int main() {
    // socket阶段，第一个参数为IP地址，第二个参数传输方式，第三个参数为具体的协议，0表示由操作系统自行选择，或者IPPROTO_TCP等
    int serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 返回值-1表示error
    if (serverSocket == -1) {
        error_handling("socket() error!");
    }

    // 准备一个 sockaddr_in 结构，初始化内存为0
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(IP); // ip转地址
    serverAddr.sin_port = htons(PORT);    // 端口转换字节序

    // bind阶段，绑定socket到ip端口
    if (bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        error_handling("bind() error!");
    }

    // listen阶段，并设置backlog,同时能处理的最大连接要求,
    if (listen(serverSocket, 1) == -1) {
        error_handling("listen() error!");
    }

    select_fd_t select_set;
    init_select_set(&select_set, serverSocket);
    fd_set r_set;   //可读文件描述符的集合
    while (1) {
        // 清空集合，不含有任何文件句柄
        FD_ZERO(&r_set);
        add_read_fd(&r_set, &select_set);
        struct timeval timeout = {30, 0};
        printf("开始监听\n");
        int res = select(select_set.max_fd + 1, &r_set, NULL, NULL, &timeout);
        if (res == 0) {
            perror("timeout!");
            break;
        } else if (res == -1) {
            perror("select");
            break;
        } else {
            printf("success res=%d\n", res);
            int i = 0;
            //遍历数组来确定哪一个文件描述符已经就绪
            for (; i < _FD_NUM_; i++) {
                int fd = select_set.fd_arr[i];
                // 先看是不是新链接
                if (i == 0 && FD_ISSET(fd, &r_set)) {   //listen_sock
                    struct sockaddr_in client;
                    socklen_t len = sizeof(client);
                    int new_fd = accept(fd, (struct sockaddr *) &client, &len);//继续监听新的链接
                    if (new_fd == -1) {
                        perror("accept");
                        continue;
                    }
                    if (0 == add_new_fd(&select_set, new_fd)) {//把新的链接加入数组里面
                        //do nothing
                    } else {//add error,arr is full
                        close(fd);//处理不了的链接就直接关闭这个链接
                    }
                    continue;
                }

                if (fd != _FD_DEFAULT_VAL_ && FD_ISSET(fd, &r_set)) {
                    if (0 == read_data_show(fd)) {//read success
                        delete_new_fd(&select_set, fd);
                        close(fd);
                    } else {
                        //do nothing
                    }
                }
            }
        }
    }


    return 0;
}

