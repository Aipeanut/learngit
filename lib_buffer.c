#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char buff[]="hello linux";
	printf("%s\n",buff);// no \n  or  lib_buffer full 1024 bite
	//write(1,buff,sizeof(buff));
	//while(1);
	return 0;
}