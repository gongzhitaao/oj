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
  int kthSmallest(TreeNode* root, int k) {
    int cnt = k;
    return dfs(root, cnt)->val;
  }

  TreeNode* dfs(TreeNode* node, int& cnt) {
    TreeNode* ret = NULL;
    if (node->left) ret = dfs(node->left, cnt);
    if (ret) return ret;

    --cnt;
    if (!cnt) return node;

    if (node->right) ret = dfs(node->right, cnt);
    return ret;
  }
};
