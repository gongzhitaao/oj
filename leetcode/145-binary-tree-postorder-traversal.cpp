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

    stack<TreeNode*> p, q;
    for (p.push(root); p.size();) {
      TreeNode* cur = p.top();
      q.push(cur);
      p.pop();
      if (cur->left) p.push(cur->left);
      if (cur->right) p.push(cur->right);
    }

    for (; q.size(); q.pop()) ret.push_back(q.top()->val);
    return ret;
  }
};
