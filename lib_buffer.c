#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char buff[]="hello linux";
	write(1,buff,sizeof(buff));
	return 0;
}