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
    if (!root) return ret;

    stack<TreeNode*> s;
    for (TreeNode* cur = root; true;) {
      for (; cur; cur = cur->left) {
        if (cur->right) s.push(cur->right);
        s.push(cur);
      }

      cur = s.top();
      s.pop();

      if (cur->right && s.size() && s.top() == cur->right) {
        s.pop();
        s.push(cur);
        cur = cur->right;
      } else {
        ret.push_back(cur->val);
        cur = nullptr;
      }

      if (s.empty()) break;
    }

    return ret;
  }
};
