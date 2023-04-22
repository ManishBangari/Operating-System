
/*
C-SCAN Disk Scheduling Algorithm
Time Complexity: O(n*log(n))
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, head, size, seek_time = 0;
    cout << "Enter the number of requests, current head position, and disk size: ";
    cin >> n >> head >> size;

    vector<int> requests(n), sequence;

    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
        cin >> requests[i];

    // sort the requests in ascending order
    sort(requests.begin(), requests.end());

    // find the index of the first request greater than or equal to the head
    int index = lower_bound(requests.begin(), requests.end(), head) - requests.begin();

    // add the requests to the sequence in the order that the head will visit them
    for (int i = index; i < n; i++)
        sequence.push_back(requests[i]);

    sequence.push_back(size - 1); // add the end of the disk
    sequence.push_back(0);        // add the beginning of the disk

    for (int i = 0; i < index; i++)
        sequence.push_back(requests[i]);

    // calculate the seek time by iterating through the sequence
    for (int i = 1; i < (int)sequence.size(); i++)
        seek_time += abs(sequence[i] - sequence[i - 1]);

    // print the seek sequence and seek time
    cout << "The seek sequence is: ";
    for (int i = 0; i < (int)sequence.size(); i++)
        cout << sequence[i] << " -> ";

    cout << "\nThe seek time is: " << seek_time << endl;

    return 0;
}