#include "../common.h"

#define BUF_SIZE (4*1024)
#define FIFO_PATH "./test_fifo"

//自己做一个出错信息函数，重复的代码
void sys_error(const char *reason, int errnu) {
    perror(reason);
    exit(errnu);
}

int main(int argc, const char *argv[]) {
    int fd;
    char buffer[BUF_SIZE];
    //从fifo中读数据
    fd = open(FIFO_PATH, O_RDONLY);
    if (-1 == fd) {
        sys_error("open failed:", -2);
        return -1;
    }

    bzero(buffer, sizeof(buffer));
    if (-1 == read(fd, buffer, sizeof(buffer))) {
        close(fd);
        sys_error("read failed:", -3);
    }

    printf("read datas:%s\n", buffer);

    close(fd);
    return 0;
}
