#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void int2inv(const char *a, char *b)
{
    int c[10];
    memset(c, 0, sizeof c);

    for (int i = 0; '\0' != a[i]; ++i)
        ++c[a[i]-'0'];

    for (int i = 0, j = 0; i <= 9; ++i)
        if (c[i] > 0)
            j += sprintf(b+j, "%d%d", c[i], i);
}

int main()
{
    const int INTR = 16;
    char d[INTR][81];
    while (scanf("%s", d[0])) {
        if (-1 == atoi(d[0])) break;

        int2inv(d[0], d[1]);
        if (0 == strcmp(d[0], d[1]))
            printf("%s is self-inventorying\n", d[0]);
        else {
            bool f = false;
            for (int i = 2; i < INTR; ++i) {
                int2inv(d[i-1], d[i]);
                if (f = 0 == strcmp(d[i-1], d[i]))
                    printf("%s is self-inventorying after %d steps\n", d[0], i-1);
                if (f) break;

                for (int j = 0; j < i-1; ++j)
                    if (f = 0 == strcmp(d[j], d[i])) {
                        printf("%s enters an inventory loop of length %d\n", d[0], i-j);
                        break;
                    }
                if (f) break;
            }
            if (!f) printf("%s can not be classified after 15 iterations\n", d[0]);
        }
    }
    return 0;
}
