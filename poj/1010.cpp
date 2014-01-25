
// STAMPS
// Time-stamp: <2012-11-30 14:30:49 CST gongzhitaao>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int pattern[4][4][4][4] = {
    {{{1}}, {{2}}, {{3}}, {{4}}},
    {{}, {{1,1}}, {{2,1},{1,2}}, {{2,2},{3,1},{1,3}}},
    {{}, {}, {{1,1,1}}, {{2,1,1},{1,2,1},{1,1,2}}},
    {{}, {}, {}, {{1,1,1,1}}}
};

const int pattern_count[4][4] = {
    {1,1,1,1},{0,1,2,3},{0,0,1,3},{0,0,0,1}
};

vector<int> stamp_value;
int choice[4];
int ans[4], idx_type, idx_count, idx_pattern;

bool next_choice(/* choice */)
{
    if (choice[0] == idx_type - 1) return false;
    int i = idx_type - 1;
    while (choice[i] <= idx_type - 1 - i) --i;
    --choice[i];
    while (++i < idx_type) choice[i] = choice[i - 1] - 1;
    return true;
}

int solve(int request)
{
    if (request < stamp_value[0] ||
        (request >> 2) > stamp_value.back())
        return 0;

    int type_cnt = stamp_value.size();
    int max_type = min(type_cnt, min(request / stamp_value[0], 4));

    int sum, ans_cnt = 0, max_val = -1;
    for (int type = max_type; type > 0; --type) {
        idx_type = type;

        for (int count = type; count <= 4; ++count) {
            idx_count = count;

            for (int i = 0; i < type; ++i)
                choice[i] = type_cnt - 1 - i;
            max_val = stamp_value[choice[0]];

            do {

                if (max_val > stamp_value[choice[0]]) {
                    if (ans_cnt) return 1;
                    else max_val = stamp_value[choice[0]];
                }

                for (int i = 0; i < pattern_count[type-1][count-1]; ++i) {
                    idx_pattern = i;

                    sum = 0;
                    for (int j = 0; j < type; ++j)
                        sum += pattern[type-1][count-1][i][j] * stamp_value[choice[j]];

                    if (request == sum) {
                        if (!ans_cnt) {
                            for (int k = 0; k < type; ++k) ans[k] = stamp_value[choice[k]];
                            ans_cnt = 1;
                        } else return 2;
                    }
                }
            } while (next_choice());

            if (ans_cnt) return 1;
        }
    }
    return 0;
}

int main()
{
    int t, r;
    while (cin >> t && t) {
        stamp_value.clear();
        stamp_value.push_back(t);

        while (cin >> t && t) stamp_value.push_back(t);
        sort(stamp_value.begin(), stamp_value.end());

        while (cin >> t && t) {
            r = solve(t);
            cout << t;
            if (0 == r)
                cout << " ---- none";
            else {
                cout << " (" << idx_type << "):";
                if (1 == r) {
                    for (int i = idx_type - 1; i >= 0; --i)
                        for (int j = 0;
                             j < pattern[idx_type-1][idx_count-1][idx_pattern][i];
                             ++j)
                            cout << ' ' << ans[i];
                } else cout << " tie";
            }
            cout << endl;
        }
    }
    return 0;
}
