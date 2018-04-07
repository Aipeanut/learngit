#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	fd=open(argv[1],O_CREAT|O_RDWR,0777);
	if(fd<0){
		printf("creat file %s failure\n",argv[1] );
		return -1;
	}
	printf("creat file %s success,fd=%d\n",argv[1],fd);
	close(fd);
	return 0;
}