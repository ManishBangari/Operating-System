
/*
Banker's Algorithm
Time Complexity: O(n^2 * m)
Space Complexity: O(n * m)
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000 // maximum number of processes
#define MAX_M 1000 // maximum number of resource types

// function to check if the system is in a safe state

bool is_safe_state(int n, int m, int available[], int maximum[][MAX_M], int allocation[][MAX_M])
{
    int need[MAX_N][MAX_M], work[MAX_M], finish[MAX_N] = {0};
    int i, j, k, count = 0;

    // calculate the need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    // initialize the work vector
    for (j = 0; j < m; j++)
    {
        work[j] = available[j];
    }

    // iterate until all processes are finished or no process can be allocated
    while (count < n)
    {
        bool found = false;

        // try to find a process that can be allocated
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                bool can_allocate = true;

                // check if the process can be allocated
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        can_allocate = false;
                        break;
                    }
                }

                // allocate resources if the process can be allocated
                if (can_allocate)
                {
                    for (j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = true;
                    count++;
                    break;
                }
            }
        }

        // if no process can be allocated, the system is in an unsafe state
        if (!found)
        {
            return false;
        }
    }

    // if all processes are finished, the system is in a safe state
    return true;
}

int main()
{
    int n, m, i, j;

    // read input

    printf("Enter the number of processes and resource types: ");
    scanf("%d %d", &n, &m);

    int available[MAX_M], maximum[MAX_N][MAX_M], allocation[MAX_N][MAX_M];

    printf("Enter the number of available resources of each type: ");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &available[j]);
    }

    printf("Enter the maximum demand of each process: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the number of resources of each type currently allocated: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // check if the system is in a safe state

    if (is_safe_state(n, m, available, maximum, allocation))
    {
        printf("The system is in a safe state.\n");
    }
    else
    {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}