// Zubin Mukerjee
// Feb 22, 2024
// https://math.stackexchange.com/questions/4867910/

#include <stdio.h>

// Function to (inefficiently) compute modular exponentiation (base^exp % mod)
// This can be sped up using repeated squaring
long long int modPow(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Compute 1 + 3^n % (n+1) for n = 0 to [limit], keep track of counts
    const int limit = 2000000000;
    int zeroCount = 0; // The total number of solutions
    int mod72Count = 0; // The number of solutions that are 27 mod 72
    printf("Values of n for which 1 + 3^n \\equiv 0 (mod n+1):\n");
    for (int n = 0; n <= limit; ++n) {
        long long int result = (1 + modPow(3, n, n + 1)) % (n + 1);
        if (result == 0) {
            zeroCount++;
            if (n % 72 == 27) {
                mod72Count++;
            }
            printf("%d\n", n);
        }
    }
    printf("Number of solutions: %d\n", zeroCount);
    printf("Number of solutions that are 27 mod 72: %d\n", mod72Count);
    
    // Calculate the percentage of solutions that are 27 mod 72
    if (zeroCount == 0) {
        printf("Percentage of solutions that are 27 mod 72: 0%%\n");
    } else {
        double percentage = (double)mod72Count / zeroCount * 100;
        printf("Percentage of solutions that are 27 mod 72: %.2f%%\n", percentage);
    }

    return 0;
}
