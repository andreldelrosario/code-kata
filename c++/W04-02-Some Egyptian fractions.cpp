#include <iostream>
#include <string>
#include <sstream>

class Decomp
{
private:
  static std::string fibonacci(long x, long y);
public:
  static std::string decompose(const std::string &nrStr, const std::string &drStr);
};

std::string Decomp::fibonacci(long x, long y)
{
  std::ostringstream buffer;
  
  if (x == 0 || y == 0)
  { }
  else if (x % y == 0)
  {
    buffer << x / y;
  }
  else if (y % x == 0)
  {
    buffer << "1/" << y / x;
  }
  else if (x > y)
  {
    long n = x / y;
    buffer << n << ", " << Decomp::fibonacci(x % y, y);
  }
  else 
  {
    long n = y / x + 1;
    buffer << "1/" << n << ", " << Decomp::fibonacci(x * n - y, y * n);
  }
  return buffer.str();
}

std::string Decomp::decompose(const std::string &nrStr, const std::string &drStr)
{
  std::string::size_type sz;
  return "[" + Decomp::fibonacci(std::stoi(nrStr, &sz), std::stoi(drStr, &sz)) + "]";
}

int main()
{
  std::cout << Decomp::decompose("12", "4") << std::endl;
  std::cout << Decomp::decompose("4", "12") << std::endl;
  std::cout << Decomp::decompose("8", "11") << std::endl;
  std::cout << Decomp::decompose("0", "1") << std::endl;
  std::cout << Decomp::decompose("66", "100") << std::endl;
  return 0;
}