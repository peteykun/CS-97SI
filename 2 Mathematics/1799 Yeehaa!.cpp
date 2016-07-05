#include <math.h>
#include <stdio.h>
#define PI 3.14159

int main()
{
  int t, n;
  double R, r;
  scanf("%d", &t);

  for (int i=1; i <= t; i++)
  {
    scanf("%lf %d", &R, &n);
    r = R * sin(3.14159/n) / (1 + sin(3.14159/n));
    printf("Scenario #%d:\n%.3lf\n\n", i, r);
  }

  return 0;
}
