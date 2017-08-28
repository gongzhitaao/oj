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
  int sumOfLeftLeaves(TreeNode* root)
  {
    int sum = 0;
    for (TreeNode *cur = root, *tmp = nullptr; cur; ) {
      if (cur->left) {
        for (tmp = cur->left;
             tmp->right && tmp->right != cur;
             tmp = tmp->right);
        if (tmp->right) {
          tmp->right = nullptr;
          cur = cur->right;
        } else {
          tmp->right = cur;
          tmp = cur;
          cur = cur->left;
          if (cur && !cur->left && cur->right == tmp)
            sum += cur->val;
        }
      } else {
        cur = cur->right;
      }
    }
    return sum;
  }
};
