#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, temp, answer, speed[10000], departure[10000], arrival[10000];

	while(true)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i=0; i < n; i++)
		{
			cin >> speed[i] >> departure[i];
			arrival[i] = departure[i] + ceil(16200.0/speed[i]);
		}

		answer = -1;

		for (int i=0; i < n; i++)
			if ((answer == -1 || arrival[i] < arrival[answer]) && departure[i] >= 0)
				answer = i;

		cout << arrival[answer] << endl;
	}
}
