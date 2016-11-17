class Solution
{
 public:
  vector<int> countSmaller(vector<int>& nums)
  {
    vector<int> vec;
    std::unique_copy(nums.begin(), nums.end(), back_inserter(vec));
    sort(vec.begin(), vec.end());

    unordered_map<int, int> pos;
    for (int i = 0; i < vec.size(); ++i) pos[vec[i]] = i;

    int n = nums.size();
    vector<int> ret, bit(n+1, 0);
    for (int i = n-1; i >= 0; --i) {
      int p = pos[nums[i]];
      update(bit, p+1, 1);
      ret.push_back(getsum(bit, p));
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

  int getsum(vector<int>& bit, int i)
  {
    int s = 0;
    for (; i > 0; i -= i & -i)
      s += bit[i];
    return s;
  }

  void update(vector<int>& bit, int i, int v)
  {
    int n = bit.size();
    for (; i < n; i += i & -i)
      bit[i] += v;
  }
};
