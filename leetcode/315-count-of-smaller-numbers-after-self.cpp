class Solution
{
 public:
  vector<int> countSmaller(vector<int>& nums)
  {
    int n = nums.size();

    vector<int> vec;
    std::unique_copy(nums.begin(), nums.end(), back_inserter(vec));
    sort(vec.begin(), vec.end());

    unordered_map<int, int> pos;
    for (int i = 0; i < vec.size(); ++i) pos[vec[i]] = i;

    vector<int> ret, bit(n+1, 0);
    for (int i = n-1; i >= 0; --i) {
      int p = pos[nums[i]];
      ret.push_back(getsum(bit, p));
      update(bit, p+1, 1);
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

  int getsum(vector<int>& bit, int i)
  {
    int s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void update(vector<int>& bit, int i, int v)
  {
    int n = bit.size();
    while (i < n) {
      bit[i] += v;
      i += i & -i;
    }
  }
};
