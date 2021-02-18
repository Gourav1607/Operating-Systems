#include<iostream>
#include<unistd.h>
#include<wait.h>

using namespace std;

int main(int argc, char * argv[]) {
	cout << endl << "Arguments are ";
	for (int i = 1; i < argc; i++)
		cout << argv[i] << " ";
	cout << endl;

	return 2;
}

