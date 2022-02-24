#include <iostream>
#include <vector>
#include <random>
#include <cassert>

#include "PrefixSum.h"

using Matrix = std::vector<std::vector<int>>;

Matrix getData(){
    unsigned int Y = 0;
    unsigned int X = 0; 
    std::cout << "enter dimensions X Y ";
    std::cin >> X;
    std::cin >> Y;
    Matrix result(Y, std::vector<int>(X));
    
    std::mt19937 gen(X*Y); //Standard mersenne_twister_engine seeded with X*Y
    std::uniform_int_distribution<> dis(-10, 10);
 
    for (size_t y = 0; y<Y; ++y)
      for (size_t x = 0; x<X; ++x)
        result[y][x] = dis(gen);

    return result;
}

// pre: rectangular matrix m
//      0 <= x0 <= x1 < width m[0].size() of m
//      0 <= y0 <= y1 < height m.size() of m
// post: return sum of values of m[y][x] for all x in [x0,x1] and y in [y0,y1]
//       (x1,y1 are included)
int naiveSum(const Matrix& m, unsigned x0, unsigned y0, unsigned x1, unsigned y1){
  int sum = 0; 
  for (unsigned y = y0; y != y1+1; ++y)
    for (unsigned x = x0; x != x1+1; ++x)
      sum += m[y][x];
  return sum;
}


int main()
{
  
  Matrix m = getData();
  unsigned Y = m.size();
  unsigned X = m[0].size();

  int max = m[0][0]; 
  unsigned X0, Y0, X1, Y1; // max positions

  PrefixSum prefixSum (m);
  
  // naive algorithm:
  // traverse all possible pairs of points (x0,y0), (x1,y1) to find 
  // the rectangle with maximal sum 
  for (unsigned x0 = 0; x0 != X; ++x0){
    for (unsigned y0 = 0; y0 != Y; ++y0){
      for (unsigned x1 = x0; x1 != X; ++x1){
        for (unsigned y1 = y0; y1 != Y; ++y1){
          int result = prefixSum.sum(x0,y0,x1,y1);
          if (Y<20 && X<20) 
            assert(result == naiveSum(m,x0,y0,x1,y1));
          if (result > max){
            max = result;
            X0 = x0; Y0 = y0; X1 = x1; Y1 = y1;
          }
        }
      }
    }
  }

  std::cout << "max = " << max << " (" << X0 << "," << Y0 << ") -- (" << X1 << "," << Y1 << ")" <<  std::endl;

 return 0;
}