#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int i = 1, j = *max_element(piles.begin(), piles.end()), ans;

        while (i <= j)
        {
            int mid = (i + j) / 2;
            long long int cnt = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                if (piles[i] < mid)
                {
                    cnt++;
                }
                else
                {
                    cnt += ((piles[i] / mid) + (piles[i] % mid != 0));
                }
            }
            if (cnt > h)
            {
                i = mid + 1;
            }
            else
                j = mid - 1;
        }
        return i;
    }
};

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;
    int result = obj.minEatingSpeed(piles, h);
    std::cout << result;
    return 0;
}

// TC- O(n logn)
// SC- O(1)