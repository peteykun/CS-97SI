#include <iostream>
#include <math.h>
using namespace std;

long int Z(long int n)
{
  long int count = 0;
  long int mult = 5;

  while (mult <= n)
  {
    count += n/mult;
    mult *= 5;
  }

  return count;
}

int main()
{
  long int t;
  long int n;

  cin >> t;

  while(t--)
  {
    cin >> n;
    cout << Z(n) << endl;
  }

  return 0;
}
