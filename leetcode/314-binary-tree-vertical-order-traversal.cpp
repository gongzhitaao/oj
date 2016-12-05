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
  vector<vector<int> > verticalOrder(TreeNode* root)
  {
    if (!root) return vector<vector<int> >();

    typedef list<vector<int> >::iterator ptr_t;
    list<vector<int> > lst;

    queue<pair<TreeNode*, ptr_t> > q;
    q.push({nullptr, lst.end()});
    q.push({root, lst.insert(lst.end(), vector<int>())});

    TreeNode* nd;
    ptr_t cur;

    while (!q.empty()) {
      tie(nd, cur) = q.front(); q.pop();

      if (!nd) {
        if (q.empty()) break;
        q.push({nullptr, lst.end()});
        continue;
      }

      cur->push_back(nd->val);

      if (nd->left) {
        ptr_t p = prev(cur);
        if (p == lst.end())
          p = lst.insert(cur, vector<int>());
        q.push({nd->left, p});
      }

      if (nd->right) {
        ptr_t n = next(cur);
        if (n == lst.end())
          n = lst.insert(lst.end(), vector<int>());
        q.push({nd->right, n});
      }
    }

    return vector<vector<int> >(
        make_move_iterator(begin(lst)),
        make_move_iterator(end(lst)));
  }
};
