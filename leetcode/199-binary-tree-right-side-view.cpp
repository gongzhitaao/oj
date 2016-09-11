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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;

    queue<TreeNode*> q;
    for (q.push(root); !q.empty(); ) {
      int n = q.size();
      int val;
      for (int i = 0; i < n; ++i) {
        TreeNode* nd = q.front(); q.pop();
        val = nd->val;
        if (nd->left) q.push(nd->left);
        if (nd->right) q.push(nd->right);
      }
      ret.push_back(val);
    }
    return ret;
  }
};
