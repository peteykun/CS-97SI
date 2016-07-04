#include <iostream>
using namespace std;

int rev_sum(int a, int b)
{
	int rev_a = 0, rev_b = 0, res = 0, rev_res = 0;

	while (a > 0)
	{
		rev_a = rev_a*10 + a%10;
		a /= 10;
	}

	while (b > 0)
	{
		rev_b = rev_b*10 + b%10;
		b /= 10;
	}

	rev_res = rev_a + rev_b;

	while (rev_res > 0)
	{
		res = res*10 + rev_res%10;
		rev_res /= 10;
	}

	return res;
}

int main()
{
	int t, a, b;
	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		cout << rev_sum(a, b) << endl;
	}
	
	return 0;
}
