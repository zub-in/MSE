// Zubin Mukerjee
// Feb 23, 2024
// https://math.stackexchange.com/questions/4867910/

#include <stdio.h>

// Recursively compute 3^exponent % modulus
unsigned long long int modpow(unsigned long long int exponent, unsigned long long int modulus) {
    if (exponent == 0)
        return 1;

    unsigned long long int result;

    if ((exponent & 1) == 0) {
        unsigned long long int half_pow = modpow(exponent >> 1, modulus);
        result = (half_pow * half_pow) % modulus;
    } else {
        unsigned long long int half_pow = modpow((exponent - 1) >> 1, modulus);
        result = (3 * ((half_pow * half_pow) % modulus)) % modulus;
    }

    return result;
}

int main() {
    unsigned long long int limit;
    printf("Enter the limit: ");
    scanf("%llu", &limit);

    unsigned long long int total_solutions = 1; // Accounting for n = 0
    unsigned long long int solutions_mod_72[10] = {0}; // Adjusted size for 10 residues
    solutions_mod_72[0] = 1; // Accounting for n = 0
    int residues[10] = {0, 1, 3, 13, 25, 27, 37, 49, 51, 61}; // Modified residues array

    for (unsigned long long int n = 0; n <= limit; ++n) {
        unsigned long long int residue = n % 72;
        switch (residue) {
            case 1:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[1]++;
                    total_solutions++;
                }
                break;
            case 3:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[2]++;
                    total_solutions++;
                }
                break;
            case 13:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[3]++;
                    total_solutions++;
                }
                break;
            case 25:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[4]++;
                    total_solutions++;
                }
                break;
            case 27:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[5]++;
                    total_solutions++;
                }
                break;
            case 37:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[6]++;
                    total_solutions++;
                }
                break;
            case 49:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[7]++;
                    total_solutions++;
                }
                break;
            case 51:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[8]++;
                    total_solutions++;
                }
                break;
            case 61:
                if (modpow(n, n + 1) == n) {
                    solutions_mod_72[9]++;
                    total_solutions++;
                }
                break;
            default:
                break;
        }
    }

    printf("Number of solutions found: %llu\n", total_solutions);
    printf("Count of solutions for each residue modulo 72:\n");
    for (int i = 0; i < 10; ++i) { // Adjusted loop size
        double percentage = (double)solutions_mod_72[i] / total_solutions * 100.0;
        printf("  Residue %d: %llu (Percentage: %.2f%%)\n", residues[i], solutions_mod_72[i], percentage);
    }

    return 0;
}
