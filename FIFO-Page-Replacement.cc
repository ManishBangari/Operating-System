
/*
FIFO Page Replacement Algorithm
Time Complexity: O(nk)              //  k is number of available frames.
Space Complexity: O(n+k)
*/

#include <iostream>
using namespace std;

int n, k, pf = 0, m = -1;

// Function to search element in array
int search_element(int b[], int s)
{
    for (int i = 0; i < k; i++)
    {
        if (b[i] == s)
        {
            return 1;
        }
    }
    return -1;
}

int main()
{
    cout << "Enter the number of pages and number of frames:" << endl;
    cin >> n >> k;

    int a[n], b[k];
    cout << "Enter the page numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        b[i] = -1;
    }

    // FIFO page replacement algorithm
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            b[i] = a[i];
            pf++;
            m++;
        }
        else
        {
            int found = search_element(b, a[i]);
            if (found == -1)
            {
                m++;
                pf++;
                b[m % k] = a[i];
            }
        }

        for (int i = 0; i < k; i++)
        {
            cout << b[i] << "\t";
        }
        cout << endl;
    }

    cout << "The number of page faults: " << pf << endl;

    return 0;
}

/*
An optimized form of the above program using queue and hash tables.
Time Complexity : O(n+k)
Space complexity : O(n)


#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int n, k, pf = 0;
    cout << "Enter the number of pages and number of frames: ";
    cin >> n >> k;

    int a[n];
    cout << "Enter the page numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    queue<int> q;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        if (s.size() < k) { // Frames are not yet full
            if (s.find(a[i]) == s.end()) { // Page fault
                s.insert(a[i]);
                q.push(a[i]);
                pf++;
            }
        }
        else { // Frames are full
            if (s.find(a[i]) == s.end()) { // Page fault
                int t = q.front();
                q.pop();
                s.erase(t);
                s.insert(a[i]);
                q.push(a[i]);
                pf++;
            }
        }
    }

    cout << "The page fault is: " << pf << endl;
    return 0;
}
*/