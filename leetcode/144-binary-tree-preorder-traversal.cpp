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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;

    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *n = s.top(); s.pop();
      ret.push_back(n->val);
      if (n->right) s.push(n->right);
      if (n->left) s.push(n->left);
    }

    return ret;
  }
};
