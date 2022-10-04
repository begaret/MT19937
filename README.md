# MT19337
A C++ implementation of the **Mersenne Twister** pseudorandom number generator based on the [pseudocode on Wikipedia](https://en.wikipedia.org/wiki/Mersenne_twister#Pseudocode).

All coefficients are as according to the MT19937-32 standard.

## Usage

The following program creates an instance of the generator seeded with the current time and then prints 100 random numbers.

```c++
#include <mt19937.h>
#include <iostream>
    
int main()
{
  MT19937 mt(time(NULL));
    
  for (int i = 0; i < 100; i++)
  {
    std::cout << mt.random() << std::endl;
  }
    
  return 0;
}
```

You can also use the seed_mt method to reset the seed.
