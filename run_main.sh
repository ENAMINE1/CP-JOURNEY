#!/bin/bash

# Compile the program with sanitizers
g++ -DLOCAL -g -fsanitize=address,undefined -o main main.cpp
success=$?
if [ $success -eq 0 ]; then
    echo "Compilation successful!"

    # Generate the checksum for main.cpp
    checksum=$(python3 generate_checksum.py main.cpp)
    echo "Checksum: $checksum"

    # Append the checksum to the end of main.cpp
    echo -e "\n// Checksum: $checksum" >> main.cpp
    echo "Checksum appended to main.cpp"

    echo "Start of Program"
    echo
    ./main < input.txt > output.txt
    echo
    echo "End of Program"
else
    echo "Compilation failed!"
fi

# Clean up the executable
rm -rf main
