#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    void solve(vector<int> out, vector<int> &nums, int x)
    {
        ans.push_back(out);

        for (int i = x; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            solve(out, nums, i + 1);
            out.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> out;
        solve(out, nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution obj;
    vector<vector<int>> result = obj.subsets(nums);

    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << "[" << j << "]";
        }
        cout << "," << endl;
    }

    return 0;
}

// TC- O(2^N)
// SC- O(N)