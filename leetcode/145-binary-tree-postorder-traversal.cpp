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
  vector<int> postorderTraversal(TreeNode* root)
  {
    vector<int> ret;
    for (TreeNode *cur = root, *tmp = nullptr; cur;) {
      if (cur->right) {
        for (tmp = cur->right; tmp->left && tmp->left != cur; tmp = tmp->left)
          ;
        if (tmp->left) {
          tmp->left = nullptr;
          cur = cur->left;
        } else {
          tmp->left = cur;
          ret.push_back(cur->val);
          cur = cur->right;
        }
      } else {
        ret.push_back(cur->val);
        cur = cur->left;
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
