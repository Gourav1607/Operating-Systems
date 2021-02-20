// Program to copy files using system calls
#include <fcntl.h> // for read write system calls
#include <stdio.h>
#include <stdlib.h> // for exit
void copy(int old, int new1);
void main(int argc, char *argv[])
{
	int fdold, fdnew;
	if (argc != 3) //  3 arguments (a.out, and 2 files)
	{
		printf("needs two arguments\n");
		exit(-1);
	}
	fdold = open(argv[1], 0); // 0 -mode, takes existing file from argv and puts in fold variable
	if (fdold == -1)
	{
		printf("unable to open file\n");
		printf("%s", argv[1]);
		exit(-1);
	}
	fdnew = creat(argv[2], 0666); //0666 -mode create file which is in argv and puts in fdnew variable
	if (fdnew == -1)
	{
		printf("unable to create file\n");
		printf("%s", argv[2]); // s-string
		exit(-1);
	}
	copy(fdold, fdnew);
	exit(0);
}

void copy(int old, int new1)
{
	int count;
	char buffer[512];
	while ((count = read(old, buffer, sizeof(buffer))) > 0) // reads content from old and copy to buffer
		write(new1, buffer, count);							// copies from buffer to new
}
