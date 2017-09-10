#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "315-count-of-smaller-numbers-after-self.cpp"

TEST_CASE("1 element", "")
{
  Solution s;
  vector<int> vec = {0}, tar = {0};
  CHECK(s.countSmaller(vec) == tar);

  vec = {1};
  CHECK(s.countSmaller(vec) == tar);
}

TEST_CASE("2 elements", "")
{
  Solution s;
  vector<int> vec = {0, 0}, tar = {0, 0};
  CHECK(s.countSmaller(vec) == tar);

  vec = {1, 0}, tar = {1, 0};
  CHECK(s.countSmaller(vec) == tar);
}

TEST_CASE("Random", "")
{
  Solution s;
  vector<int> vec = {1,3,2,3,1}, tar = {0, 2, 1, 1, 0};
  CHECK(s.countSmaller(vec) == tar);

  vec = {5, 2, 6, 1}, tar = {2, 1, 1, 0};
  CHECK(s.countSmaller(vec) == tar);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec = {2147483647, -2147483648, -1, 0}, tar = {3, 0, 0, 0};
  CHECK(s.countSmaller(vec) == tar);

  vec = {-2147483647, 0, -2147483647, 2147483647}, tar = {0, 1, 0, 0};
  CHECK(s.countSmaller(vec) == tar);

  vec = {}, tar = {};
  CHECK(s.countSmaller(vec) == tar);
}
