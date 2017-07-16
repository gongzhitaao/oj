class WordDictionary
{
  struct node;
  typedef shared_ptr<node> nodeptr;
  struct node {
    bool word;
    unordered_map<char, nodeptr> next;
    node() : word(false) { }
  };

 public:
  /** Initialize your data structure here. */
  WordDictionary()
  {
    dict_ = make_shared<node>();
  }

  /** Adds a word into the data structure. */
  void addWord(string word)
  {
    nodeptr head = dict_;
    for (char c : word) {
      if (head->next.find(c) == head->next.end())
        head->next[c] = make_shared<node>();
      head = head->next[c];
    }
    head->word = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word)
  {
    if (nullptr == dict_)
      return false;
    return dfs(dict_, word, 0);
  }

 private:
  bool dfs(const nodeptr& cur, const string& word, int pos)
  {
    if (word.size() == pos)
      return cur->word;

    char c = word[pos];

    if ('.' == c) {
      for (auto elm : cur->next)
        if (dfs(elm.second, word, pos+1))
          return true;
      return false;
    }

    if (cur->next.find(c) != cur->next.end())
      return dfs(cur->next[c], word, pos+1);

    return false;
  }

  nodeptr dict_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
