/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode *> s;
    for (TreeNode *n = root; n || !s.empty(); n = n->right) {
      for (; n; n = n->left) s.push(n);
      n = s.top(); s.pop();
      ret.push_back(n->val);
    }
    return ret;
  }
};
