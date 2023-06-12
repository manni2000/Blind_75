#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int count[256] = {0};
        int i = 0;   // start index
        int j = 0;   // start index
        int ans = 0; // store final value
        int n = s.size();

        while (j < n) // True
        {
            count[s[j]]++; // count -> a=2,b=1,c=1,

            while (count[s[j]] > 1) // false,false,false,true
            {
                count[s[i]]--; // count -> a=1
                i++;           // i=1
            }
            ans = max(ans, j - i + 1); // ans = 1, 2 , 3
            j++;                       // j=1,2
        }
        return ans;
    }
};

int main()
{
    string s = {"abcabcbb"};
    Solution obj;
    int result = obj.lengthOfLongestSubstring(s);
    std::cout << result;
    return 0;
}

// TC- O(n)
// SC- O(1)