#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        solveParenthesis("(", 1, 0, result, n);
        return result;
    }

    void solveParenthesis(string ch, int open, int close, vector<string> &result, int n)
    {
        if (ch.size() == 2 * n)
        {
            result.push_back(ch);
            return;
        }
        if (open < n)
            solveParenthesis(ch + "(", open + 1, close, result, n);
        if (close < open)
            solveParenthesis(ch + ")", open, close + 1, result, n);
    }
};

int main()
{
    int n = 3; // Set the desired number of pairs of parentheses
    Solution solution;

    vector<string> result = solution.generateParenthesis(n);

    cout << "Generated Parentheses Combinations:" << endl;
    for (auto str : result)
    {
        cout << str << endl;
    }

    return 0;
}

// TC-O(2^n)
// SC-O(2^n)