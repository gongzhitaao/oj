class Trie
{
  struct node;
  typedef shared_ptr<node> nodeptr;

 public:
  /** Initialize your data structure here. */
  Trie()
  {
    dict_ = make_shared<node>();
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    nodeptr cur = dict_;
    for (char c : word) {
      if (cur->next.find(c) == cur->next.end())
        cur->next[c] = make_shared<node>();
      cur = cur->next[c];
    }
    cur->word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    nodeptr cur = dict_;
    for (char c : word) {
      if (cur->next.find(c) == cur->next.end())
        return false;
      cur = cur->next[c];
    }
    return cur->word;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    nodeptr cur = dict_;
    for (char c : prefix) {
      if (cur->next.find(c) == cur->next.end())
        return false;
      cur = cur->next[c];
    }
    return true;
  }

 private:
  struct node {
    bool word;
    unordered_map<char, nodeptr> next;
    node() : word(false) { }
  };

  nodeptr dict_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
