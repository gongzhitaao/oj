class Solution
{
 public:
  int calculate(string s)
  {
    vector<int> args, ops;
    s.push_back('+');
    for (int i = 0, n = 0; i < s.size(); ++i) {
      if (' ' == s[i]) continue;
      if ('0' <= s[i] && s[i] <= '9') {
        n = n * 10 + s[i] - '0';
      } else {
        args.push_back(n);
        ops.push_back(s[i]);
        n = 0;
      }
    }
    s.pop_back();

    reverse(args.begin(), args.end());

    int lastarg = args.back(), lastop = -1;
    for (int i = 0; i < ops.size(); ++i) {
      if ('*' == ops[i]) {
        int cur = *args.rbegin() * *next(args.rbegin());
        args.pop_back();
        args.back() = cur;
      } else if ('/' == ops[i]) {
        int cur = *args.rbegin() / *next(args.rbegin());
        args.pop_back();
        args.back() = cur;
      } else {
        if (lastop > 0) {
          if ('+' == lastop)
            args.back() += lastarg;
          else if ('-' == lastop)
            args.back() = lastarg - args.back();
          lastop = -1;
        }
        lastarg = args.back(), lastop = ops[i];
        args.pop_back();
      }
    }

    return lastarg;
  }
};
