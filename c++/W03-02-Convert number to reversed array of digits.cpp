std::vector<int> digitize(unsigned long long n)
{        
    std::vector<int> result;
    while (n > 0)
    {
        result.push_back(n % 10);
        n /= 10;
    }
    return result;
}