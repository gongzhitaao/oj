/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {

    if (!root) return vector<vector<int> >();

    vector<vector<int> > results;

    queue<TreeNode *> q;
    q.push(root);

    bool start = true;
    vector<int> tmp;
    while (q.size() > 0) {
      TreeNode *node = q.front(); q.pop();
      if (!node) {
        start = true;
      } else {
        if (start) {
          results.push_back(tmp);
          tmp.clear();
          q.push(NULL);
          start = false;
        }
        tmp.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    if (start) results.push_back(tmp);

    reverse(results.begin(), results.end());
    results.pop_back();

    return results;
  }
};
