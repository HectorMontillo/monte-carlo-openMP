#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

long Dartboard(long numDarts, int my_thread_id)
{
  long dart, numInCircle = 0;
  double x, y;
  unsigned int seed = (unsigned)time(NULL);
  srand(seed + my_thread_id);
  for (dart = 0; dart < numDarts; dart++)
  {
    x = rand_r(&seed) / (double)RAND_MAX;
    y = rand_r(&seed) / (double)RAND_MAX;
    if ((x * x + y * y) <= 1.0)
      numInCircle++;
  }
  return numInCircle;
}

int main(int argc, char **argv)
{
  int my_thread_id;
  int numThreads = 4;
  long totalNumDarts = atoi(argv[1]);
  long numThreadDarts;
  long numberInCircle = 0;
  double pi;
  double start, finish, elapsed;
  double pi_base = 3.141592653589793238462643;

  omp_set_num_threads(numThreads);
  numThreadDarts = totalNumDarts / numThreads;

  start = omp_get_wtime();

#pragma omp parallel reduction(+ \
                               : numberInCircle)
  {
    my_thread_id = omp_get_thread_num();
    numberInCircle = Dartboard(numThreadDarts, my_thread_id);
  }

  finish = omp_get_wtime();
  elapsed = (double)(finish - start);

  pi = (4 * numberInCircle) / ((double)totalNumDarts);
  printf("%f\t%.16f\t%.16f\n", elapsed, pi, fabs(pi - pi_base));

  return 0;
}
