#include <stdio.h>
#define MAX 100
int set[MAX];
int subset[MAX];
int n, targetSum;
int totalSubsets = 0;
void generateSubsets(int i, int sum, int total) {
    if (sum == targetSum) {
        printf("Subset %d: { ", ++totalSubsets);
        for (int j = 0; j < total; j++) {
            printf("%d ", subset[j]);
        }
        printf("}\n");
        return;
    }
    if (i == n || sum > targetSum) {
        return;
    }
    subset[total] = set[i];
    generateSubsets(i + 1, sum + set[i], total + 1);
    generateSubsets(i + 1, sum, total);
}
int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets with sum equal to %d:\n", targetSum);
    generateSubsets(0, 0, 0);
    if (totalSubsets == 0) {
        printf("No subsets found with the given sum.\n");
    }
    return 0;
}
