#include <iostream>
#include <string>
#include <map>

std::string heavyMetalUmlauts(std::string boringText)
{
    std::string s = "";
    std::map<char, std::string> replace {
        {'A', "Ä"},
        {'E', "Ë"},
        {'I', "Ï"},
        {'O', "Ö"},
        {'U', "Ü"},
        {'Y', "Ÿ"},
        {'a', "ä"},
        {'e', "ë"},
        {'i', "ï"},
        {'o', "ö"},
        {'u', "ü"},
        {'y', "ÿ"}
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