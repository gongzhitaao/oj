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
  int maxPathSum(TreeNode* root)
  {
    maxval_ = numeric_limits<int>::min();
    dfs(root, 0);
    return maxval_;
  }

 private:
  int dfs(TreeNode* node, int cur)
  {
    if (!node) return 0;

    int pmax = cur;
    if (pmax < 0) pmax = 0;

    int lmax = dfs(node->left, cur);
    if (lmax < 0) lmax = 0;

    int rmax = dfs(node->right, cur);
    if (rmax < 0) rmax = 0;

    int tmp = pmax + lmax;
    if (pmax + rmax > tmp) tmp = pmax + rmax;
    if (lmax + rmax > tmp) tmp = lmax + rmax;
    tmp += node->val;
    if (tmp > maxval_) maxval_ = tmp;

    if (lmax > rmax)
      return lmax + node->val;
    return rmax + node->val;
  }
  int maxval_;
};
