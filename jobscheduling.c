#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct Job {
    char id;     // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if the job is completed
} Job;

// Comparison function to sort jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to find the maximum deadline in the job array
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    return maxDeadline;
}

// Function to schedule jobs for maximum profit
void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Find the maximum deadline to create a slot array
    int maxDeadline = findMaxDeadline(jobs, n);
    int slots[maxDeadline + 1]; // Slot array (1-based indexing)
    char jobOrder[maxDeadline + 1];

    // Initialize all slots to free (-1)
    for (int i = 1; i <= maxDeadline; i++) {
        slots[i] = -1;
    }

    int totalProfit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) { // If the slot is free
                slots[j] = i;    // Assign the job index
                jobOrder[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the job sequence
    printf("Job Sequence: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("%c ", jobOrder[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    // Example jobs
    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Schedule jobs
    jobSequencing(jobs, n);

    return 0;
}
