
/*
SCAN Disk Scheduling Algorithm
Time Complexity: O(n*log(n))
Space Complexity: O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, head, seektime = 0, size = 0, val = -1, index = 0;

    cout << "Enter the number of disks, head and size of the disks: ";
    cin >> n >> head >> size;

    vector<int> a(n), s(n + 1);
    cout << "Enter the disk sequence:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    val = abs(head - a[0]);
    for (int i = 1; i < n; i++)
    {
        if (val > abs(head - a[i]))
        {
            val = abs(head - a[i]);
            index = i;
        }
    }

    int j = 0, next = -1, temp = head;
    if (a[index] > head)
    {
        for (int i = index; i < n; i++)
        {
            s[j++] = a[i];
        }
        s[j++] = size;
        for (int i = index - 1; i >= 0; i--)
        {
            s[j++] = a[i];
        }
    }
    else
    {
        for (int i = index; i >= 0; i--)
        {
            s[j++] = a[i];
        }
        s[j++] = 0;
        for (int i = index + 1; i < n; i++)
        {
            s[j++] = a[i];
        }
    }

    cout << "The seek sequence is: ";
    for (int i = 0; i < n + 1; i++)
    {
        cout << s[i] << " -> ";
        seektime += abs(temp - s[i]);
        temp = s[i];
    }
    cout << endl;
    cout << "The seek time is: " << seektime << endl;

    return 0;
}
