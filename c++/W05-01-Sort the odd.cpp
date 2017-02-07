#include <cassert>
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

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::cout << "actual   " << array << std::endl;
        std::vector<int> result{array.begin(), array.end()};
        result.erase(std::remove_if(result.begin(), result.end(), [](int t){ return t % 2 == 0; }), result.end());
        std::sort(result.begin(), result.end());
        
        for (int i = 0; array.begin() + i < array.end(); ++i)
        {
            const auto it = array.begin() + i;
            if (*it % 2 == 0)
            {
                result.emplace(result.begin() + i, *it);
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> expected = { 1, 3, 2, 8, 5, 4 };
    Kata kata;
    std::vector<int> actual = kata.sortArray({ 5, 3, 2, 8, 1, 4 });
    std::cout << "expected " << expected << std::endl; 
    return 0;
}