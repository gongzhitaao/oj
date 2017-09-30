class Solution
{
 public:
  string numberToWords(int num)
  {
    vector<string> _20{"Zero",    "One",       "Two",      "Three",
                       "Four",    "Five",      "Six",      "Seven",
                       "Eight",   "Nine",      "Ten",      "Eleven",
                       "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> _100{"",      "",      "Twenty",  "Thirty", "Forty",
                        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (0 == num) return _20[num];

    auto under1000 = [&_20, &_100](int n) {
      string ret;
      if (n >= 100) {
        ret += _20[n / 100] + " Hundred ";
        n %= 100;
      }

      if (n >= 20) {
        ret += _100[n / 10] + " ";
        n %= 10;
      }

      if (n)
        ret += _20[n];

      if (isspace(ret.back()))
        ret.pop_back();

      return ret;
    };

    string ret;

    if (num >= 1000000000) {
      ret += _20[num / 1000000000] + " Billion ";
      num %= 1000000000;
    }

    if (num >= 1000000) {
      ret += under1000(num / 1000000) + " Million ";
      num %= 1000000;
    }

    if (num >= 1000) {
      ret += under1000(num / 1000) + " Thousand ";
      num %= 1000;
    }

    ret += under1000(num);

    if (isspace(ret.back()))
      ret.pop_back();

    return ret;
  }
};
