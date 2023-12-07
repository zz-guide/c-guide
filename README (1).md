#笔记
1.GCC编译选项CFLAGS参数
2.GCC链接选项LDFLAGS参数
3.PKG_CONFIG_PATH
4.完整的报错信息： ld: 1 duplicate symbol for architecture x86_64  clang: error: linker command failed with exit code 1 (use -v to see invocation)
即：在链接阶段，发现“重复定义”。

5.查看宏替换后的文件内容
gcc -C -E ./main.c -o my_pre.log
6.尽量不要include .c文件
7.因为cMakeLists.txt add_executable配置的关系导致引入.c文件一直编译失败
8.main函数必须是有返回值的，符合规范
9.__attribute__含义


###安装第三方库
1.mysql: https://dev.mysql.com/downloads/connector/cpp/
2.gcc编译选项: https://blog.csdn.net/zhizhengguan/article/details/111743586