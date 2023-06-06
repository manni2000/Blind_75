#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(); // Number of elements in the heights vector
        stack<int> s;           // Stack to store indices of heights

        long long ans = 0; // Variable to store the maximum area

        for (int i = 0; i <= n; i++)
        {
            // While stack is not empty and current height is smaller than the height at the top of the stack
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                long long h = heights[s.top()]; // Height of the rectangle
                s.pop();                        // Remove the index from the stack

                int w; // Width of the rectangle
                if (s.empty())
                    w = i; // If stack is empty, width is from index 0 to i
                else
                {
                    w = i - s.top() - 1; // Width is from the index at the top of the stack to i
                }

                ans = max(ans, w * h); // Calculate the area and update the maximum area
            }
            s.push(i); // Push the current index to the stack
        }

        return ans; // Return the maximum area
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution obj;
    int result = obj.largestRectangleArea(heights);
    std::cout << result;
    return 0;
}

// TC-O(n)
// SC-O(n)