class Solution
{
 public:
  int nthUglyNumber(int n)
  {
    vector<int> uglies(n + 1, 1);

    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; ++i) {
      int n2 = uglies[p2] * 2,
          n3 = uglies[p3] * 3,
          n5 = uglies[p5] * 5;
      if (n2 < n3) {
        if (n2 < n5) uglies[i] = n2, ++p2;
        else if (n2 > n5) uglies[i] = n5, ++p5;
        else uglies[i] = n2, ++p2, ++p5;
      } else if (n2 > n3) {
        if (n3 < n5) uglies[i] = n3, ++p3;
        else if (n3 > n5) uglies[i] = n5, ++p5;
        else uglies[i] = n3, ++p3, ++p5;
      } else {
        if (n2 < n5) uglies[i] = n2, ++p2, ++p3;
        else if (n2 > n5) uglies[i] = n5, ++p5;
        else uglies[i] = n5, ++p2, ++p3, ++p5;
      }
    }
    return uglies[n];
  }
};
