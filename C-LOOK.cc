
/*
C-LOOK Disk Scheduling Algorithm
Time Complexity: O(n*log(n))
Space Complexity: O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
    int n, head, seektime = 0, val = -1, index = 0;

    std::cout << "Enter the number of requests and head position: ";
    std::cin >> n >> head;

    std::vector<int> requests(n), s(n);
    std::cout << "Enter the request sequence: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> requests[i];
    }

    // Add the head position to the request sequence
    requests.push_back(head);

    // Sort the request sequence
    std::sort(requests.begin(), requests.end());

    // Find the index of the head position in the sorted sequence
    for (int i = 0; i < n + 1; i++)
    {
        if (requests[i] == head)
        {
            index = i;
            break;
        }
    }

    // Find the closest request to the head position
    val = std::abs(head - requests[index - 1]);
    if (std::abs(head - requests[index + 1]) < val)
    {
        val = std::abs(head - requests[index + 1]);
        index++;
    }

    // Arrange the requests in the order they should be serviced
    int direction = (requests[index] > head) ? 1 : -1;
    for (int i = index; i >= 0 && i < n + 1; i += direction)
    {
        s.push_back(requests[i]);
    }
    for (int i = index + direction; i >= 0 && i < n + 1; i += direction)
    {
        s.push_back(requests[i]);
    }

    // Compute the seek time
    for (int i = 1; i < n + 2; i++)
    {
        seektime += std::abs(s[i] - s[i - 1]);
    }

    // Output the seek sequence and the seek time
    std::cout << "The seek sequence is: ";
    for (int i = 0; i < n + 1; i++)
    {
        std::cout << s[i] << " -> ";
    }
    std::cout << "\n";
    std::cout << "The seek time is: " << seektime << "\n";

    return 0;
}
