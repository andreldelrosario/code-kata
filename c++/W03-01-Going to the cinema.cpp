#include <cmath>

class Movie
{
public:
    static int movie(int card, int ticket, double perc);
};

int Movie::movie(int card, int ticket, double perc)
{
    float systemB;
    float systemA;
    
    int count = 0;
    do
    {
        ++count;
        systemA = ticket * count;
        systemB = card;
        for (int n = 1; n <= count; ++n)
        {
            systemB += (ticket * std::pow(perc, n));
        }
    } while (std::ceil(systemB) >= systemA);
    return count;
}