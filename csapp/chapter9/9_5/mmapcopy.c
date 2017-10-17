#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

//error wrapper
void unix_error(char * msg)
{
	fprintf(stderr, "%s:%s\n", msg, strerror(errno));
	exit(0);
}


//open wrapper
int Open(const char * pathname, int flags, mode_t mode)
{
	int rc;
	if((rc=open(pathname, flags, mode))<0)
		unix_error("Open error");
	return rc;
}


//write wrapper
ssize_t Write(int fd, const void * buf, size_t count)
{
	ssize_t rc;
	if((rc=write(fd, buf, count))<0)
		unix_error("Write error");
	return rc;
}


//mmap wrapper
void * Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	void * ptr;
	//(void*)-1 means a invalid address
	if((ptr=mmap(addr, len, prot, flags, fd, offset))==((void *)-1))
		unix_error("mmap error");
	return (ptr);
}

//mmapcopy: copy a random size of block to stdout
void mmapcopy(int fd, int size)
{
	char * bufp;
	//arg1:addr=NULL,the kernel choose the address where to create the mapping
	//arg2:length=size, use length bytes starting at offset
	//arg3:prot=PROT_READ, the desired memory protection way is: Page may be read.
	//arg4:flag=MAP_PRIVATE, whether updates to the mapping are visible to other processes mapping the same region
	//and whether the updates are carried through to the underlying file. MAP_PRIVATE:create a private copy-on-write mapping.
	//arg5:fd=fd, file descriptor
	//arg6:offset=0, offset must be a multiple of the page size
	bufp = Mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	Write(1, bufp, size);
	return;
}



int main(int argc, char **argv)
{
	struct stat stat;
	int fd;
	
	if(argc != 2)
	{
		printf("usage:%s <filename>\n", argv[0]);
		exit(0);
	}
	fd = Open(argv[1], O_RDONLY, 0);

	//fstat:get information of a file
	fstat(fd, &stat);
	mmapcopy(fd, stat.st_size);
	exit(0);
}
