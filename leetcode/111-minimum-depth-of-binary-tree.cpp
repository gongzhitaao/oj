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
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode *> q;
    q.push(root);
    int d = 1;
    for (int cnt = 1; !q.empty(); ++d) {
      int t = 0;
      for (int i = 0; i < cnt; ++i) {
        TreeNode *tn = q.front();
        q.pop();

        if (!tn->left && !tn->right) return d;

        if (tn->left) q.push(tn->left), ++t;
        if (tn->right) q.push(tn->right), ++t;
      }
      cnt = t;
    }
  }
};
