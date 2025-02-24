#include <stdio.h>

typedef long long (*long_func_ptr)(int of_num);
long_func_ptr original_provider;
long_func_ptr factorial_provider;

#define NOT_PRESENT -1
long long results[100] = {NOT_PRESENT};

long long cache(int val) {
    for (int ix = 0; ix < 100; ix++)
        results[ix] = NOT_PRESENT;

    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val);
    return results[val];
}

// Provider
long long factorial(int of_num) {
    if (of_num < 2) {
        return 1;
    }
    return (long long)of_num * (*factorial_provider)(of_num - 1);
}

int main() {
    for (int ix = 0; ix < 92; ix++) {
        int n              = ix;

        original_provider  = factorial;
        factorial_provider = cache;

        printf("factorial of %d is %lld\n", n, (*factorial_provider)(n));
    }

    for (int ix = 0; ix < 92; ix++) {
        int n              = ix;

        original_provider  = factorial;
        factorial_provider = cache;

        printf("factorial of %d is %lld\n", n, (*factorial_provider)(n));
    }

    return 0;
}
