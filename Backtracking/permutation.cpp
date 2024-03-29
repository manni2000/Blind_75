#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int i, vector<int> &n, vector<vector<int>> &ans)
    {
        if (i == n.size())
        {
            ans.push_back(n);
            return;
        }
        for (int j = i; j < n.size(); j++)
        {

            swap(n[i], n[j]);
            solve(i + 1, n, ans);
            swap(n[i], n[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &n)
    {
        vector<vector<int>> ans;
        solve(0, n, ans);
        return ans;
    }
};

int main()
{
    vector<int> n = {1, 2, 3};
    Solution obj;
    vector<vector<int>> result = obj.permute(n);
    for (auto i : result)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}