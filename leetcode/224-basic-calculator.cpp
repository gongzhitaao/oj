class Solution
{
 public:
  int calculate(string s)
  {
    vector<int> param;
    vector<char> op;
    int n = -1;
    for (char c : s) {
      if (' ' == c) continue;
      switch (c) {
        case '(':
          op.push_back(c);
          break;
        case ')':
          if (n >= 0) {
            param.push_back(n);
            n = -1;
          }
          while (op.back() != '(')
            eval(param, op);
          op.pop_back();
          break;
        case '-':
        case '+':
          if (n >= 0) {
            param.push_back(n);
            n = -1;
          }
          while (op.size() && ('-' == op.back() || '+' == op.back()))
            eval(param, op);
          op.push_back(c);
          break;
        default:
          if (n < 0) n = 0;
          n = n*10 + c-'0';
      }
    }

    if (n >= 0) param.push_back(n);
    while (op.size()) eval(param, op);
    return param.size() ? param[0] : 0;
  }

  void eval(vector<int>& param, vector<char>& op)
  {
    char c = op.back();
    op.pop_back();
    int b = param.back();
    param.pop_back();
    if ('-' == c)
      param.back() -= b;
    else param.back() += b;
  }
};
