class Solution
{
 public:
  void reverseWords(vector<char>& str)
  {
    reverse(str.begin(), str.end());
    str.push_back(' ');
    for (int i = 0, j = 0; j < str.size(); ++j) {
      if (' ' == str[j]) {
        reverse(str.begin() + i, str.begin() + j);
        i = j + 1;
      }
    }
    str.pop_back();
  }
};
