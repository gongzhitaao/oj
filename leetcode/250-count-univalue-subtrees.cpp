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
  int countUnivalSubtrees(TreeNode* root)
  {
    int cnt = 0;
    postorder(root, cnt);
    return cnt;
  }

  bool postorder(TreeNode* cur, int& cnt)
  {
    if (!cur) return true;
    bool l = postorder(cur->left, cnt);
    bool r = postorder(cur->right, cnt);

    if (l && r && (!cur->left || cur->val == cur->left->val) &&
        (!cur->right || cur->val == cur->right->val)) {
      ++cnt;
      return true;
    }

    return false;
  }
};
