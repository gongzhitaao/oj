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
  int sumNumbers(TreeNode* root)
  {
    if (!root) return 0;
    int sum = 0;
    return dfs(root, 0, sum);
  }

  int dfs(TreeNode* cur, int val, int& sum)
  {
    val = val * 10 + cur->val;
    if (!cur->left && !cur->right)
      return sum += val;
    if (cur->left) dfs(cur->left, val, sum);
    if (cur->right) dfs(cur->right, val, sum);
    return sum;
  }
};
