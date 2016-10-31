class Solution
{
 public:
  vector<pair<int, int> >
  reconstructQueue(vector<pair<int, int> >& people)
  {
    sort(people.begin(), people.end(),
         [](pair<int, int>& a, pair<int, int>& b) {
           return (a.first == b.first
                   ? a.second < b.second
                   : a.first > b.first);
         });
    vector<pair<int, int> > ret;
    for (auto p : people)
      ret.insert(ret.begin()+p.second, p);
    return ret;
  }
};
