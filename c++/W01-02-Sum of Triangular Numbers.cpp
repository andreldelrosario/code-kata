int sumTriangularNumbers(int n) 
{
  int sum = 0;
  int prev = 0;
  for(int i = 1; i <= n; ++i)
  {
      sum += (prev + i);
      prev += i;
  }
  
  return sum;
}

//n - 00 01 02 03 04 05
//t - 00 01 03 06 10 15
//d -   1  2  3  4  5
//s - 00 01 04 10 20 35