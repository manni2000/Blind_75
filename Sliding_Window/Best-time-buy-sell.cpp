#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        int Left = 0, Right = 1;

        while (Right < prices.size())
        {
            if (prices[Right] - prices[Left] < 0)
            {
                Left = Right;
                Right++;
            }
            else if (prices[Right] - prices[Left] > max)
            {
                max = prices[Right] - prices[Left];
                Right++;
            }

            else
                Right++;
        }

        return max;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution obj;

    int result = obj.maxProfit(prices);
    std::cout << result;
    return 0;
}

// TC- O(n)
// SC- O(n)