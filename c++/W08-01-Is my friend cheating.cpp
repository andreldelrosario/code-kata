#include <algorithm>
#include <iostream>
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

class RemovedNumbers
{
private:
    static bool sort(std::vector<long long> a, std::vector<long long> b);
public:
    static std::vector<std::vector<long long>> removNb(long long n);
};

bool RemovedNumbers::sort(std::vector<long long> a, std::vector<long long> b)
{
    return a[0] < b[0];
}

std::vector<std::vector<long long>> RemovedNumbers::removNb(long long n)
{
    // sum of all numbers from 1 to n has a ceil value of (n * (n + 1)) / 2
    const long long ceiling = (n * (n + 1)) / 2;
    std::vector<std::vector<long long>> result;

    for (long long a = n / 2; a <= n; ++a)
    {
        // highest possible b = (ceiling - a) / a
        // lowest possible  b = (ceiling - (a + 1)) / (a + 1)
        for (long long b = (ceiling - a) / a; b >= (ceiling - (a + 1)) / (a + 1); --b)
        {
            if (ceiling - (a + b) == a * b)
            {
                std::vector<long long> pair {a, b};
                std::vector<long long> pairR {b, a};
                if (result.end() == std::find(result.begin(), result.end(), pair))
                {
                    result.push_back(pair);
                    result.push_back(pairR);
                }
            }
        }
    }

    std::sort(result.begin(), result.end(), sort);
    return result;
}

int main() {
    // 26 -> {{15, 21}, {21, 15}}
    std::cout << RemovedNumbers::removNb(26) << std::endl;
    // 100 -> { }
    std::cout << RemovedNumbers::removNb(100) << std::endl;
    return 0;
}