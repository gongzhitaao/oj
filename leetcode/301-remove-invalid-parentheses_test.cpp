#include <vector>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "301-remove-invalid-parentheses.cpp"

TEST_CASE("Valid", "")
{
  Solution s;
  string str = "((()))";
  vector<string> res{"((()))"};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "()";
  res = {"()"};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "";
  res = {""};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "()()()";
  res = {"()()()"};
  CHECK(res == s.removeInvalidParentheses(str));
}

TEST_CASE("1 Step", "")
{
  Solution s;
  string str = "(";
  vector<string> res{""};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "())";
  res = {"()"};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "(()";
  res = {"()"};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "()()(";
  res = {"()()"};
  CHECK(res == s.removeInvalidParentheses(str));

  str = "()())";
  res = {"(())", "()()"};
  CHECK(res == s.removeInvalidParentheses(str));
}

TEST_CASE("Random", "")
{
  Solution s;
  string str = "((()((s((((()";
  vector<string> res{"()s()", "()(s)", "(()s)"};
  CHECK(res == s.removeInvalidParentheses(str));
}
