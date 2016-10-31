class Solution
{
 public:
  string reverseVowels(string s)
  {
    for (int i = 0, j = s.size() - 1; i < j; ) {
      bool bi = isvowel(s[i]), bj = isvowel(s[j]);
      if (bi && bj) swap(s[i++], s[j--]);
      else i += !bi, j -= !bj;
    }
    return s;
  }

  inline bool isvowel(char c)
  {
    return 'a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c ||
        'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c;
  }
};
