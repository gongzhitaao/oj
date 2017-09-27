#include <vector>
#include <algorithm>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "283-move-zeroes.cpp"

TEST_CASE("Random", "")
{
  Solution s;
  vector<int> vec{1, 2, 0, 3, 4}, res{1, 2, 3, 4, 0};
  s.moveZeroes(vec);
  CHECK(vec == res);
}

TEST_CASE("Corner cases", "")
{
  Solution s;
  vector<int> vec{}, res{};
  s.moveZeroes(vec);
  CHECK(vec == res);

  vec = {0, 0}, res = {0, 0};
  s.moveZeroes(vec);
  CHECK(vec == res);
}
