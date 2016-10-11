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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
  {
    for (int i = 0; i < inorder.size(); ++i)
      pos_[inorder[i]] = i;
    return build(preorder, inorder, 0, 0, inorder.size());
  }

  TreeNode* build(const vector<int>& preorder,
                  const vector<int>& inorder,
                  int p, int q, int len)
  {
    if (0 == len) return nullptr;
    if (1 == len) return new TreeNode(preorder[p]);

    int val = preorder[p];
    int k = pos_[val], d = k - q;

    TreeNode* par = new TreeNode(val);
    par->left = build(preorder, inorder, p + 1, q, d);
    par->right = build(preorder, inorder, p + d + 1, q + d + 1,
                       len - d - 1);
    return par;
  }

 private:
  map<int, int> pos_;
};
