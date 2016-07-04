#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char dna[100][51];
	int order[100], inversions[100] = {0};
	int n, m, temp;

	cin >> n >> m;

	for(int i=0; i < m; i++)
	{
		cin >> dna[i];
		order[i] = i;

		for (int j = 0; j < n; j++)
			for (int k = j+1; k < n; k++)
				if (dna[i][j] > dna[i][k])
					inversions[i] += 1;
	}

	for(int i=0; i < m; i++)
		for(int j=i+1; j < m; j++)
		{
			if (inversions[order[i]] > inversions[order[j]])
			{
				temp = order[i];
				order[i] = order[j];
				order[j] = temp;
			}
		}

	for(int i=0; i < m; i++)
		cout << dna[order[i]] << endl;

	return 0;
}
