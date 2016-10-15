class Solution
{
 public:
  int findMaximumXOR(vector<int>& nums)
  {
    int ans = 0;

    // If you move the following inside the loop, the memory for
    // previous iteration will not freed, and you will get a MLE.
    unordered_set<int> prefix;

    for (int i = 30; i >= 0; --i) {
      prefix.clear();

      for (int n : nums)
        prefix.insert(n>>i);

      ans <<= 1;
      for (int p : prefix)
        if (prefix.find(ans^1^p) != prefix.end()) {
          ans ^= 1;
          break;
        }
    }
    return ans;
  }
};
