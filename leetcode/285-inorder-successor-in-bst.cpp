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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
  {
    TreeNode* tmp;
    if (root)
      return inorder(root, tmp, p);
    return nullptr;
  }

  TreeNode* inorder(TreeNode* cur, TreeNode*& par, TreeNode* p)
  {
    TreeNode* ret = nullptr;

    if (cur->left) ret = inorder(cur->left, par, p);
    if (ret) return ret;

    if (par == p) return cur;
    par = cur;

    if (cur->right) ret = inorder(cur->right, par, p);

    return ret;
  }
};
