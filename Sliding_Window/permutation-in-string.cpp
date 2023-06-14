#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool comparedInt(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        vector<int> freqs1(26, 0);
        for (char c : s1)
        {
            freqs1[c - 'a']++; // count each index value of s1
        }

        vector<int> freqs2(26, 0);
        int i = 0, j = 0;
        while (j < s2.size())
        {
            freqs2[s2[j] - 'a']++; // count each ind val of s2

            if (j - i + 1 == s1.size()) // if you windows are same return true
            {
                if (comparedInt(freqs1, freqs2))
                    return true;
            }

            if (j - i + 1 < s1.size()) // Not two windows are same then j++
                j++;
            else
            {
                freqs2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

int main()
{
    string s1 = {"ab"};
    string s2 = {"eidbaooo"};

    Solution obj;
    bool result = obj.checkInclusion(s1, s2);
    std::cout << result;
    return 0;
}

// TC- O(n1+n1)
// SC- O(1)