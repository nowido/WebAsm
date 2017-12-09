#include <stdio.h>
#include <stdlib.h>
#include <time.h>

inline double random01(void)
{
    return (double) rand() / (double) RAND_MAX;
}

double mcpi(int n, unsigned int seed)
{
    srand(seed);

    int count = 0;

    for(int i = 0; i < n; ++i)
    {
        double x = random01();
        double y = random01();

        if(x * x + y * y <= 1.0)
        {
            ++count;
        }
    }

    return 4.0 * (double) count / (double) n;
}

int main(int argc, char** argv)
{
    printf("Hello, World!\n");
    clock_t t1 = clock();
    double pi = mcpi(100000000, 123);
    clock_t t2 = clock();
    printf("%f %ld\n", pi, t2 - t1);    
    return 0;
}