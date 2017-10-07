class Solution
{
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs)
  {
    vector<int> t(n, 0);
    if (logs.empty()) return t;
    stack<int> calls;

    for (int i = 0, ts0; i < logs.size(); ++i) {
      string& entry = logs[i];
      int p1 = entry.find_first_of(':');
      int p2 = entry.find_last_of(':');

      int id = stoi(entry.substr(0, p1));
      bool start = "start" == entry.substr(p1 + 1, p2 - p1 - 1);
      int ts = stoi(entry.substr(p2 + 1));

      if (start) {
        if (calls.size())
          t[calls.top()] += ts - ts0 - 1;
        calls.push(id);
      } else {
        t[calls.top()] += ts - ts0 + 1;
        calls.pop();
      }

      ts0 = ts;
    }

    return t;
  }
};
