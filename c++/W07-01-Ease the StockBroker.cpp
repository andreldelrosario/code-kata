#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

class OrdersSummary
{
private:
    static std::vector<std::string> processStatements(const std::string &lst);
    static std::string parseStatements(std::vector<std::string> statements);
public:
    static std::string balanceStatements(const std::string &lst);
};

std::vector<std::string> OrdersSummary::processStatements(const std::string &lst)
{
    std::string input = lst + ',';
    std::vector<std::string> statements;

    for (int i = 1, start = 0, end; i < input.length(); ++i)
    {
        end = i;
        if (',' == input.at(i))
        {
            statements.push_back(input.substr(start, end-start));
            i += 2;
            start = i;
        }
    }
    
    return statements;
}

std::string OrdersSummary::parseStatements(std::vector<std::string> statements)
{
    std::string errors;

    int buy = 0;
    int sell = 0;
    int count = 0;

    for (auto i : statements)
    {
        bool mismatch = false;
        std::stringstream ss;
        std::stringstream temp;
        std::string value;
        std::string quote;
        int quantity;
        float price;
        char status;

        temp << i;
        ss << i;
        temp >> value;
        ss >> quote;
        mismatch = mismatch || !std::regex_match(value, std::regex("\\S+"));
        

        temp >> value;
        ss >> quantity;
        mismatch = mismatch || !std::regex_match(value, std::regex("\\d+"));

        temp >> value;
        ss >> price;
        mismatch = mismatch || !std::regex_match(value, std::regex("([[:digit:]]*)(\\.[[:digit:]]+)"));

        temp >> value;
        ss >> status;
        mismatch = mismatch || !std::regex_match(value, std::regex("\[sSbB]"));

        if (mismatch)
        {
            errors += (i + " ;");
            count ++;
        }
        else
        {
            if (toupper(status) == 'B')
            {
                buy += (quantity * price);
            }
            else
            {
                sell += (quantity * price);
            }
        }

    }

    return "Buy: " + std::to_string(buy) + " Sell: " + std::to_string(sell) + ((count > 0) ? "; Badly formed " + std::to_string(count) + ": " + errors : "");
}

std::string OrdersSummary::balanceStatements(const std::string &lst)
{
    std::vector<std::string> statements = processStatements(lst);

    return parseStatements(statements);
}

int main() {
    std::cout << OrdersSummary::balanceStatements("GOOG 300 542.0 B, AAPL 50 145.0 B, CSCO 250.0 29 B, GOOG 200 580.0 S") << std::endl;
    std::cout << OrdersSummary::balanceStatements("ZNGA 1300 2.66 B, CLH15.NYM 50 56.32 B, OWW 1000 11.623 B, OGG 20 580.1 B") << std::endl;
    std::cout << OrdersSummary::balanceStatements("ZNGA 1300 2.66 B, CLH16.NYM 50 56 S ;OWW 1000 11 S, OGG 20 580.1 B") << std::endl;
    return 0;
}