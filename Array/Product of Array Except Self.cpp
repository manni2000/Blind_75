#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int arraybeforestart = 1;
        int arrayafterend = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = arraybeforestart;   // ans = 1, 1, 2, 6
            arraybeforestart *= nums[i]; // arrS = 1,2,6,24
        }

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= arrayafterend;  // ans = 6,8,12,24
            arrayafterend *= nums[i]; // 4,12,24
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    Solution obj;
    vector<int> result = obj.productExceptSelf(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}

//TC-O(n)
//SC-O(1)