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
    return lca(root, p, q);
  }

  TreeNode* lca(TreeNode* cur, TreeNode* p, TreeNode* q)
  {
    if (!cur || cur == p || cur == q) return cur;
    TreeNode* l = lca(cur->left, p, q);
    TreeNode* r = lca(cur->right, p, q);
    return !l ? r : !r ? l : cur;
  }
};
