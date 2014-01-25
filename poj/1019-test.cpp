#include <fstream>
using namespace std;

char ch[1395495+2];

int main()
{
    ofstream fo("in");
    int b = 0;
    for (int i = 1; i < 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            b += sprintf(ch+b, "%d", j);
        }
    }
    fo << ch;
    fo.close();
    return 0;
}
