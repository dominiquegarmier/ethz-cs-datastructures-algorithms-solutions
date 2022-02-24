#include <vector>
using Matrix = std::vector<std::vector<int>>;


class PrefixSum
{
private:
  Matrix a;
  Matrix cache_block;
  Matrix cache_slice;
  
  
public:
  
  PrefixSum(const Matrix& a) : a (a)
  {
    unsigned size_x = a.at(0).size();
    unsigned size_y = a.size();
    cache_block =  Matrix(size_y, std::vector<int>(size_x, 0));
    cache_slice =  Matrix(size_y, std::vector<int>(size_x, 0));
  }


  // pre: 0 <= x0 <= x1 < X and 0 <= y0 <= y1 < Y
  // post: return the sum of all pixels in a[y0..y1,x0..x1]
  int sum(unsigned x0, unsigned y0, unsigned x1, unsigned y1)
  {
    int ret = 0;
    
    if (y1 > y0) {
      ret += cache_block.at(y1 - 1).at(x1);
    }
    
    int slice = a[y1][x1];
    if (x1 > x0) {
      slice += cache_slice.at(y1).at(x1 - 1);
    }
    
    cache_slice.at(y1).at(x1) = slice;
    
    ret += slice;
    cache_block.at(y1).at(x1) = ret;
    return ret;
  }
};
