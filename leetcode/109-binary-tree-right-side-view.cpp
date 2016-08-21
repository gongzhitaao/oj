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
    TreeNode* sentinal = new TreeNode(0);
    int val = 0;
    q.push(root);
    q.push(sentinal);
    for (TreeNode* n; !q.empty(); ) {
      n = q.front(); q.pop();
      if (n == sentinal) {
        ret.push_back(val);
        if (q.empty()) break;
        q.push(sentinal);
      } else {
        val = n->val;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    return ret;
  }
};
