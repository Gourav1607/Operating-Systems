//program for Pthread library-single thread
#include <pthread.h>
#include <stdio.h>

int fact;
void *runner(void *param);
int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	if (argc != 2)
	{
		printf("wrong number of parameters\n");
		return -1;
	}

	if (atoi(argv[1]) < 0)
	{
		printf(" %d must be >0\n", atoi(argv[1]));
		return -1;
	}

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);
	pthread_join(tid, NULL);

	printf("Factorial = %d\n", fact);
}

void *runner(void *param)
{
	int i, upper = atoi(param);
	fact = 1;

	for (i = upper; i > 0; i--)
		fact = fact * i;

	pthread_exit(0);
}
