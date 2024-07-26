#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers/tasks

// Function to initialize a matrix
void initializeMatrix(int matrix[N][N], int value) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = value;
        }
    }
}

// Function to print the solution
void printSolution(int assignment[N]) {
    printf("Assigned Tasks:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i, assignment[i]);
    }
}

// Function to find the minimum cost of unassigned workers
int minCost(int costMatrix[N][N], bool assigned[N], int worker) {
    int min = INT_MAX;
    for (int task = 0; task < N; task++) {
        if (!assigned[task] && costMatrix[worker][task] < min) {
            min = costMatrix[worker][task];
        }
    }
    return min;
}

// Function to find the minimum cost of unassigned tasks
int minCostTask(int costMatrix[N][N], bool assigned[N], int task) {
    int min = INT_MAX;
    for (int worker = 0; worker < N; worker++) {
        if (!assigned[worker] && costMatrix[worker][task] < min) {
            min = costMatrix[worker][task];
        }
    }
    return min;
}

// Recursive function for branch and bound
void branchAndBoundUtil(int costMatrix[N][N], bool assigned[N], int worker, int currentCost, int* minCostSoFar, int assignment[N]) {
    if (worker == N) {
        if (currentCost < *minCostSoFar) {
            *minCostSoFar = currentCost;
            for (int i = 0; i < N; i++) {
                assignment[i] = assigned[i];
            }
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (!assigned[task]) {
            int cost = currentCost + costMatrix[worker][task] + minCost(costMatrix, assigned, worker);
            if (cost < *minCostSoFar) {
                assigned[task] = true;
                branchAndBoundUtil(costMatrix, assigned, worker + 1, cost, minCostSoFar, assignment);
                assigned[task] = false;
            }
        }
    }
}

// Branch and bound function to solve the assignment problem
void branchAndBound(int costMatrix[N][N]) {
    bool assigned[N] = { false };
    int assignment[N];
    int minCostSoFar = INT_MAX;

    branchAndBoundUtil(costMatrix, assigned, 0, 0, &minCostSoFar, assignment);

    printf("Minimum Cost: %d\n", minCostSoFar);
    printSolution(assignment);
}

int main() {
    int costMatrix[N][N];
    initializeMatrix(costMatrix, 0); // Initialize matrix with cost values

    // Input costMatrix values from the user or any other source

    branchAndBound(costMatrix);

    return 0;
}
