class Solution
{
 public:
  string largestNumber(vector<int>& nums)
  {
    const int n = nums.size();
    vector<string> str(n, "");
    vector<int> ind(n, 0);

    for (int i = 0; i < n; ++i) {
      string s = to_string(nums[i]);
      string tmp;
      for (tmp = s; tmp.size() < 9; tmp += s)
        ;
      str[i] = tmp.substr(0, 9);
      ind[i] = i;
    }

    auto cmp = [&str](int a, int b) { return str[a] > str[b]; };
    sort(ind.begin(), ind.end(), cmp);

    string ret;
    for (int i : ind) ret += to_string(nums[i]);
    int i = 0;
    for (; i < ret.size() - 1 && '0' == ret[i]; ++i)
      ;

    return ret.substr(i);
  }
};
