class Solution
{
 public:
  struct Node
  {
    bool word;
    unordered_map<char, Node*> next;
    Node() : word(false) { }
  };

  vector<string> wordBreak(string s, unordered_set<string>& wordDict)
  {
    Node* trie = new Node();
    for (string word : wordDict) {
      Node* cur = trie;
      for (char c : word) {
        if (cur->next.find(c) == cur->next.end())
          cur->next[c] = new Node();
        cur = cur->next[c];
      }
      cur->word = true;
    }

    unordered_map<string, vector<string> > memo;
    dfs(s, trie, "", memo);
    return memo[s];
  }

  vector<string> dfs(string s, Node* trie, string path,
                     unordered_map<string, vector<string> >& memo)
  {
    if (memo.find(s) != memo.end())
      return memo[s];

    vector<string> ret;
    if (path.size()) path += " ";

    Node* cur = trie;
    for (int i = 0;
         i < s.size() && cur->next.find(s[i]) != cur->next.end();
         ++i) {
      cur = cur->next[s[i]];
      if (cur->word) {
        string prefix = path + s.substr(0, i+1);
        string sub = s.substr(i+1);
        if (sub.size()) {
          memo[sub] = dfs(sub, trie, "", memo);
          for (string e: memo[sub])
            ret.push_back(prefix + " " + e);
        } else
          ret.push_back(prefix);
      }
    }

    memo[s] = ret;
    return ret;
  }
};
