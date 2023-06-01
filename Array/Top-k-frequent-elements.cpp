#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;  // map = 1->3 , 2->2, 3->4, 4->3
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_h; // min-heap
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            min_h.push({it->second, it->first}); // In pair<int,int> -> always use arrow pointer(it->first etc..)

            if (min_h.size() > k)
            {
                min_h.pop();
            }
        }
        for (int i = 0; i < k; i++)
        {
            ans.push_back(min_h.top().second); // In iteration -> always use dot pointer(it.first etc..)
            min_h.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4};
    int k = 3;

    Solution obj;
    vector<int> result = obj.topKFrequent(nums, k);
    std::cout << "Top " << k << " Frequency elements :";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    return 0;
}

// TC- O(n logk)
// SC- O(n)