#!/bin/bash

todo=$(comm -13 \
            <(ls *.cpp | sed -rn 's/([0-9]+)-.*$/\1/p' | sort) \
            <(seq -w 761))

if [ $# -eq 0 ]; then
    echo $todo
else
    res=$(echo $todo | tr ' ' '\n' | grep -xc "$1")

    if [ $res -eq 0 ]; then
        echo -e "\033[01;32mFinished!\033[0m"
    else
        echo -e "\033[01;31mNot Finished!\033[0m"
    fi
fi
