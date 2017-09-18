#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "646-maximum-length-of-pair-chain.cpp"

TEST_CASE("Random", "")
{
  Solution s;
  vector<vector<int>> vec = {{1,2}, {2,3}, {3,4}};
  CHECK(s.findLongestChain(vec) == 2);

  vec = {{3, 4}, {2, 3}, {1, 2}};
  CHECK(s.findLongestChain(vec) == 2);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<vector<int>> vec = {{1, 2}};
  CHECK(s.findLongestChain(vec) == 1);

  vec = {};
  CHECK(s.findLongestChain(vec) == 0);
}
