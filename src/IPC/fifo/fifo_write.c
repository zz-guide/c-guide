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
    char buffer[BUF_SIZE] = "fifo通信";

    // 不存在就创建
    if (access(FIFO_PATH, F_OK) != 0) {
        mkfifo(FIFO_PATH, 0666);
    }

    fd = open(FIFO_PATH, O_WRONLY);
    if (-1 == fd) {
        sys_error("open failed:", -2);
        return -1;
    }

    if (-1 == write(fd, buffer, strlen(buffer) + 1)) {
        close(fd);
        sys_error("write failed:", -3);
    }

    close(fd);
    return 0;
}
