#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), start = 0, end = m * n - 1;

        while (start <= end)
        {
            int ind = (start + end) / 2;
            int val = matrix[ind / n][ind % n];

            if (val == target)
                return true;
            else if (val > target)
                end = ind - 1;
            else
                start = ind + 1;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    Solution obj;
    bool result = obj.searchMatrix(matrix, target);
    std::cout << result;
    return 0;
}

// TC- O(n Log(m*n))
// SC- O(1)