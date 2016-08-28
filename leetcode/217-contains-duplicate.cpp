class Solution
{
 public:
  bool containsDuplicate(vector<int>& nums)
  {
    unordered_set<int> vec;
    for (int n : nums) {
      if (vec.find(n) != vec.end()) return true;
      vec.insert(n);
    }
    return false;
  }
};
