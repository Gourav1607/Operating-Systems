#include<iostream>
#include<pthread.h>
#include<fcntl.h>
using namespace std;
void *runner(void *param);
int fin;
int fout;
int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "\nSyntax incorrect:copy <src> <dst>";
		return 1;
	}
	//fin=open(argv[1],O_RDONLY,0666);
	pthread_t tid;
	pthread_create(&tid, NULL, runner, argv[2]);
	fin = open(argv[1], O_RDONLY, 0666);
	pthread_join(tid, NULL);
	return 0;
}
void *runner(void *param) {
	int n;
	//String fname=(char *)param;
	fout = open((char *) param, O_WRONLY | O_CREAT, 0666);
	char ary[15];
	//char ary1[10];
	//ary1[1]='a';
	while (n = read(fin, ary, sizeof(ary))) {
		write(fout, ary, n);
		//cout<<ary;
	}
}

