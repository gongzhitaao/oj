/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root)
  {
    if (!root) return "#";
    return to_string(root->val) + "," +
        serialize(root->left) + "," +
        serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data)
  {
    stringstream ss(data);
    return decode(ss);
  }

  TreeNode* decode(stringstream& ss)
  {
    string val;
    getline(ss, val, ',');
    if ("#" == val) return nullptr;
    TreeNode* par = new TreeNode(stoi(val));
    par->left = decode(ss);
    par->right = decode(ss);
    return par;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
