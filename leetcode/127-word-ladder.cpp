class Solution
{
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    unordered_map<string, bool> visited;
    for (string& w : wordList)
      visited[w] = false;

    if (visited.find(endWord) == visited.end())
      return 0;

    visited[beginWord] = true;
    visited[beginWord] = true;

    unordered_set<string> shorter{beginWord};
    unordered_set<string> longer{endWord};

    for (int len = 2, n = beginWord.size();
         shorter.size() && longer.size(); ++len) {

      if (shorter.size() > longer.size())
        swap(shorter, longer);

      unordered_set<string> next;
      for (string w : shorter) {
        for (int i = 0; i < n; ++i) {
          char c = w[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            w[i] = j;

            if (longer.find(w) != longer.end())
              return len;

            if (visited.find(w) == visited.end() || visited[w])
              continue;

            next.insert(w);
            visited[w] = true;
          }
          w[i] = c;
        }
      }

      swap(shorter, next);
    }

    return 0;
  }
};
