#include <iostream>
#include <math.h>
#include <stdio.h>
#define PI 3.141592653589793

using namespace std;

int main()
{
  double x1, y1, x2, y2, x3, y3, a, b, c, d, e, f, h, k, temp, r;

  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
  {
    a = 2 * (y2 - y1);
    b = 2 * (x2 - x1);
    c = x1 * x1 - x2 * x2 - y2 * y2 + y1 * y1;

    d = 2 * (y3 - y2);
    e = 2 * (x3 - x2);
    f = x2 * x2 - x3 * x3 - y3 * y3 + y2 * y2;

    temp = b*d - a*e;
    h = (c*e - b*f)/temp;
    k = (a*f - c*d)/temp;

    r = sqrt((h - x1) * (h - x1) + (k - y1) * (k - y1));
    printf("%.2lf\n", 2 * PI * r);
  }

  return 0;
}
