#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, ans = INT_MAX;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};

    Solution obj;
    int result = obj.findMin(nums);
    std::cout << result;
    return 0;
}

// TC-O(n logn)
// SC- O(1)