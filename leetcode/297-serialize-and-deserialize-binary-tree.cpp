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
    return encode(root);
  }

  string encode(TreeNode* cur)
  {
    if (!cur) return "#";
    return to_string(cur->val) + " " + encode(cur->left) + " " +
           encode(cur->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data)
  {
    istringstream iss(data);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    int ind = 0;
    return decode(tokens, ind);
  }

  TreeNode* decode(const vector<string>& tokens, int& ind)
  {
    if ("#" == tokens[ind]) return nullptr;
    TreeNode* cur = new TreeNode(stoi(tokens[ind]));
    cur->left = decode(tokens, ++ind);
    cur->right = decode(tokens, ++ind);
    return cur;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
