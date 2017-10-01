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
  vector<vector<int>> verticalOrder(TreeNode* root)
  {
    vector<vector<int>> ret;
    if (!root) return ret;

    int l = 0, r = 0;
    dfs(root, 0, l, r);

    ret = vector<vector<int>>(r - l + 1, vector<int>());
    queue<pair<int, TreeNode*>> q, p;
    int ind;
    TreeNode* node;
    for (q.push({-l, root}); q.size(); ) {
      tie(ind, node) = q.front();
      q.pop();
      ret[ind].push_back(node->val);
      if (node->left) p.push({ind - 1, node->left});
      if (node->right) p.push({ind + 1, node->right});
      if (q.empty()) swap(p, q);
    }

    return ret;
  }

  void dfs(TreeNode* node, int cur, int& l, int& r)
  {
    if (cur < l)
      l = cur;
    else if (cur > r)
      r = cur;
    if (node->left) dfs(node->left, cur - 1, l, r);
    if (node->right) dfs(node->right, cur + 1, l, r);
  }
};
