#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "673-number-of-longest-increasing-subsequence.cpp"

TEST_CASE("Random", "")
{
  Solution s;
  vector<int> vec = {1, 3, 5, 4, 7};
  CHECK(s.findNumberOfLIS(vec) == 2);

  vec = {1, 2, 3, 4};
  CHECK(s.findNumberOfLIS(vec) == 1);

  vec = {1, 1, 2, 2, 3, 3, 4};
  CHECK(s.findNumberOfLIS(vec) == 8);

  vec = {1, 2, 4, 3, 5, 4, 7, 2};
  CHECK(s.findNumberOfLIS(vec) == 3);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec = {2147483647, -2147483648, -1, 0};
  CHECK(s.findNumberOfLIS(vec) == 1);

  vec = {1, 1, 1, 1};
  CHECK(s.findNumberOfLIS(vec) == 4);

  vec = {};
  CHECK(s.findNumberOfLIS(vec) == 0);
}
