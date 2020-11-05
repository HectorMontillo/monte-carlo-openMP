#include <math.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  srand(time(NULL));
  int i;         //(counter)
  double l;      //(lenght of needle)
  double n;      //(number of trials)
  double L;      //(width between lines)
  double x;      //(angle)
  double pi;     //(pi)
  double P = 0;  //(ammount of trials that worked)
  double d;      //(distance between centre of needle and line)
  double y;      //minimalizacja obliczeń
  double stosun; // (cantidad de ensayos a cantidad de ensayos exitosos)

  n = stoi(argv[1]);
  l = 1;
  L = 2;
  clock_t start, end;
  start = clock();

  for (i = 0; i < n; i++)
  {
    x = ((double)rand() / RAND_MAX) * 3.1415; //(random angle in radians)

    d = ((double)rand() / RAND_MAX) * L / 2; //(random needle lenght)

    y = (l / 2) * sin(x);

    if (d <= y)
    {
      P++;
    }
  }

  stosun = n / P;

  pi = stosun * 2 * l / L;

  end = clock();

  cout << n << "\t" << (double)(end - start) / CLOCKS_PER_SEC << "\t" << pi << "\t";
  return 0;
}