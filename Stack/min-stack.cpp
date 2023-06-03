#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            int mn = val;
            st.push({val, val});
        }
        else
        {
            int mn = min(st.top().second, val);
            st.push({val, mn});
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
        }
    }

    int top()
    {
        if (st.empty())
        {
            return 0;
        }
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    MinStack minStack;

    minStack.push(5);
    minStack.push(2);
    minStack.push(10);
    minStack.push(1);

    cout << "Top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    minStack.pop();
    cout << "After popping, top element: " << minStack.top() << endl;
    cout << "Minimum element: " << minStack.getMin() << endl;

    return 0;
}