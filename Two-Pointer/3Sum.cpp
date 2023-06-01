#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // nums = {0,1,2,-1,-1,-4}
        set<vector<int>> s;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {                                            // i=0
            int low = i + 1, high = nums.size() - 1; // low =1, high = 5 (index)
            while (low < high)
            {
                if (nums[i] + nums[low] + nums[high] == 0)
                {
                    s.insert({nums[i], nums[low], nums[high]}); // s = {0,1,-1},{-1,-1,2}
                    low++;
                    high--;
                }
                else if (nums[i] + nums[low] + nums[high] < 0)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        for (auto it : s)
        {
            result.push_back(it); // res=[{{0,1,-1},{-1,-1,2}}]
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution obj;
    vector<vector<int>> result = obj.threeSum(nums);
    cout << "Triplets that sum up to zero: " << endl;
    for (auto triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC-O(n^2)
// SC-O(n)