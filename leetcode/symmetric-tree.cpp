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
  bool isSymmetric(TreeNode* root) {
    return bfs(root);
  }

  bool bfs(TreeNode *node) {
    deque<TreeNode *> q;
    int cnt = 1;
    q.push_back(node);

    while (!q.empty()) {
      for (int i = 0, j = cnt - 1; i < j; ++i, --j) {
        if ((!q[i] != !q[j]) ||
            (q[i] && q[j] && q[i]->val != q[j]->val))
          return false;
      }

      int t = 0;
      for (int i = 0; i < cnt; ++i) {
        TreeNode *n = q.front();
        if (n) {
          q.push_back(n->left);
          q.push_back(n->right);
          t += 2;
        }
        q.pop_front();
      }

      cnt = t;
    }

    return true;
  }
};
