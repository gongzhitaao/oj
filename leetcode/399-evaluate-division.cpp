class Solution
{
 public:
  struct info {
    string par;
    double val;
    int rank;
  };

  vector<double>
  calcEquation(vector<pair<string, string> > equations,
               vector<double>& values,
               vector<pair<string, string> > queries)
  {
    unordered_set<string> V;
    unordered_map<string, info> myset;
    int n = values.size();
    for (int i = 0; i < n; ++i) {
      pair<string, string>& eq = equations[i];
      double val = values[i];
      for (string var : vector<string>{eq.first, eq.second}) {
        if (V.find(var) == V.end()) {
          myset[var] = {var, 1.0, 0};
          V.insert(var);
        }
      }
      _union(myset, eq.first, eq.second, val);
    }

    vector<double> ret;
    for (auto& qry : queries) {
      double val = -1;
      if (V.find(qry.first) != V.end() &&
          V.find(qry.second) != V.end()) {
        string p0 = _find(myset, qry.first),
               p1 = _find(myset, qry.second);
        if (p0 == p1)
          val = myset[qry.second].val / myset[qry.first].val;
      }
      ret.push_back(val);
    }
    return ret;
  }

 private:
  void _union(unordered_map<string, info>& myset,
              string v0, string v1, double val)
  {
    string p0 = _find(myset, v0),
           p1 = _find(myset, v1);
    if (p0 == p1) return;

    info &i0 = myset[p0], &i1 = myset[p1];
    double v01 = myset[v0].val * val / myset[v1].val;
    if (i0.rank < i1.rank) {
      i0.par = p1;
      i0.val = 1 / v01;
    } else {
      i1.par = p0;
      i1.val = v01;
      i0.rank += i0.rank == i1.rank;
    }
  }

  string _find(unordered_map<string, info>& myset, string v0)
  {
    info &i = myset[v0];
    if (i.par != v0) {
      string oldpar = i.par;
      i.par = _find(myset, oldpar);
      i.val *= myset[oldpar].val;
    }
    return i.par;
  }
};
