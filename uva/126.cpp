/*!
  \file   126.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Sun Jun 16 11:02:39 2013

  \brief  The Errant Physicist
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct exponent
{
    unsigned x_, y_;

    exponent(unsigned x, unsigned y)
        : x_(x), y_(y) {}
};

struct comp
{
    bool operator() (const exponent &a, const exponent &b)
    {
        return a.x_ > b.x_ ? true : a.x_ < b.x_ ? false : a.y_ < b.y_;
    }
};

typedef map<exponent, int, comp> poly_type;

int print_coef(char *s, int n, bool b)
{
    if (b) {
        if (n > 0) return sprintf(s, " + %d", n);
        else return sprintf(s, " - %d", -n);
    } else {
        if (1 == n) return sprintf(s, " + ");
        else if (-1 == n) return sprintf(s, " - ");
        else if (n > 0) return sprintf(s, " + %d", n);
        else return sprintf(s, " - %d", -n);
    }
}

int print_xy(char *s, int n, char ch)
{
    if (0 == n) return 0;
    else {
        s[0] = ch;
        if (n > 1) return sprintf(s+1, "%d", n)+1;
        else return 1;
    }
}

void str(const poly_type &p, char *expo, char *item)
{
    int a = 0;
    for (poly_type::const_iterator i = p.begin(); i != p.end(); ++i) {
        a += print_coef(item+a, i->second, 0 == i->first.x_ && 0 == i->first.y_ );
        a += print_xy(item+a, i->first.x_, 'x');
        a += print_xy(item+a, i->first.y_, 'y');
    }

    int len = strlen(item);
    bool f = false;
    for (int i = 0; i < len; ++i) {
        if (f && isdigit(item[i])) {
            expo[i] = item[i];
            item[i] = ' ';
        }
        else {
            expo[i] = ' ';
            f = ('x' == item[i] || 'y' == item[i]);
        }
    }
    expo[len] = item[len] = 0;
}

ostream &operator<<(ostream &o, const poly_type &p)
{
    char a[90] = {0}, b[90] = {0};
    str(p, a, b);
    if ('-' == b[1])
        o << a+2 << endl << '-' << b+3;
    else o << a + 3 << endl << b+3;
    return o;
}

void parse(const char *s, poly_type &p)
{
    int coef;
    unsigned x = 0, y = 0;

    int beg = 0;
    if ('-' == s[0] || '+' == s[0]) {
        if (isdigit(s[1])) {
            coef = atoi(s);
            for (; isdigit(s[beg]); ++beg)/* empty */;
        } else {
            coef = '-' == s[0] ? -1 : 1;
            beg = 1;
        }
    } else {
        if (isdigit(s[0])) {
            coef = atof(s);
            for (; isdigit(s[beg]); ++beg)/* empty */;
        } else {
            coef = 1;
            beg = 0;
        }
    }

    int len = strlen(s);

    for (int i = beg; i < len; ++i) {
        switch (s[i]) {
        case 'x':
            x = atoi(s+i+1);
            if (0 == x) x = 1;
            else for (; isdigit(s[i+1]); ++i) ;
            break;
        case 'y':
            y = atoi(s+i+1);
            if (0 == y) y = 1;
            else for (; isdigit(s[i+1]); ++i) ;
            break;
        case '-':
        case '+':
            p[exponent(x,y)] += coef;
            if (isdigit(s[i+1])) {
                coef = atoi(s+i);
                for (; isdigit(s[i+1]); ++i) ;
            } else coef = '-' == s[i] ? -1 : 1;
            x = y = 0;
            break;
        default: break;
        }
    }
    p[exponent(x,y)] += coef;
}

void multiply(const poly_type &a, const poly_type &b, poly_type &c)
{
    for (poly_type::const_iterator i = a.begin(); i != a.end(); ++i) {
        for (poly_type::const_iterator j = b.begin(); j != b.end(); ++j) {
            int x = i->first.x_ + j->first.x_;
            int y = i->first.y_ + j->first.y_;
            int v = i->second * j->second;
            c[exponent(x,y)] += v;
        }
    }

    for (poly_type::iterator i = c.begin(); i != c.end(); ++i)
        if (0 == i->second) c.erase(i);
}


int main()
{
    char s1[90], s2[90];
    while (cin.getline(s1, 90) && s1[0] != '#') {
        cin.getline(s2, 90);

        poly_type p1, p2;
        parse(s1, p1);
        parse(s2, p2);

        poly_type p;
        multiply(p1, p2, p);
        cout << p << endl;
    }

    return 0;
}
