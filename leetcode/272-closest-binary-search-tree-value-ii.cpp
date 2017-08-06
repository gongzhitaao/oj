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
  vector<int> closestKValues(TreeNode* root, double target, int k)
  {
    deque<double> q;
    for (TreeNode *cur = root, *tmp = nullptr; cur; ) {
      if (!cur->left) {
        if (q.size() < k)
          q.push_back(cur->val);
        else if (abs(cur->val-target) < abs(q.front()-target)) {
          q.push_back(cur->val);
          q.pop_front();
        }
        cur = cur->right;
      } else {
        for (tmp = cur->left;
             tmp->right && tmp->right != cur;
             tmp = tmp->right) ;
        if (tmp->right) {
          tmp->right = nullptr;
          if (q.size() < k)
            q.push_back(cur->val);
          else if (abs(cur->val-target) < abs(q.front()-target)) {
            q.push_back(cur->val);
            q.pop_front();
          }
          cur = cur->right;
        } else {
          tmp->right = cur;
          cur = cur->left;
        }
      }
    }

    return vector<int>(q.begin(), q.end());
  }
};
