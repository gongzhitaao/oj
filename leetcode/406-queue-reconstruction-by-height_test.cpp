#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "406-queue-reconstruction-by-height.cpp"

TEST_CASE("1 element", "")
{
  Solution s;
  vector<pair<int, int>> vec = {{7, 0}}, res = {{7, 0}};
  CHECK(s.reconstructQueue(vec) == res);
}

TEST_CASE("2 elements", "")
{
  Solution s;
  vector<pair<int, int>> vec = {{6, 1}, {7, 0}}, res = {{7, 0}, {6, 1}};
  CHECK(s.reconstructQueue(vec) == res);
}

TEST_CASE("Random", "")
{
  Solution s;
  vector<pair<int, int>> vec = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}},
                         res = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
  CHECK(s.reconstructQueue(vec) == res);
}
