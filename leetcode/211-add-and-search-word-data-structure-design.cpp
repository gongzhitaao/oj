class WordDictionary
{
  struct Node {
    bool word;
    unordered_map<char, Node*> next;

    Node() : word(false) { }
  };

  Node* head_;

 public:
  /** Initialize your data structure here. */
  WordDictionary()
  {
    head_ = new Node();
  }

  /** Adds a word into the data structure. */
  void addWord(string word)
  {
    Node* cur = head_;
    for (char ch : word) {
      if (cur->next.find(ch) == cur->next.end())
        cur->next[ch] = new Node();
      cur = cur->next[ch];
    }
    cur->word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word)
  {
    return dfs(head_, word, 0);
  }

  bool dfs(Node* cur, const string& word, int i0)
  {
    if (i0 == word.size()) return cur->word;

    for (int i = i0; i < word.size(); ++i) {
      char ch = word[i];

      if ('.' == ch) {
        for (auto elm : cur->next)
          if (dfs(elm.second, word, i + 1))
            return true;
        return false;
      }

      if (cur->next.find(ch) == cur->next.end())
        return false;

      cur = cur->next[ch];
    }

    return cur->word;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
