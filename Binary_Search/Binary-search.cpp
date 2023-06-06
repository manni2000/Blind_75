#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else
        {
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return -1;
        }
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution obj;
    int result = obj.search(nums, target);
    std::cout << result;
    return 0;
}

// TC-O(n logn)
// SC-O(1)