#include <iostream>
#include <algorithm>
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
    static std::vector<long long> an(long long n);
    static std::vector<long long> gn(long long n);
    static std::vector<long long> p(long long n);
public:
    static long long countOnes(long long n);
    static long long maxPn(long long n);
    static int anOverAverage(long long n);
};

long long WeirdPrimeGen::gcd(long long a, long long b)
{
    return (b == 0) ? a : WeirdPrimeGen::gcd(b, a % b);
}

std::vector<long long> WeirdPrimeGen::an(long long n)
{
    std::vector<long long> an {7};
    for (int i = 2; i <= n; ++i)
    {
        an.push_back(an[i-2] + WeirdPrimeGen::gcd(an[i-2], i));
    }
    return an;
}

std::vector<long long> WeirdPrimeGen::gn(long long n)
{
    std::vector<long long> an = WeirdPrimeGen::an(n);
    std::vector<long long> gn {1};
    for (int i = 1; i < n; ++i)
    {
        gn.push_back(an[i] - an[i-1]);
    }
    return gn;
}

std::vector<long long> WeirdPrimeGen::p(long long n)
{
    std::vector<long long> p {};
    long long i = 1;
    auto gn = WeirdPrimeGen::gn(1000000);

    while (p.size() != n)
    {
        auto end = std::remove_if(gn.begin(), gn.end(), [&](long long num){return num == i;});
        gn.erase(end);
        i = *gn.begin();
        p.push_back(i);
    }

    return p;
}

long long WeirdPrimeGen::countOnes(long long n)
{
    auto g = WeirdPrimeGen::gn(n);
    return std::count_if(g.begin(), g.end(), [](int i){return i == 1;});
}


long long WeirdPrimeGen::maxPn(long long n)
{
      std::vector<long long> p = WeirdPrimeGen::p(n);
    return *std::max_element(p.begin(), p.end());
}

int WeirdPrimeGen::anOverAverage(long long n)
{
    return 3;
}

int main() {
    // your code goes here
    std::cout << WeirdPrimeGen::a(2) << std::endl;
    std::cout << WeirdPrimeGen::gcd(7, 2) << std::endl;
    std::cout << WeirdPrimeGen::an(10) << std::endl;
    std::cout << WeirdPrimeGen::gn(10) << std::endl;
    std::cout << WeirdPrimeGen::countOnes(10) << std::endl;
    std::cout << WeirdPrimeGen::p(10) << std::endl;


    return 0;
}