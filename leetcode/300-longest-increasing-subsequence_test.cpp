#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "300-longest-increasing-subsequence.cpp"

TEST_CASE("Random", "")
{
  Solution s;
  vector<int> vec = {1, 3, 5, 4, 7};
  CHECK(s.lengthOfLIS(vec) == 4);

  vec = {1, 2, 3, 4};
  CHECK(s.lengthOfLIS(vec) == 4);

  vec = {1, 1, 2, 2, 3, 3, 4};
  CHECK(s.lengthOfLIS(vec) == 4);

  vec = {1, 2, 4, 3, 5, 4, 7, 2};
  CHECK(s.lengthOfLIS(vec) == 5);

  vec = {10, 9, 2, 5, 3, 7, 101, 18};
  CHECK(s.lengthOfLIS(vec) == 4);

  vec = {4, 10, 4, 3, 8, 9};
  CHECK(s.lengthOfLIS(vec) == 3);

  vec = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  CHECK(s.lengthOfLIS(vec) == 6);

  vec = {10, 9, 2, 5, 3, 4};
  CHECK(s.lengthOfLIS(vec) == 3);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec = {2147483647, -2147483648, -1, 0};
  CHECK(s.lengthOfLIS(vec) == 3);

  vec = {1, 1, 1, 1};
  CHECK(s.lengthOfLIS(vec) == 1);

  vec = {};
  CHECK(s.lengthOfLIS(vec) == 0);
}
