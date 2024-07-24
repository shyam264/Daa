#include <stdio.h>
void printPascalTriangle(int n) {
    int i, j, k;
    int triangle[n][n];
    for (i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }
    for (i = 2; i < n; i++) {
        for (j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printPascalTriangle(n);
    return 0;
}