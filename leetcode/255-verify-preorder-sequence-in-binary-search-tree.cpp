class Solution
{
 public:
  bool verifyPreorder(vector<int>& preorder)
  {
    int minval = numeric_limits<int>::min();
    stack<int> left;
    for (int cur : preorder) {
      if (cur < minval)
        return false;
      for (; !left.empty() && left.top() < cur; left.pop())
        minval = left.top();
      left.push(cur);
    }
    return true;
  }
};
