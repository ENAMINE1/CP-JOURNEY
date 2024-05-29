#!/bin/bash

g++ -DLOCAL -g -fsanitize=address,undefined -o main main.cpp
success=$?
if [ $success -eq 0 ]; then
    echo "Start of Program"
    echo
    ./main < input.txt > output.txt
    echo
    echo "End of Program"
else
    echo "Compilation failed!"
fi

rm -rf main