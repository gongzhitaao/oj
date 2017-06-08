class Solution {
  public:
    string licenseKeyFormatting(string S, int K)
    {
        string ret;
        for (int i = S.size()-1, j; i >= 0; ) {
            for (j = 0; j < K && i >= 0; --i) {
                if ('-' != S[i]) {
                    ret = char(toupper(S[i])) + ret;
                    ++j;
                }
            }
            if (j == K)
                ret = '-' + ret;
        }
        if ('-' == ret[0])
            return ret.substr(1);
        return ret;
    }
};
