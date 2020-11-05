#include <iostream>
#include <math.h>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>
#include <string>
#include <time.h>
#include <omp.h>

using namespace std;

long double calc(int n)
{
  unsigned seed = 17937 + omp_get_thread_num() * chrono::system_clock::now().time_since_epoch().count();
  default_random_engine gen(seed);
  uniform_real_distribution<float> prob(0.0, 1.0);
  double x;
  double y;
  double d;
  double P = 0;
  for (int i = 0; i < n; i++)
  {
    x = (prob(gen)) * 3.1415;
    d = (prob(gen));
    y = 0.5 * sin(x);
    if (d <= y)
    {
      P++;
    }
  }
  //cout << (long double)n/P << endl;
  return (long double)n / P;
}

int main(int argc, char **argv)
{
  int n;
  double start, end, elapsed;

  n = stoi(argv[1]);
  int prs = omp_get_num_procs();
  int n1 = n / prs;
  long double tavg = (long double)0;
  omp_set_num_threads(prs);
  start = omp_get_wtime();
#pragma omp parallel
  {
    int i;
#pragma omp for
    for (i = 0; i < prs; i++)
    {
      tavg += (long double)calc(n1);
    }
  }
  tavg = (long double)tavg / prs;
  end = omp_get_wtime();
  elapsed = (double)(end - start);
  cout << (double)(end - start) << "\t" << tavg << endl;

  return 0;
}
