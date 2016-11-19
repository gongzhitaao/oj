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
  int closestValue(TreeNode* root, double target)
  {
    for (TreeNode* n = root; ;) {
      if (n->val > target) {
        if (!n->left) return n->val;
        TreeNode* m = rightmost(n->left);
        if (m->val > target)
          n = n->left;
        else return target-m->val < n->val-target ? m->val : n->val;
      } else {
        if (!n->right) return n->val;
        TreeNode* m = leftmost(n->right);
        if (m->val < target)
          n = n->right;
        else return m->val-target < target-n->val ? m->val : n->val;
      }
    }
    return 0;
  }

  TreeNode* rightmost(TreeNode* node)
  {
    if (!node->right)
      return node;
    return rightmost(node->right);
  }

  TreeNode* leftmost(TreeNode* node)
  {
    if (!node->left)
      return node;
    return leftmost(node->left);
  }
};
