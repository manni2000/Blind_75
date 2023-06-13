#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char, int> mp;
        int ans = -1;
        while (j < n) // T,T,T,T,T,T,T,F
        {
            mp[s[j]]++;                 // mp -> A=4,B=3
            maxi = max(maxi, mp[s[j]]); // maxi = 1,2,1,3,2,3,4
            if ((j - i + 1) - maxi > k)
            {               // 2-0+1-2>k(F), 3-0+1-1>k(T), 4-1+1-3>k(F), 5-1+1-2>k(T), 6-2+1-3>k(T), 7-3+1-4>k(F)
                mp[s[i]]--; // m=p -> A(pop),A(pop),B(pop),A(pop)
                i++;        // i=1,2,3,4
            }
            ans = max(ans, (j - i + 1)); // ans = 2-0+1=3, 3-1+1=3, 4-1+1=4, 5-2+1=4, 6-3+1=4, 7-4+1=4
            j++;                         // j=1,2,3,4,5,6,7 end
        }
        return ans; // 4
    }
};

int main()
{
    string s = {"ABAB"};
    int k = 2;

    Solution obj;
    int result = obj.characterReplacement(s, k);
    std::cout << result;
    return 0;
}

// TC- O(N)
// SC- O(1)