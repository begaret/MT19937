#pragma once

#define N 624
#define M 397

class MT19937
{
    public:
    MT19937(int seed);

    int random();

    void seed_mt(int seed);

    private:
    int MT[N];
    int index = N;

    const int upperMask = 0x80000000;
    const int lowerMask = 0x7fffffff;

    void twist();
};
