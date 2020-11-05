#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long Dartboard(long numDarts)
{
	long dart, numInCircle = 0;
	double x, y;
	unsigned int seed = (unsigned)time(NULL);
	srand(seed);
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
	long numDarts = atoi(argv[1]);
	long numInCircle;
	double pi;
	clock_t start, finish;
	double pi_base = 3.141592653589793238462643;

	start = clock();
	numInCircle = Dartboard(numDarts);
	finish = clock();

	pi = (4 * numInCircle) / ((double)numDarts);
	printf("%li\t%f\t%.16f\t%.16f\t", numDarts, (double)(finish - start) / CLOCKS_PER_SEC, pi, fabs(pi - pi_base));

	return 0;
}
