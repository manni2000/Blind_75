#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                return {left + 1, right + 1};
            }
            else if (numbers[left] + numbers[right] < target)
                left++;

            else
                right--;
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> numbers = {2, 7, 11};
    int target = 13;

    Solution obj;
    vector<int> result = obj.twoSum(numbers, target);

    if (result[0] == -1 && result[1] == -1)
    {
        std::cout << "No two numbers found that add up to the target." << endl;
    }
    else
    {
        std::cout << "Indices of the two numbers that add up to the target: " << result[0] << ", " << result[1] << endl;
    }
    return 0;
}

// TC-O(n)
// SC-O(1)