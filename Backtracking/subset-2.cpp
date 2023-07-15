#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    void solve(vector<int> &nums, vector<int> &out, int ind)
    {
        ans.push_back(out);

        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
                continue;

            out.push_back(nums[i]);
            solve(nums, out, i + 1);
            out.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> out;
        solve(nums, out, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2};
    Solution obk;
    vector<vector<int>> result = obk.subsetsWithDup(nums);
    for (auto i : result)
    {
        for (auto j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}