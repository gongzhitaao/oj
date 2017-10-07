class Solution
{
  struct Node {
    bool word;
    unordered_map<char, Node*> next;

    Node() : word(false){};
  };

 public:
  bool wordBreak(string s, vector<string>& wordDict)
  {
    Node* dict = new Node();

    for (string& word : wordDict) {
      Node* cur = dict;
      for (char ch : word) {
        if (cur->next.find(ch) == cur->next.end()) cur->next[ch] = new Node();
        cur = cur->next[ch];
      }
      cur->word = true;
    }

    const int n = s.size();
    vector<bool> memo(n + 1, true);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        memo[i] = memo[j - 1] && contains(dict, s.substr(j - 1, i - j + 1));
        if (memo[i]) break;
      }
    }

    return memo.back();
  }

  bool contains(Node* dict, const string& word)
  {
    Node* cur = dict;
    for (char ch : word) {
      if (cur->next.find(ch) == cur->next.end()) return false;
      cur = cur->next[ch];
    }
    return cur->word;
  }
};
