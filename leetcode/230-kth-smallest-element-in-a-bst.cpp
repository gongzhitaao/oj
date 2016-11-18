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
  int kthSmallest(TreeNode* root, int k)
  {
    return inorder(root, k);
  }

  int inorder(TreeNode* node, int& k)
  {
    int x = 0;
    if (node->left) x = inorder(node->left, k);
    if (!k) return x;
    if (!--k) return node->val;
    if (node->right) return inorder(node->right, k);
    return 0;
  }
};
