#include <stdio.h>

// Function to recursively find factors of a number
void findFactors(int n, int divisor) {
    if (divisor > n / 2) {
        // Base case: divisor exceeds half of n
        printf("%d ", n);
        return;
    }
    if (n % divisor == 0) {
        printf("%d ", divisor);
        findFactors(n / divisor, divisor);
    } else {
        findFactors(n, divisor + 1);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    findFactors(n, 2); // Start with divisor 2
    printf("\n");

    return 0;
}
