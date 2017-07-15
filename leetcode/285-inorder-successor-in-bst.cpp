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
    TreeNode* pre = nullptr;
    return inorder(root, p, pre);
  }

 private:
  TreeNode* inorder(TreeNode* node, TreeNode* target, TreeNode*& pre)
  {
    if (!node) return nullptr;
    TreeNode* ret = inorder(node->left, target, pre);
    if (ret) return ret;
    if (pre == target) return node;
    pre = node;
    return inorder(node->right, target, pre);
  }
};
