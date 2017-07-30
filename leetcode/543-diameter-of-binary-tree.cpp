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
  int diameterOfBinaryTree(TreeNode* root)
  {
    int d = 1;
    dfs(root, d);
    return d-1;
  }

  int dfs(TreeNode* node, int& d)
  {
    if (!node) return 0;
    int l = dfs(node->left, d);
    int r = dfs(node->right, d);
    if (l + r + 1 > d)
      d = l + r + 1;
    return max(l, r) + 1;
  }
};
