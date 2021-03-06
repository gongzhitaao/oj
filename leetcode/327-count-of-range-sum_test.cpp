#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "327-count-of-range-sum.cpp"

TEST_CASE("1 element", "")
{
  Solution s;
  vector<int> vec = {0};
  CHECK(s.countRangeSum(vec, 0, 0) == 1);

  vec = {1};
  CHECK(s.countRangeSum(vec, 1, 1) == 1);
}

TEST_CASE("2 elements", "")
{
  Solution s;
  vector<int> vec = {0, 0};
  CHECK(s.countRangeSum(vec, 0, 0) == 3);

  vec = {1, 5};
  CHECK(s.countRangeSum(vec, 5, 5) == 1);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec = {2147483647, -2147483648, -1, 0};
  CHECK(s.countRangeSum(vec, -1, 0) == 4);
  vec = {-2147483647,0,-2147483647,2147483647};
  CHECK(s.countRangeSum(vec, -564, 3864) == 3);
}
