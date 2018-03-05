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
  vector<vector<int>> findLeaves(TreeNode* root)
  {
    if (!root) return vector<vector<int>>();
    vector<pair<int, int>> flat;
    int maxdep = 0;
    dfs(root, maxdep, flat);
    vector<vector<int>> ret(maxdep + 1, vector<int>());
    for (auto& elm : flat) ret[elm.second].push_back(elm.first);
    return ret;
  }

  int dfs(TreeNode* cur, int& maxdep, vector<pair<int, int>>& flat)
  {
    if (!cur) return -1;
    int l = dfs(cur->left, maxdep, flat);
    int r = dfs(cur->right, maxdep, flat);
    int curdep = max(l, r) + 1;
    if (curdep > maxdep) maxdep = curdep;
    flat.push_back({cur->val, curdep});
    return curdep;
  }
};
