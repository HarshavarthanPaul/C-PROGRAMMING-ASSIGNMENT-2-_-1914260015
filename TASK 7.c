#include <stdio.h>
#include <stdlib.h>

void sieve(unsigned long N) {
    unsigned char *is_prime = malloc(N + 1);
    for (unsigned long i = 0; i <= N; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (unsigned long p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (unsigned long i = p * p; i <= N; i += p)
                is_prime[i] = 0;
        }
    }
    printf("Primes up to %lu computed using Sieve.\n", N);
    free(is_prime);
}

int main(void) {
    sieve(1000000);
    return 0;
}
