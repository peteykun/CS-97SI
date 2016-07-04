#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	double length, sum[300];
	int cards;

	// Precompute distances
	sum[1] = 0.5;

	for(int i = 2; i < 300; i++)
		sum[i] = sum[i-1] + 1.0/(i+1.0);

	while(true)
	{
		cin >> length;

		if(length == 0)
			return 0;

		cards = 1;

		while (sum[cards] < length)
			cards += 1;

		cout << cards << " card(s)" << endl;
	}
}
