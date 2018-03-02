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
 public:
  int rob(TreeNode* root)
  {
    int ret = 0;
    bsearch(root, ret);
    return ret;
  }

  pair<int, int> bsearch(TreeNode* cur, int& ret)
  {
    if (!cur) return {0, 0};
    pair<int, int> l = bsearch(cur->left, ret);
    pair<int, int> r = bsearch(cur->right, ret);
    int w_cur = cur->val + l.second + r.second;
    int wo_cur = max(l.first, l.second) + max(r.first, r.second);
    if (w_cur > ret) ret = w_cur;
    if (wo_cur > ret) ret = wo_cur;
    return {w_cur, wo_cur};
  }
};
