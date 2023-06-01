#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(height[i - 1], left[i - 1]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i + 1], right[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int waterLevel = min(left[i], right[i]);
            if (waterLevel >= height[i])
                ans += waterLevel - height[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution obj;
    int result = obj.trap(height);

    std::cout << result << " ";
    return 0;
}

// TC-O(n)
// SC-O(1)