#include<iostream>
#include<stdio.h>
#include<pthread.h>

using namespace std;

int sum;
void *runner(void *param);

int main(int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t atb;

	if (argc != 2) {
		cout << endl << "usage:a.out<integer value>\n";
		return -1;
	}

	if (atoi(argv[1]) < 0) {
		cout << endl << "must be an integer>=0 \n" << atoi(argv[1]);
		return 1;
	}
	pthread_attr_init(&atb);
	pthread_create(&tid, &atb, runner, argv[1]);
	pthread_join(tid, NULL);
	cout << endl << "Sum =" << sum;
	return 0;
}

void *runner(void *param) {
	int i;
	int upper = atoi((char *) param);
	sum = 0;

	for (i = 1; i <= upper; i++)
		sum += i;
	pthread_exit(0);
}
