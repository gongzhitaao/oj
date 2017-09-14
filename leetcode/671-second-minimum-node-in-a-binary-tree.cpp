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
  int findSecondMinimumValue(TreeNode* root)
  {
    int m0 = numeric_limits<int>::max(), m1 = m0;
    for (TreeNode *cur = root, *tmp = nullptr; cur;) {
      if (cur->left) {
        for (tmp = cur->left; tmp->right && tmp->right != cur;
             tmp = tmp->right) {
        }
        if (tmp->right) {
          tmp->right = nullptr;
          if (cur->val < m0) m1 = m0, m0 = cur->val;
          else if (cur->val > m0 && cur->val < m1) m1 = cur->val;
          cur = cur->right;
        } else {
          tmp->right = cur;
          cur = cur->left;
        }
      } else {
        if (cur->val < m0) m1 = m0, m0 = cur->val;
        else if (cur->val > m0 && cur->val < m1) m1 = cur->val;
        cur = cur->right;
      }
    }
    if (numeric_limits<int>::max() == m1 || m1 == m0) return -1;
    return m1;
  }
};
