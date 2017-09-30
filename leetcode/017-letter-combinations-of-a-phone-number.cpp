class Solution
{
 public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> num2ch{"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;

    if (digits.empty()) return ret;

    for (char ch : digits)
      if ('0' == ch || '1' == ch)
        return ret;

    dfs(digits, 0, num2ch, ret, "");
    return ret;
  }

  void dfs(const string& digits, int i0, const vector<string>& num2ch,
           vector<string>& ret, string path)
  {
    if (i0 == digits.size()) return ret.push_back(path);
    const string& choices = num2ch[digits[i0] - '0'];
    for (char ch : choices) dfs(digits, i0 + 1, num2ch, ret, path + ch);
  }
};
