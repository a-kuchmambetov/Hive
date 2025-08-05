#!/bin/bash

# Check if argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 \"numbers to sort\""
    echo "Example: $0 \"1300 19515 47637 23522 31827\""
    exit 1
fi

# Get the input argument
ARG="$1"

echo "Testing with arguments: $ARG"
echo "----------------------------------------"

# Count the number of operations
echo "Number of operations:"
./push_swap $ARG | wc -l

echo ""

# Check if the sorting is correct
echo "Checker result:"
./push_swap $ARG | ./checker_linux $ARG

echo ""
echo "Test completed."
