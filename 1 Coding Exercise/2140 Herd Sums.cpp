#include <iostream>
using namespace std;

int main()
{
	int i, j, N, result, current_sum;
	cin >> N;

	result = 1;

	for (i=1; i <= N/2; i++)
	{
		current_sum = 0;

		for (j=i; current_sum < N; j++)
			current_sum += j;

		if (current_sum == N)
			result++;
	}

	cout << result << endl;
	return 0;
}
