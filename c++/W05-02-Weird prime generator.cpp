#include <iostream>
#include <set>
#include <vector>

template <class T>
inline std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << " ]";
    return os;
}

class WeirdPrimeGen
{
private:
    static long long gcd(long long a, long long b);
public:
    static long long countOnes(long long n);
    static long long maxPn(long long n);
    static std::vector<long double> anOver(long long n);
    static int anOverAverage(long long n);
};

long long WeirdPrimeGen::gcd(long long a, long long b)
{
    return (b == 0) ? a : WeirdPrimeGen::gcd(b, a % b);
}

long long WeirdPrimeGen::countOnes(long long n)
{
    long long a = 7;
    long long count = 1;

    for (long long i = 2; i <= n; ++i)
    {
        long long ai = a + gcd(a, i);
        long long g = ai - a;
        a = ai;

        if (g == 1)
        {
            ++count;
        }
    }

    return count;
}

long long WeirdPrimeGen::maxPn(long long n)
{
    long long max = -1;
    long long a = 7;
    long long i = 2;
    long long count = 0;
    std::set<long long> p {};

    while (count < n)
    {
        long long ai = a + gcd(a, i++);
        long long g = ai - a;

        if (g != 1 && p.end() == p.find(g))
        {
            p.insert(g);
            max = (max < g) ? g : max;
            ++count;
        }
        a = ai;
    }

    return max;
}

std::vector<long double> WeirdPrimeGen::anOver(long long n)
{
    std::vector<long double> anOver;
    // for (long long i = 0; i < n; ++i)
    //     anOver.push_back(3);
    // or

    long long max = -1;
    long long a = 7;
    long double i = 2;
    long long count = 0;

    while (count < n)
    {
        long double ai = a + gcd(a, i);
        long long g = ai - a;

        if (g != 1)
        {
            anOver.push_back(ai / i);
            ++count;
        }
        a = ai;
        ++i;
    }

    return anOver;
}

int WeirdPrimeGen::anOverAverage(long long n)
{
    // return 3;
    // or
    auto anOver = WeirdPrimeGen::anOver(n);
    long long sum = 0;
    for (const long long& i : anOver)
    {
        sum += i;
    }
    return sum / n;
}

int main()
{
    int n = 15;
    std::cout << WeirdPrimeGen::countOnes(n) << std::endl;
    std::cout << WeirdPrimeGen::maxPn(n) << std::endl;
    std::cout << WeirdPrimeGen::anOver(n) << std::endl;
    std::cout << WeirdPrimeGen::anOverAverage(n) << std::endl;

    return 0;
}