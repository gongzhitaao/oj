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
  vector<vector<int>> levelOrder(TreeNode* root)
  {
    vector<vector<int>> ret;
    if (!root) return ret;

    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    for (vector<int> tmp; q.size(); ) {
      TreeNode* cur = q.front(); q.pop();

      if (!cur) {
        ret.push_back(tmp);
        tmp = vector<int>();
        if (q.empty()) break;
        q.push(nullptr);
        continue;
      }

      tmp.push_back(cur->val);
      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    return ret;
  }
};
