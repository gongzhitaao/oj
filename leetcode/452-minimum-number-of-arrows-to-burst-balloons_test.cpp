#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "452-minimum-number-of-arrows-to-burst-balloons.cpp"

TEST_CASE("Random", "")
{
  Solution s;
  vector<pair<int, int>> vec = {{10,16}, {2,8}, {1,6}, {7,12}};
  CHECK(s.findMinArrowShots(vec) == 2);

  vec = {{1, 2}, {3, 4}};
  CHECK(s.findMinArrowShots(vec) == 2);

  vec = {{1, 4}, {4, 5}};
  CHECK(s.findMinArrowShots(vec) == 1);

  vec = {{1, 5}, {3, 5}, {6, 7}};
  CHECK(s.findMinArrowShots(vec) == 2);
}
