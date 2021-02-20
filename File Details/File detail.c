//Program to print file details
#include <stdio.h>
#include <sys/stat.h> //stat.h is used to get statistics of any file, its part of system directory
int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	if (argc < 2)
		printf("usage <File name list for which stats is needed> %s\n",
			   argv[1]);
	for (i = 1; i < argc; i++) //to get stats of more than one file
	{
		printf("\nFile : %s", argv[i]);
		if (stat(argv[i], &buf) < 0) //to check if attributes are there
		{
			printf("Error in obtaining file stats \n");
		}
		else
		{
			printf("\n Owner uid = %d", buf.st_uid);		//every file has its user id
			printf("\n gid = %d \n", buf.st_gid);			// it is group id
			printf("Access permissions = %d", buf.st_mode); //access rights
			printf("\nAccess time = %d\n", buf.st_atime);	//access time of file
		}
	}
	return 0;
}
