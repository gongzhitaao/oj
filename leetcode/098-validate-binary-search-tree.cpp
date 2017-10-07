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
  bool isValidBST(TreeNode* root) {
    TreeNode* par = nullptr;
    return inorder(root, par);
  }

  bool inorder(TreeNode* cur, TreeNode*& par)
  {
    if (!cur) return true;
    if (!inorder(cur->left, par) || par && par->val >= cur->val) return false;
    par = cur;
    return inorder(cur->right, par);
  }
};
