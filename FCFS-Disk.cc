
/*
FCFS Disk Scheduling Algorithm
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{

    int n, head, seektime = 0;

    cout << "Enter the number of disks and head: ";
    cin >> n >> head;

    int *a = new int[n];

    cout << "Enter the disk sequence: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The seek sequence is: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " -> ";
        seektime += abs(a[i] - head);
        head = a[i];
    }

    cout << endl
         << "The seektime is: " << seektime << endl;

    delete[] a;
    return 0;
}
