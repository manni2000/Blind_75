#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> ans;
    void solve(vector<int> &candidates, int target, int curSum, vector<int> temp, int i)
    {
        if (curSum > target)
        {
            return;
        }

        if (i == candidates.size())
        {
            if (curSum == target)
            {
                ans.push_back(temp);
            }
            return;
        }

        curSum += candidates[i];
        temp.push_back(candidates[i]);
        solve(candidates, target, curSum, temp, i);
        curSum -= candidates[i];
        temp.pop_back();

        solve(candidates, target, curSum, temp, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        solve(candidates, target, 0, temp, 0);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum(candidates, target);
    for (auto i : result)
    {
        for (auto j : i)
        {
            std::cout << "[" << j << "]";
        }
        cout << ",";
    }
    return 0;
}