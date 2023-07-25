#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &candidates, int target, int curSum, vector<int> temp, int curInd)
    {
        if (curSum == target)
        {
            ans.push_back(temp);
            return;
        }
        else if (curSum > target)
        {
            return;
        }

        for (int i = curInd; i < candidates.size(); i++)
        {
            if (i != curInd && candidates[i] == candidates[i - 1]) // to avoid picking up the same combnations i.e. we don't pick same element for certain kth position of a combination
                continue;
            curSum += candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, target, curSum, temp, i + 1);
            curSum -= candidates[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp, 0);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum2(candidates, target);
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