#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int findDuplicate(vector<int> &nums)
//     {
//         unordered_map<int, int> mp;
//         int dup;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             mp[nums[i]]++;
//         }
//         for (auto i : mp)
//         {
//             if (i.second > 1)
//             {
//                 dup = i.first;
//                 break;
//             }
//         }
//         return dup;
//     }
// };

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int dup;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                dup = nums[i];
                break;
            }
        }
        return dup;
    }
};

// TC-O(logN)
// SC-O(1)

int main()
{
    vector<int> nums = {1, 2, 4, 2, 6};

    Solution obj;
    int result = obj.findDuplicate(nums);
    std::cout << result;
    return 0;
}

// TC-O(N)
// SC-O(1)