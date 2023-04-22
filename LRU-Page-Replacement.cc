
/*
FIFO Page Replacement Algorithm
Time Complexity: O(n*k)              //  k is number of available frames.
Space Complexity: O(k)
*/

#include <iostream>
using namespace std;

int n, k, pf = 0, m = -1;

// Function to search for a page in the frame
int search_element(int b[], int s, int index[])
{
    for (int i = 0; i < k; i++)
    {
        if (b[i] == s)
        {               // If the page is found
            index[i]++; // Increment its index
            return 1;   // Return found
        }
    }
    return -1; // Return not found
}

// Function to add a page to the frame
void add_page(int a, int index[], int b[])
{
    int mini = 1e7, flag = 0;
    for (int i = 0; i < k; i++)
    {
        if (index[i] <= mini)
        {
            mini = index[i];
            if (i == m % k)
            {                 // If the page to be replaced is the last page in the frame
                b[i] = a;     // Replace the page
                index[i] = 1; // Reset its index
                flag = 1;     // Set the flag
            }
        }
    }
    if (flag == 0)
    {                     // If the flag is not set
        b[m % k] = a;     // Replace the page
        index[m % k] = 1; // Reset its index
    }
    return;
}

int main()
{
    cout << "Enter the number of pages and number of frames: ";
    cin >> n >> k;

    int a[n], b[k], index[k];
    cout << "Enter the page sequence: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        b[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            b[i] = a[i];
            pf++;
            m++;
            index[i] = 1;
        }
        else
        {
            int found = search_element(b, a[i], index);
            if (found == -1)
            {
                pf++;
                m++;
                add_page(a[i], index, b);
            }
        }

        // Print the frame after every page replacement
        for (int i = 0; i < k; i++)
        {
            cout << b[i] << "\t";
        }
        cout << endl;
    }
    cout << "The page fault is: " << pf << endl;
    return 0;
}
