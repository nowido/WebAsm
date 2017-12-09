#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

int myfunc(int a)
{
    int fe = EM_ASM_INT({
        return myjscode($0);
    }, a);

    return fe + 3;
}

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

#ifdef __cplusplus
}
#endif
