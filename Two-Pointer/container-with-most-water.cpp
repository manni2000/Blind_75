#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int max_h = 0;
        while (left < right)
        {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            max_h = max(max_h, area);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return max_h;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution obj;
    int result = obj.maxArea(height);
    std::cout << result << " ";
    return 0;
}

// TC-O(n)
// SC-O(1)