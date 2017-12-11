class Solution
{
 public:
  string nextClosestTime(string time)
  {
    vector<int> dict;
    for (char ch : time) {
      if (':' == ch) continue;
      bool exist = false;
      for (int c : dict)
        if (c + '0' == ch) exist = true;
      if (!exist) dict.push_back(ch - '0');
    }

    vector<int> hours;
    for (int i = 0; i < dict.size(); ++i)
      for (int j = 0, tmp; j < dict.size(); ++j)
        if ((tmp = dict[i] * 10 + dict[j]) < 24) hours.push_back(tmp);

    vector<int> mins;
    for (int i = 0; i < dict.size(); ++i)
      for (int j = 0, tmp; j < dict.size(); ++j)
        if ((tmp = dict[i] * 10 + dict[j]) < 60) mins.push_back(tmp);

    int cur = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    int hour, min;
    int diff = numeric_limits<int>::max();
    for (int i = 0; i < hours.size(); ++i) {
      for (int j = 0; j < mins.size(); ++j) {
        int tmp = hours[i] * 60 + mins[j];
        if (tmp - cur <= 0) tmp += 24 * 60;
        if (tmp - cur < diff)
          hour = hours[i], min = mins[j], diff = tmp - cur;
      }
    }
    return (hour < 10 ? "0" : "") + to_string(hour) + ":" +
           (min < 10 ? "0" : "") + to_string(min);
  }
};
