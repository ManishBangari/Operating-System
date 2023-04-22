
/*
LOOK Disk Scheduling Algorithm
Time Complexity: O(n*log(n))
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

int main()
{

    int n, head, seektime = 0, val = -1, index = 0;

    printf("Enter the number and head of the disk\n");
    scanf("%d %d", &n, &head);

    int a[n], j = 0, s[n], next = -1, temp = head;
    ;
    printf("Enter the disk sequence\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sort the disk sequence in ascending order
    std::sort(a, a + n);

    // Find the nearest disk location to the head
    val = abs(head - a[0]);
    for (int i = 1; i < n; i++)
    {
        if (val > abs(head - a[i]))
        {
            val = abs(head - a[i]);
            index = i;
            next = a[i];
        }
    }

    // Re-order the disk sequence based on the direction of the head movement
    if (next > head)
    {
        for (int i = index; i < n; i++)
        {
            s[j] = a[i];
            j++;
        }
        for (int i = index - 1; i >= 0; i--)
        {
            s[j] = a[i];
            j++;
        }
    }
    else
    {
        for (int i = index; i >= 0; i--)
        {
            s[j] = a[i];
            j++;
        }
        for (int i = index + 1; i < n; i++)
        {
            s[j] = a[i];
            j++;
        }
    }

    // Calculate the seek time and print the seek sequence
    printf("The seek sequence is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ->", s[i]);
        seektime += abs(temp - s[i]);
        temp = s[i];
    }

    printf("\n");
    printf("The seek time is : %d\n", seektime);

    return 0;
}
