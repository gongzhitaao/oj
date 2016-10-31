class Solution
{
 public:
  vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
  {
    vector<pair<int, int> > ret;
    if (!buildings.empty())
      ret = foo(buildings, 0, buildings.size());
    return ret;
  }

  vector<pair<int, int> >
  foo(vector<vector<int> >& B, int i0, int n)
  {
    if (1 == n)
      return {{B[i0][0], B[i0][2]}, {B[i0][1], 0}};

    vector<pair<int, int> > sky,
        sky0 = foo(B, i0, n/2),
        sky1 = foo(B, i0+n/2, n-n/2);

    int i = 0, j = 0, h = 0;
    for (int h0 = 0, h1 = 0; i < sky0.size() && j < sky1.size(); ) {
      pair<int, int> &s0 = sky0[i], &s1 = sky1[j];
      if (s0.first < s1.first) {
        ++i;
        h0 = s0.second;
        int newh = max(h0, h1);
        if (newh != h) {
          h = newh;
          sky.push_back({s0.first, h});
        }
      } else if (s0.first > s1.first) {
        ++j;
        h1 = s1.second;
        int newh = max(h0, h1);
        if (newh != h) {
          h = newh;
          sky.push_back({s1.first, h});
        }
      } else {
        ++i, ++j;
        h0 = s0.second, h1 = s1.second;
        int newh = max(h0, h1);
        if (newh != h) {
          h = newh;
          sky.push_back({s0.first, h});
        }
      }
    }

    for (; i < sky0.size(); ++i) {
      if (sky0[i].second != h) {
        h = sky0[i].second;
        sky.push_back(sky0[i]);
      }
    }

    for (; j < sky1.size(); ++j) {
      if (sky1[j].second != h) {
        h = sky1[j].second;
        sky.push_back(sky1[j]);
      }
    }

    return sky;
  }
};
