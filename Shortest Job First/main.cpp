/*
 *  SJF
 *  Created on: 16-Nov-2014
 *      Author: Gourav Siddhad
 */

#include "sjf.h"
using namespace std;

int main()
{
	int a = 0;
	cout << "\n  Enter The Number Of Processes : ";
	cin >> a;

	const int n = a;
	PCB p[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\n Process : " << i;
		p[i].input();
	}

	sort(p, n);
	sjf(p, n);
	printtable(p, n);
}
