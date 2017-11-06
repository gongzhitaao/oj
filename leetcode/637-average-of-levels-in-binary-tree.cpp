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
  vector<double> averageOfLevels(TreeNode *root)
  {
    vector<double> ret;
    if (!root) return ret;

    queue<TreeNode *> q, p;
    double avg = 0.0;
    int cnt = 0;
    for (q.push(root); q.size();) {
      TreeNode *cur = q.front();
      q.pop();

      avg = (cur->val + cnt * avg) / (cnt + 1);
      ++cnt;

      if (cur->left) p.push(cur->left);
      if (cur->right) p.push(cur->right);

      if (q.empty()) {
        swap(p, q);
        ret.push_back(avg);
        avg = 0.0;
        cnt = 0;
      }
    }

    return ret;
  }
};
