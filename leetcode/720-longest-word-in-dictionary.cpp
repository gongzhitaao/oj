class Solution
{
 public:
  string longestWord(vector<string> &words)
  {
    struct Node;
    typedef shared_ptr<Node> nodeptr;

    struct Node {
      bool word;
      unordered_map<char, nodeptr> next;
      Node() : word(false) {}
    };

    sort(words.begin(), words.end());

    nodeptr dict = make_shared<Node>();
    string ret;
    for (string& word : words) {
      int len = 1;
      nodeptr cur = dict;
      for (char ch : word) {
        if (cur->next.find(ch) == cur->next.end())
          cur->next[ch] = make_shared<Node>();
        cur = cur->next[ch];
        len += cur->word;
      }
      cur->word = true;
      if (len == word.size() && len > ret.size())
        ret = word;
    }

    return ret;
  }
};
