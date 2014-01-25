/*!
  \file   128.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Mon Jun 17 14:35:34 2013

  \brief  Software CRC
*/

#include <stdio.h>

int main()
{
    char ch;
    unsigned mod = 0;
    unsigned g = 34943;
    while ((ch = getchar()) && ('#' != ch)) {
        if ('\n' == ch) {
            mod = (mod<<16) % g;
            if (mod > 0) mod = g-mod;
            printf("%02X %02X\n", mod>>8, mod&0xFF);
            mod = 0;
        } else mod = ((mod<<8) + ch) % g;
    }
    return 0;
}
