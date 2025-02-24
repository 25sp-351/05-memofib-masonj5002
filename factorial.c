#include <stdio.h>

typedef long (*long_func_ptr)(int of_num);
long_func_ptr original_provider;
long_func_ptr factorial_provider;

#define NOT_PRESENT -1
long results[100] = {NOT_PRESENT};

long cache(int val) {
    for (int ix = 0; ix < 100; ix++)
        results[ix] = NOT_PRESENT;

    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val);
    return results[val];
}

// Provider
long factorial(int of_num) {
    if (of_num < 2) {
        // printf("hello from factorial!\n");
        return 1;
    }
    return of_num * (*factorial_provider)(of_num - 1);
}

int main() {
    // printf("HELLO C\n");
    int n              = 9;

    original_provider  = factorial;
    factorial_provider = cache;

    printf("factorial of %d is %ld\n", n, (*factorial_provider)(n));

    return 0;
}
