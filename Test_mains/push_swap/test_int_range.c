#include "../../push_swap/push_swap.h"
#include <stdio.h>

int main(void)
{
    int count;
    int *result;
    
    // Test cases
    char *test_cases[][3] = {
        {"test_program", "2147483647", NULL},     // INT_MAX - should pass
        {"test_program", "2147483648", NULL},     // INT_MAX + 1 - should fail
        {"test_program", "-2147483648", NULL},    // INT_MIN - should pass
        {"test_program", "-2147483649", NULL},    // INT_MIN - 1 - should fail
        {"test_program", "0", NULL},              // Zero - should pass
        {"test_program", "123456789", NULL},      // Normal number - should pass
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Testing integer range validation:\n");
    printf("=====================================\n");
    
    for (int i = 0; i < num_tests; i++)
    {
        printf("Test %d: %s\n", i + 1, test_cases[i][1]);
        
        result = parse_input(2, test_cases[i], &count);
        
        if (result != NULL)
        {
            printf("  Result: PASS (value: %d)\n", result[0]);
            free(result);
        }
        else
        {
            printf("  Result: FAIL (out of range or invalid)\n");
        }
        printf("\n");
    }
    
    return 0;
}
