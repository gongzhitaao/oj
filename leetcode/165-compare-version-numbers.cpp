class Solution {
public:
  int compareVersion(string version1, string version2) {
    int v1 = 0, v2 = 0, n1 = version1.size(), n2 = version2.size();
    for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
      for (; i < n1 && version1[i] != '.'; ++i)
        v1 = v1 * 10 + version1[i] - '0';
      for (; j < n2 && version2[j] != '.'; ++j)
        v2 = v2 * 10 + version2[j] - '0';

      if (v1 < v2) return -1;
      if (v1 > v2) return 1;

      v1 = v2 = 0;
    }

    return 0;
  }
};
