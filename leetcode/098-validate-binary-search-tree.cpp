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

 private:
  bool inorder(TreeNode* node, TreeNode*& pre)
  {
    if (!node) return true;
    if (!inorder(node->left, pre))
      return false;
    if (pre && pre->val >= node->val)
      return false;
    pre = node;
    return inorder(node->right, pre);
  }
};
