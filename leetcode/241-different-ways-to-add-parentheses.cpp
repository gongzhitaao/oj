class Solution
{
 public:
  vector<int> diffWaysToCompute(string input)
  {
    vector<int> args, ops;
    input.push_back('-');
    for (int i = 0, num = 0; i < input.size(); ++i) {
      if ('0' <= input[i] && input[i] <= '9')
        num = num * 10 + input[i] - '0';
      else {
        args.push_back(num);
        num = 0;
        ops.push_back(input[i]);
      }
    }
    input.pop_back();
    ops.pop_back();

    return dfs(input, args, ops, 0, args.size() - 1);
  }

  vector<int> dfs(string& input, vector<int>& args, vector<int>& ops, int start,
                  int end)
  {
    if (start == end) return {args[start]};

    vector<int> res;
    for (int i = start; i < end; ++i) {
      vector<int> res1 = dfs(input, args, ops, start, i);
      vector<int> res2 = dfs(input, args, ops, i + 1, end);

      if ('-' == ops[i])
        for (int a : res1)
          for (int b : res2)
            res.push_back(a - b);
      else if ('+' == ops[i])
        for (int a : res1)
          for (int b : res2)
            res.push_back(a + b);
      else if ('*' == ops[i])
        for (int a : res1)
          for (int b : res2)
            res.push_back(a * b);
    }

    return res;
  }
};
