class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2) return 0;

    int count = n / 2;
    bool prime[count] = {true};

    for (int i = 1; i <= sqrt(n) / 2; ++i) {
      if (prime[i]) {
        for (int j = 2 * i * (i + 1); j < n / 2; j += 2 * i + 1) {
          if (prime[j]) {
            --count;
            prime[j] = false;
          }
        }
      }
    }

    return count;
  }
};
