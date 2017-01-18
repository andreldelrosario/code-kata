#include <iostream>
#include <cmath>
#include <cstdlib>

int findDigit(int num, int nth)
{
    std::div_t dv;
    dv.quot = std::abs(num);

    if (nth <= 0)
    {
        return -1;
    }

    for (int i = 1; i <= nth; ++i)
    {
        dv = std::div(dv.quot, 10);
    }
    
    return dv.rem;
}

// Test Cases
// findDigit(6429, 3)       --> 4
// findDigit(1064, 1)       --> 4
// findDigit(10030, 5)      --> 1
// findDigit(40915, 9)      --> 0
// findDigit(0, 1)          --> 0
// indDigit(-1234, 2)       --> 3
// indDigit(-5540, 1)       --> 0
// indDigit(678998, 0)      --> -1
// indDigit(-67854, -57)    --> -1
// indDigit(0, -3)          --> -1
