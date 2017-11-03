class Solution
{
 public:
  vector<int> findSubstring(string s, vector<string>& words)
  {
    vector<int> ret;
    if (s.empty() || words.empty()) return ret;

    const int strlen = s.size();
    const int wordcnt = words.size();
    const int wordlen = words[0].size();

    unordered_map<string, int> dict;
    unordered_map<string, int> visited;
    for (string& word : words) {
      ++dict[word];
      visited[word] = 0;
    }

    for (int start = 0, end = min(wordlen - 1, strlen - wordlen * wordcnt);
         start <= end; ++start) {
      queue<string> seq;
      for (auto& v : visited) v.second = 0;

      for (int i = start, pos = -1, cnt = 0; i <= strlen - wordlen;
           i += wordlen) {
        string word = s.substr(i, wordlen);

        if (dict.find(word) == dict.end()) {
          for (; seq.size(); seq.pop())
            --visited[seq.front()];
          cnt = 0, pos = -1;
          continue;
        }

        for (; visited[word] >= dict[word]; pos += wordlen, --cnt, seq.pop())
          --visited[seq.front()];

        ++visited[word];
        seq.push(word);
        if (pos < 0) pos = i;
        if (++cnt == wordcnt) ret.push_back(pos);
      }
    }

    return ret;
  }
};
