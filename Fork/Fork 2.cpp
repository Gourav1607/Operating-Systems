#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	int i, num, a, b, fact = 1, sum = 0, k = 1;
	int pid = fork();

	if (pid == 0)
	{
		while (k != 3)
		{
			cout << endl
				 << "Enter number(factorial) ";
			cin >> num;
			for (i = 1; i <= num; i++)
				fact = fact * i;
			cout << endl
				 << "Factorial is " << fact;

			k++;
		}
	}
	else
	{
		while (k != 3)
		{
			cout << endl
				 << "Enter first number ";
			cin >> a;
			cout << endl
				 << "Enter second number ";
			cin >> b;
			sum = a + b;
			cout << endl
				 << "Sum is " << sum;

			k++;
		}
	}

	return 1;
}
