#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	double balance;
	int sum = 0;

	for (int i = 0; i < 12; i++)
	{
		cin >> balance;
		sum += balance * 100;
	}

	sum /= 12;
	cout << "$" << sum/100 << "." << sum%100;
	return 0;
}
