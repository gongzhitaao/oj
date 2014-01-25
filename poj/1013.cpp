// Counterfeit Dollar
// Time-stamp: <2013-04-15 15:34:16 CDT gongzhitaao>

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    const int tot = 'L'-'A'+1;
    // -2: unobserved; 0: good
    // -1: light; 1: heavy
    int coins[tot];
    int mask[tot];

    for (int i = 0; i < n; ++i) {

        fill(coins, coins+tot, -2);

        string s1, s2, s3;
        for (int j = 0; j < 3; ++j) {
            cin >> s1 >> s2 >> s3;

            if (!s3.compare("even")) {
                for (int k = 0; k < s1.size(); ++k)
                    coins[s1[k]-'A'] = coins[s2[k]-'A'] = 0;

            } else if (!s3.compare("up")) {
                fill(mask, mask+tot, 1);
                for (int k = 0; k < s1.size(); ++k) {
                    mask[s1[k]-'A'] = mask[s2[k]-'A'] = 0;
                    if (coins[s1[k]-'A']) coins[s1[k]-'A'] = -1 == coins[s1[k]-'A'] ? 0 : 1;
                    if (coins[s2[k]-'A']) coins[s2[k]-'A'] = 1 == coins[s2[k]-'A'] ? 0 : -1;
                }
                for (int k = 0; k < tot; ++k) if (mask[k]) coins[k] = 0;

            } else /* if (!s3.compare("down") */ {
                fill(mask, mask+tot, 1);
                for (int k = 0; k < s1.size(); ++k) {
                    mask[s1[k]-'A'] = mask[s2[k]-'A'] = 0;
                    if (coins[s1[k]-'A']) coins[s1[k]-'A'] = 1 == coins[s1[k]-'A'] ? 0 : -1;
                    if (coins[s2[k]-'A']) coins[s2[k]-'A'] = -1 == coins[s2[k]-'A'] ? 0 : 1;
                }
                for (int k = 0; k < tot; ++k) if (mask[k]) coins[k] = 0;
            }
        }

        for (int j = 0; j < tot; ++j) {
            if (-1 == coins[j]) {
                cout << char('A'+j) << " is the counterfeit coin and it is light." << endl;
                break;
            } else if (1 == coins[j]) {
                cout << char('A'+j) << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
    }
    return 0;
}
