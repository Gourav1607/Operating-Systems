#include <iostream>
#include <unistd.h>
#include <wait.h>

using namespace std;

int main(int argc, char *argv[])
{
	int pid = fork();
	if (pid == 0)
	{
		char *temp[10];
		int i;
		for (i = 1; i < argc; i++)
			temp[i - 1] = argv[i];

		temp[i - 1] = (char *)0;

		execvp(temp[0], temp);

		cout << endl
			 << "Command failed ";
	}
	else
	{
		int s;
		int p = (int)wait((void *)&s);
		cout << s / 256 << endl;
	}
	return 1;
}
