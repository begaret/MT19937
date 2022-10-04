#include "mt19937.h"

void MT19937::seed_mt(int seed)
{
    index = N;
    MT[0] = seed;

    for (int i = 1; i < N; i++)
    {
        MT[i] = (1812433253 * (MT[i-1] ^ (MT[i-1] >> 30)) + i) & 0xffffffff;
    }
}

MT19937::MT19937(int seed)
{
    seed_mt(seed);
}

// generates random 32-bit integer from 0 to 0x80000000
int MT19937::random()
{
    if (index >= N)
    {
        if (index > N)
        {
            seed_mt(5489);
        }
        twist();
    }

    int y = MT[index];
    y ^= ((y >> 11) & 0xffffffff);
    y ^= ((y >> 7) & 0x9d2c5680);
    y ^= ((y >> 15) & 0xefc60000);
    y ^= ((y >> 18));

    index++;
    return y;
}

// Generate the next n values from the series x_i
void MT19937::twist()
{
    for (int i = 0; i < N; i++)
    {
        int x = (MT[i] & upperMask) | (MT[(i+1) % N] & lowerMask);
        int xA = x >> 1;
        if (x % 2 != 0)
        {
            xA = xA ^ 0x9908b0df;
        }
        MT[i] = MT[(i + M) % N] ^ xA;
    }

    index = 0;
}
