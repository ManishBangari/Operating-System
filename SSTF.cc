
/*
SSTF(Shortest Seek Time First) Disk Scheduling Algorithm
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Calculates difference of each track number with the head position
void calculateDifference(int request[], int head, int diff[][2], int n)
{
	for (int i = 0; i < n; i++)
	{
		diff[i][0] = abs(head - request[i]);
	}
}

// Find the unaccessed track which is at minimum distance from head
int findMin(int diff[][2], int n)
{
	int index = -1;
	int minimum = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (!diff[i][1] && minimum > diff[i][0])
		{
			minimum = diff[i][0];
			index = i;
		}
	}
	return index;
}

void shortestSeekTimeFirst(int request[], int head, int n)
{
	if (n == 0)
	{
		return;
	}

	int diff[n][2] = {{0, 0}};
	int seekCount = 0;
	int seekSequence[n + 1] = {0};

	for (int i = 0; i < n; i++)
	{
		// Store the head position
		seekSequence[i] = head;

		calculateDifference(request, head, diff, n);
		int index = findMin(diff, n);
		diff[index][1] = 1;

		// Increase the total count
		seekCount += diff[index][0];

		// Accessed track is now new head
		head = request[index];
	}

	// Store the last accessed track
	seekSequence[n] = head;

	cout << "Total number of seek operations = " << seekCount << endl;
	cout << "Seek sequence is: " << endl;

	// Print the sequence
	for (int i = 0; i <= n; i++)
	{
		cout << seekSequence[i] << endl;
	}
}

int main()
{
	int n = 8;
	int proc[n] = {176, 79, 34, 60, 92, 11, 41, 114};

	shortestSeekTimeFirst(proc, 50, n);

	return 0;
}
