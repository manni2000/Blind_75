#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if (x == "+")
                {
                    st.push(op2 + op1);
                }
                else if (x == "-")
                {
                    st.push(op2 - op1);
                }
                else if (x == "*")
                {
                    st.push(op2 * op1);
                }
                else if (x == "/")
                {
                    st.push(op2 / op1);
                }
            }
            else
            {
                int num = stoi(x);
                st.push(num);
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    Solution obj;
    int result = obj.evalRPN(tokens);
    std::cout << result;
    return 0;
}

//TC-O(n)
//SC-O(n)