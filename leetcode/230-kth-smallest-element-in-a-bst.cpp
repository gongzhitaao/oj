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
  int kthSmallest(TreeNode* root, int k)
  {
    vector<int> vec;
    dfs(root, vec);
    nth_element(vec.begin(), vec.begin()+k-1, vec.end());
    return vec[k-1];
  }

  void dfs(TreeNode* node, vector<int>& vec)
  {
    if (!node) return;
    vec.push_back(node->val);
    dfs(node->left, vec);
    dfs(node->right, vec);
  }
};
