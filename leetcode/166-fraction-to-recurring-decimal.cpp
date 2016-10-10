class Solution
{
 public:
  string fractionToDecimal(int numerator, int denominator)
  {
    long long num = numerator, den = denominator;
    string symb = (((num >> 31) ^ (den >> 31)) && num) ? "-" : "";
    num = abs(num);
    den = abs(den);

    long long rem = num % den;
    num /= den;
    string inte = to_string(num);

    string frac;
    map<long long, int> rems;
    for (int i = 0; rem && rems.find(rem) == rems.end(); ++i) {
      rems[rem] = i;
      num = rem * 10;
      rem = num % den;
      num /= den;
      frac += to_string(num);
    }

    frac = frac.empty()
           ? "" : "." +
           (!rem
            ? frac
            : (frac.substr(0, rems[rem]) +
               "(" + frac.substr(rems[rem]) + ")"));
    return symb + inte + frac;
  }
};
