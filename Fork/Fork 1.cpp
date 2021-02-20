#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int num, i, fact = 1;

	int pid = fork();

	cout << endl
		 << "Enter number ";
	cin >> num;

	for (i = 1; i <= num; i++)
		fact = fact * i;
	cout << endl
		 << "Factorial is " << fact;
	cout << endl
		 << "Process number " << getpid();
	return 1;
}
