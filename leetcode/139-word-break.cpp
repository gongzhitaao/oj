class Solution
{
 public:
  bool wordBreak(string s, vector<string>& wordDict)
  {
    struct node;
    typedef shared_ptr<node> nodeptr;

    struct node {
      bool word;
      unordered_map<char, nodeptr> next;

      node(bool w = false) : word(w) { }
    };

    nodeptr head = make_shared<node>();
    for (string& word : wordDict) {
      nodeptr n = head;
      for (int i = word.size() - 1; i >= 0; --i) {
        char ch = word[i];
        if (n->next.find(ch) == n->next.end()) {
          nodeptr p = make_shared<node>();
          n->next[ch] = p;
        }
        n = n->next[ch];
      }
      n->word = true;
    }

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 0; i < s.size(); ++i) {
      nodeptr n = head;
      for (int j = i; j >= 0 && n->next.find(s[j]) != n->next.end(); --j) {
        n = n->next[s[j]];
        if (n->word && (dp[i+1] = dp[j]))
          break;
      }
    }

    return dp.back();
  }
};
