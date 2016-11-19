class Solution
{
 public:
  bool isValid(string s)
  {
    vector<int> tmp(128, 0);
    tmp[')'] = '(';
    tmp[']'] = '[';
    tmp['}'] = '{';

    string stk;
    for (char ch : s) {
      if (')' == ch || ']' == ch || '}' == ch) {
        if (stk.empty() || stk.back() != tmp[ch])
          return false;
        stk.pop_back();
      } else stk.push_back(ch);
    }
    return stk.empty();
  }
};
