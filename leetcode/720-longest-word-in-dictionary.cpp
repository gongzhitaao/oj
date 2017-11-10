class Solution
{
 public:
  struct Node;
  typedef shared_ptr<Node> nodeptr;

  struct Node {
    bool word;
    map<char, nodeptr> next;
    Node() : word(false) {}
  };

  string longestWord(vector<string>& words)
  {
    nodeptr dict = make_shared<Node>();
    for (string& word : words) {
      nodeptr cur = dict;
      for (char ch : word) {
        if (cur->next.find(ch) == cur->next.end())
          cur->next[ch] = make_shared<Node>();
        cur = cur->next[ch];
      }
      cur->word = true;
    }

    return dfs(dict, "");
  }

  string dfs(nodeptr& cur, string word)
  {
    string ret;
    if (cur->word) ret = word;

    for (auto& child : cur->next) {
      if (child.second->word) {
        string tmp = dfs(child.second, word + child.first);
        if (tmp.size() > ret.size()) ret = tmp;
      }
    }

    return ret;
  }
};
