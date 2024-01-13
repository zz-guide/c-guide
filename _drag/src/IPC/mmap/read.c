#include "common.h"

/**
 * https://www.cnblogs.com/huxiao-tee/p/4660352.html
 * mmap是一种内存映射文件的方法，即将一个文件或者其它对象映射到进程的地址空间，实现文件磁盘地址和进程虚拟地址空间中一段虚拟地址的一一对映关系。
 * 实现这样的映射关系后，进程就可以采用指针的方式读写操作这一段内存，而系统会自动回写脏页面到对应的文件磁盘上，
 * 即完成了对文件的操作而不必再调用read,write等系统调用函数。相反，内核空间对这段区域的修改也直接反映用户空间，从而可以实现不同进程间的文件共享。
 *
 * 举个例子：本地文件如何上传到服务器？
 *  1.本地修改完毕，scp拷贝到linux服务器。
 *  2.本地文件通过sftp直接映射到linux服务器，做同步修改。
 *
 *
 *  https://www.jianshu.com/p/755338d11865
 *  私有映射(MAP_PRIVATE)：多进程间数据共享，修改不反应到磁盘实际文件，是一个copy-on-write（写时复制）的映射方式。
 *  共享映射(MAP_SHARED)：多进程间数据共享，修改反应到磁盘实际文件中。
 *
 *  1、文件映射
        磁盘文件映射进程的虚拟地址空间，使用文件内容初始化物理内存。
        2、匿名映射
        初始化全为0的内存空间。


    优点：
        1.文件读取不经过页缓存，减少一次数据拷贝，内存I/O，提高效率
        2.实现了用户空间和内核空间的高效交互方式。两空间的各自修改操作可以直接反映在映射的区域内，从而被对方空间及时捕捉。
        3.可用于实现高效的大规模数据传输。内存空间不足，是制约大数据操作的一个方面，解决方案往往是借助硬盘空间协助操作，补充内存的不足。但是进一步会造成大量的文件I/O操作，极大影响效率。这个问题可以通过mmap映射很好的解决。换句话说，但凡是需要用磁盘空间代替内存的时候，mmap都可以发挥其功效。
    缺点：
        1.不适合太小的文件，因为是以页为单位映射的，会浪费内存空间
        2.不适合变长的文件，无法拓展，映射的时候，大小已经固定了
        3.如果更新文件的操作很多，会触发大量的脏页回写及由此引发的随机IO上。所以在随机写很多的情况下，mmap方式在效率上不一定会比带缓冲区的一般写快。
 */


struct struct_stu{
	int id;
	char name[20];
	char sex;
};
void sys_error(const char* strDes,int erron){
	perror(strDes);
	exit(erron);
}

/**
 * mmap将一个文件或者其它对象映射进内存。文件被映射到多个页上，如果文件的大小不是所有页的大小之和，最后一个页不被使用的空间将会清零。mmap在用户空间映射调用系统中作用很大
 */

int main(int argc,const char* argv[]){
	int fd_mmap_shared,mmap_file_size;
	struct struct_stu* p_mmap;
	//创建进程间通信的mmap共享文件
	fd_mmap_shared=open("./mmap.temp",O_RDWR|O_CREAT,0777);
	if(fd_mmap_shared<0)
		sys_error("创建文件失败，请确定是否有权限操作！",-1);
	//获取文件大小，保证共享文件大小不能为0
	mmap_file_size = lseek(fd_mmap_shared,SEEK_END,0);
	if(mmap_file_size < 1){
		close(fd_mmap_shared);
		sys_error("mmap共享文件大小不能为0",-2);
	}

	p_mmap=(struct struct_stu*)mmap(NULL,mmap_file_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd_mmap_shared,0);
	close(fd_mmap_shared);//文件映射创建无论成功与否，后面操作无需直接操作文件了，因为磁盘文件和虚拟内存直接映射了
	//共享内存文件应该是一个临时文件，所以需要unink	
	if(unlink("./mmap.temp")==-1)
		sys_error("共享内存文件设置为临时文件失败",-3);

	if(MAP_FAILED == (void*)p_mmap)
		sys_error("创建文件映射失败！",-2);
	
	//不断的向文件中输入内容
	while(1){
		printf("id:%d,name:%s,sex:%c\n",p_mmap->id,p_mmap->name,p_mmap->sex);//这里是覆盖的写一个字段 mmap_索引号
		sleep(1);
	}

	munmap(p_mmap,mmap_file_size);
	return 0;
}
