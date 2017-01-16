#include <cmath>

class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
        int length = array.size();
        if (runs < 1 || length <= 1)
        {
            return array;
        }
    
        int median = ceil(length / 2.0);
        std::vector<int> folded(array.begin(), array.begin() + median);
    
        int end = (length % 2 != 0) ? median - 1 : median;
        for(int i = 0; i < end; ++i)
        {
            folded[i] += array[length - (i + 1)];
        }

        return Kata::foldArray(folded, --runs);
    }
};
// Rank up exercise
// Fold an array