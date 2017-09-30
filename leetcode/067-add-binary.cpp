class Solution
{
 public:
  string addBinary(string a, string b)
  {
    if (a.size() < b.size()) return addBinary(b, a);
    string ret(a.size() + 1, ' ');

    int c = 0;
    int i = 0, na = a.size() - 1, nb = b.size() - 1;

    for (int ia, ib, ai, bi; i <= nb; ++i) {
      ia = na - i, ib = nb - i;
      ai = a[ia] - '0', bi = b[ib] - '0';
      ret[i] = (ai ^ bi ^ c) + '0';
      c = (ai & bi) | (c & (ai ^ bi));
    }

    for (int ia, ai; i <= na; ++i) {
      ia = na - i;
      ai = a[ia] - '0';
      ret[i] = (ai ^ c) + '0';
      c = ai & c;
    }

    if (c) ret[i] = '1';

    while (ret.back() == ' ') ret.pop_back();
    reverse(ret.begin(), ret.end());

    return ret;
  }
};
