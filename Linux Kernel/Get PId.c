//program using getpid()
#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid;
	pid = fork();
	if (pid < 0)
	{
		printf("fork failed,no child created");
		return 1;
	}
	else if (pid == 0)
	{ //child
		printf("child's processid is %d \n", getpid());
		printf("child complete\n");
	}
	else
	{ //parent
		wait(NULL);
		printf("parent's processid is %d \n", getpid());
		printf("child complete\n");
	}
	return 0;
}
