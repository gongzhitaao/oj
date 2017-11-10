class Solution
{
 public:
  vector<string> removeComments(vector<string>& source)
  {
    vector<string> ret;
    char pre = 0;
    for (string& line : source) {
      string tmp;
      char last = pre;
      for (char ch : line) {
        if (0 == pre) {
          if ('/' == ch)
            pre = ch;
          else
            tmp += ch;
        } else if ('/' == pre) {
          if ('/' == ch) {
            pre = 0;
            break;
          } else if ('*' == ch) {
            pre = '(';
          } else {
            pre = 0;
            tmp += '/';
            tmp += ch;
          }
        } else if ('(' == pre) {
          if ('*' == ch) pre = ')';
        } else if (')' == pre) {
          if ('/' == ch)
            pre = 0;
          else if ('*' == ch)
            pre = ')';
          else
            pre = '(';
        }
      }

      if (pre && '(' != pre) {
        tmp += pre;
        pre = 0;
      }

      if (tmp.size()) {
        if (0 == last)
          ret.push_back(tmp);
        else
          ret.back() += tmp;
      }
    }

    return ret;
  }
};
