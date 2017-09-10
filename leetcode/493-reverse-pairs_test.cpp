#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "493-reverse-pairs.cpp"

TEST_CASE("1 element", "")
{
  Solution s;
  vector<int> vec = {0};
  CHECK(s.reversePairs(vec) == 0);

  vec = {1};
  CHECK(s.reversePairs(vec) == 0);
}

TEST_CASE("2 elements", "")
{
  Solution s;
  vector<int> vec = {0, 0};
  CHECK(s.reversePairs(vec) == 0);

  vec = {1, 0};
  CHECK(s.reversePairs(vec) == 1);
}

TEST_CASE("Random", "")
{
  Solution s;
  vector<int> vec = {1,3,2,3,1};
  CHECK(s.reversePairs(vec) == 2);

  vec = {2,4,3,5,1};
  CHECK(s.reversePairs(vec) == 3);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec = {2147483647, -2147483648, -1, 0};
  CHECK(s.reversePairs(vec) == 3);

  vec = {-2147483647, 0, -2147483647, 2147483647};
  CHECK(s.reversePairs(vec) == 2);

  vec = {};
  CHECK(s.reversePairs(vec) == 0);
}
