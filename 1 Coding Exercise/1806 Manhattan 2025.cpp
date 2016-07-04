#include <iostream>
using namespace std;

int main()
{
  int t, u, mid, line_mid, curr;
  cin >> t;

  for (int scenario=1; scenario <= t; scenario++)
  {
    cin >> u;

    cout << "Scenario #" << scenario << ":" << endl;

    for (int slice=0; slice < 2*u + 1; slice++)
    {
      cout << "slice #" << slice + 1 << ":" << endl;

      if (slice < u)
        mid = u - slice;
      else
        mid = slice - u;

      for (int i=0; i < 2*u + 1; i++)
      {
        if (i < u)
          line_mid = mid + (u - i);
        else
          line_mid = mid + (i - u);
  
        for (int j = 0; j < 2*u + 1; j++)
        {
          if (j < u)
            curr = line_mid + (u - j);
          else
            curr = line_mid + (j - u);

          if (curr > u)
            cout << ".";
          else
            cout << curr;
        }

        cout << endl;
      }
    }

    cout << endl;
  }

  return 0;
}
