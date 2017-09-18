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
  TreeNode* trimBST(TreeNode* root, int L, int R)
  {
    return trimbst(root, L, R);
  }

  TreeNode* trimbst(TreeNode* node, int L, int R)
  {
    if (!node) return node;

    if (node->val < L) return trimbst(node->right, L, R);
    if (node->val > R) return trimbst(node->left, L, R);

    node->left = trimbst(node->left, L, R);
    node->right = trimbst(node->right, L, R);

    return node;
  }
};
