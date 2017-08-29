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
  void flatten(TreeNode* root)
  {
    for (TreeNode *cur = root, *tmp = nullptr; cur; ) {
      if (cur->left) {
        for (tmp = cur->left;
             tmp->right && tmp->right != cur;
             tmp = tmp->right) ;
        if (tmp->right) {
          tmp->right = cur->right;
          tmp = cur->right;
          cur->right = cur->left;
          cur->left = nullptr;
          cur = tmp;
        } else {
          tmp->right = cur;
          cur = cur->left;
        }
      } else {
        cur = cur->right;
      }
    }
  }
};
