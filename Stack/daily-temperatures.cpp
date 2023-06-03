#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size() > 0 && temperatures[st.top()] < temperatures[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    Solution obj;
    vector<int> result = obj.dailyTemperatures(temperatures);
    for (auto res : result)
    {
        std::cout << res << " ";
    }
    return 0;
}

// TC-O(n)
// SC-O(n)