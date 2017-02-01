#include <iostream>
#include <string>
#include <map>

std::string heavyMetalUmlauts(std::string boringText)
{
    std::string s = "";
    std::map<char, std::string> replace {
        {'A', "�"},
        {'E', "�"},
        {'I', "�"},
        {'O', "�"},
        {'U', "�"},
        {'Y', "�"},
        {'a', "�"},
        {'e', "�"},
        {'i', "�"},
        {'o', "�"},
        {'u', "�"},
        {'y', "�"}
    };

    for (int i = 0; i < boringText.length(); ++i)
    {
        char c = boringText[i];
        if (replace.find(c) != replace.end())
        { 
            s += replace[c];
        }
        else
        {
            s += c;
        }
    }

    return s;
}

int main() {
    std::cout << heavyMetalUmlauts("Announcing the Macbook Air Guitar") << std::endl;
    return 0;
}