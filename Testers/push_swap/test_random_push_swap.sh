#!/bin/bash

# Default values
DEFAULT_COUNT=5
DEFAULT_NUMBERS=10
DEFAULT_MIN=-1000
DEFAULT_MAX=1000
DEFAULT_RUNS=4

# Function to display usage
usage() {
    echo "Usage: $0 [OPTIONS]"
    echo "Options:"
    echo "  -c, --count NUMBER     Number of random numbers to generate (default: $DEFAULT_NUMBERS)"
    echo "  -r, --runs NUMBER      Number of test runs (default: $DEFAULT_RUNS)"
    echo "  -m, --min NUMBER       Minimum value for random numbers (default: $DEFAULT_MIN)"
    echo "  -M, --max NUMBER       Maximum value for random numbers (default: $DEFAULT_MAX)"
    echo "  -h, --help            Show this help message"
    echo ""
    echo "Example: $0 -c 5 -r 3 -m 1 -M 100"
    echo "This will generate 5 unique random numbers between 1-100 and run 3 tests"
}

# Function to generate unique random numbers
generate_unique_numbers() {
    local count=$1
    local min=$2
    local max=$3
    
    # Check if range is sufficient for unique numbers
    local range=$((max - min + 1))
    if [ $count -gt $range ]; then
        echo "Error: Cannot generate $count unique numbers in range [$min, $max]"
        echo "Maximum possible unique numbers in this range: $range"
        exit 1
    fi
    
    # Generate unique random numbers
    local numbers=()
    while [ ${#numbers[@]} -lt $count ]; do
        local num=$((RANDOM % (max - min + 1) + min))
        
        # Check if number is already in array
        local exists=false
        for existing in "${numbers[@]}"; do
            if [ "$existing" -eq "$num" ]; then
                exists=true
                break
            fi
        done
        
        # Add if unique
        if [ "$exists" = false ]; then
            numbers+=($num)
        fi
    done
    
    echo "${numbers[@]}"
}

# Parse command line arguments
COUNT=$DEFAULT_NUMBERS
RUNS=$DEFAULT_RUNS
MIN=$DEFAULT_MIN
MAX=$DEFAULT_MAX

while [[ $# -gt 0 ]]; do
    case $1 in
        -c|--count)
            COUNT="$2"
            shift 2
            ;;
        -r|--runs)
            RUNS="$2"
            shift 2
            ;;
        -m|--min)
            MIN="$2"
            shift 2
            ;;
        -M|--max)
            MAX="$2"
            shift 2
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            usage
            exit 1
            ;;
    esac
done

# Validate inputs
if ! [[ "$COUNT" =~ ^[0-9]+$ ]] || [ "$COUNT" -le 0 ]; then
    echo "Error: Count must be a positive integer"
    exit 1
fi

if ! [[ "$RUNS" =~ ^[0-9]+$ ]] || [ "$RUNS" -le 0 ]; then
    echo "Error: Runs must be a positive integer"
    exit 1
fi

if ! [[ "$MIN" =~ ^-?[0-9]+$ ]] || ! [[ "$MAX" =~ ^-?[0-9]+$ ]]; then
    echo "Error: Min and Max must be integers"
    exit 1
fi

if [ "$MIN" -ge "$MAX" ]; then
    echo "Error: Min value must be less than Max value"
    exit 1
fi

# Check if required files exist
if [ ! -f "./push_swap" ]; then
    echo "Error: push_swap executable not found in current directory"
    exit 1
fi

if [ ! -f "./checker_linux" ]; then
    echo "Error: checker_linux executable not found in current directory"
    exit 1
fi

echo "=========================================="
echo "Random Push_Swap Tester"
echo "=========================================="
echo "Configuration:"
echo "  Numbers per test: $COUNT"
echo "  Number of runs: $RUNS"
echo "  Range: [$MIN, $MAX]"
echo "=========================================="
echo ""

# Statistics tracking
total_operations=0
successful_tests=0
failed_tests=0
min_operations=999999
max_operations=0

# Run tests
for i in $(seq 1 $RUNS); do
    echo "=== Test Run $i/$RUNS ==="
    
    # Generate unique random numbers
    numbers=$(generate_unique_numbers $COUNT $MIN $MAX)
    
    echo "Generated numbers: $numbers"
    echo "----------------------------------------"
    
    # Count operations
    operations=$(./push_swap $numbers | wc -l)
    echo "Number of operations: $operations"
    
    # Check if sorting is correct
    result=$(./push_swap $numbers | ./checker_linux $numbers)
    echo "Checker result: $result"
    
    # Update statistics
    if [ "$result" = "OK" ]; then
        successful_tests=$((successful_tests + 1))
        total_operations=$((total_operations + operations))
        
        if [ $operations -lt $min_operations ]; then
            min_operations=$operations
        fi
        
        if [ $operations -gt $max_operations ]; then
            max_operations=$operations
        fi
    else
        failed_tests=$((failed_tests + 1))
        echo "❌ FAILED!"
    fi
    
    echo ""
done

# Display final statistics
echo "=========================================="
echo "Final Statistics"
echo "=========================================="
echo "Total runs: $RUNS"
echo "Successful tests: $successful_tests"
echo "Failed tests: $failed_tests"

if [ $successful_tests -gt 0 ]; then
    average_operations=$((total_operations / successful_tests))
    echo "Average operations: $average_operations"
    echo "Minimum operations: $min_operations"
    echo "Maximum operations: $max_operations"
fi

if [ $failed_tests -eq 0 ]; then
    echo "✅ All tests passed!"
else
    echo "❌ Some tests failed!"
fi
echo "=========================================="
