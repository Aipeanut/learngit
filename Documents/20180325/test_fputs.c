#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	char buff[]="hello linux!\n";
	fp = fopen("./a.c","w+");//w a +
	if(fp == NULL)
	{
		printf("open file a.c failure\n");
		return -1;
	}
	printf("open file a.c sucess\n");
	fputs(buff,fp);
	fflush(fp);
	while(1);

	fclose(fp);
	return 0;
}