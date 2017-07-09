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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    TreeNode* ret = nullptr;
    dfs(root, p, q, ret);
    return ret;
  }

  int dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& ret)
  {
    if (!node) return 0;

    int found = (node == p) | ((node == q) << 1) | dfs(node->left, p, q, ret);
    if (3 == found && !ret) ret = node;

    if (ret) return found;

    found |= dfs(node->right, p, q, ret);
    if (3 == found && !ret) ret = node;

    return found;
  }
};
