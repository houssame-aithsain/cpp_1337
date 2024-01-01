#!/bin/bash

check_sorted() {
    # Split the input parameter into an array based on spaces
    IFS=' ' read -r -a numbers <<< "$1"
    for ((i = 0; i < ${#numbers[@]} - 1; i++)); do
        if [[ ${numbers[i]} -gt ${numbers[i+1]} ]]; then
            echo "Numbers are not sorted."
            return 1
        fi
    done
    echo "Numbers are sorted."
}

# Pass all command-line arguments as a single space-separated string
check_sorted "$*"
