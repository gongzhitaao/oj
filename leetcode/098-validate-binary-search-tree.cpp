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
  bool isValidBST(TreeNode* root)
  {
    TreeNode* pre = nullptr;
    return inorder(root, pre);
  }

  bool inorder(TreeNode* cur, TreeNode*& pre)
  {
    if (!cur) return true;
    if (!inorder(cur->left, pre) || pre && pre->val >= cur->val) return false;
    pre = cur;
    return inorder(cur->right, pre);
  }
};
