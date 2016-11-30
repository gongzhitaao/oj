class Solution
{
 public:
  bool validWordAbbreviation(string word, string abbr)
  {
    int i = 0, j = 0, n = 0;
    for (; j < word.size() && i < abbr.size(); ++i) {
      if (isdigit(abbr[i])) {
        n = n * 10 + abbr[i]-'0';
        if (!n) return false;
      } else {
        j += n;
        n = 0;
        if (word[j++] != abbr[i])
          return false;
      }
    }
    if (n) j += n;
    return j == word.size() && i == abbr.size();
  }
};
