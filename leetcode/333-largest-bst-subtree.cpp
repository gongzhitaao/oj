/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  int MIN, MAX;

 public:
  int largestBSTSubtree(TreeNode* root)
  {
    if (!root) return 0;
    MIN = numeric_limits<int>::min();
    MAX = numeric_limits<int>::max();
    int n = 0;
    valid(root, n);
    return n;
  }

  tuple<int, float, float> valid(TreeNode* cur, int& n)
  {
    tuple<int, float, float> l{0, cur->val - 0.5, cur->val - 0.5},
      r{0, cur->val + 0.5, cur->val + 0.5};
    if (cur->left) l = valid(cur->left, n);
    if (cur->right) r = valid(cur->right, n);
    if (get<0>(l) >= 0 && get<0>(r) >= 0 && get<2>(l) < cur->val &&
        cur->val < get<1>(r)) {
      int cnt = 1 + get<0>(l) + get<0>(r);
      if (cnt > n) n = cnt;
      return {cnt, get<1>(l), get<2>(r)};
    }
    if (get<0>(l) > n) n = get<0>(l);
    if (get<0>(r) > n) n = get<0>(r);
    return {-1, min(get<1>(l), get<1>(r)), max(get<2>(l), get<2>(r))};
  }
};
