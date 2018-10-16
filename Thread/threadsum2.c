//Program using two threads namely sum and factorial
#include<pthread.h>
#include<stdio.h>

int sum1, sum2, fact;
//parameters are passed through pointers
void *runner(void *param);
void *runner2(void *param);
//argc- number of param, argv- the actual values
int main(int argc, char *argv[]) {
	pthread_t tid, tid2; //pthread- data type, tid- thread identifier
	pthread_attr_t attr, attr2; //attributes of thread

	if (argc != 2) {
		printf("wrong number of parameters\n");
		return -1;
	}
//ascii to integer
	if (atoi(argv[1]) < 0) //input only positive integers
			{
		printf(" %d must be >=0\n", atoi(argv[1]));
		return -1;
	}
//get the default attributes
	pthread_attr_init(&attr); //the defined attributes are passed to threads
	pthread_attr_init(&attr2);
	pthread_create(&tid, &attr, runner, argv[1]); //when thread is created, it gets id num, attributes, function for summation and values(parameters)
	pthread_create(&tid2, &attr2, runner2, argv[1]);
	pthread_join(tid, NULL); //parent will call the join() function to know if child thread is complete
	pthread_join(tid2, NULL);
	printf("Sum of even numbers = %d\n", sum1);
	printf("\n sum of odd numbers=%d\n", sum2);
	printf("Factorial = %d\n", fact);
}
//runner is the function called to execute the child thread
void *runner(void *param) {
	int i, upper = atoi(param);
	sum1 = 0;
	sum2 = 0;

	for (i = upper; i >= 0; i--) {
		if (i % 2 == 0)
			sum1 += i;
		else
			sum2 += i;
	}
	pthread_exit(0);
}

void *runner2(void *param) {
	int i, upper = atoi(param);
	fact = 1;

	for (i = upper; i > 0; i--)
		fact = fact * i;
	pthread_exit(0);
}
