#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
  long int t, n;
  bool *seive;

  // Set up the seieve
  seive = (bool*) malloc(sizeof(bool) * 1000000);

  for (long int i = 2; i < 1000000; i++)
    seive[i] = true;

  for (long int i = 2; i < sqrt(1000000); i++)
    if (seive[i])
      for (long int j=i*i; j < 1000000; j+=i)
        seive[j] = false;

  while (true)
  {
    cin >> n;

    if (n == 0)
      break;

    // Look at pairs
    for (long int i=1; i < n; i++)
      if (seive[i] && seive[n-i])
      {
        cout << n << " = " << i << " + " << n-i << endl;
        break;
      }
  }

  return 0;
}
