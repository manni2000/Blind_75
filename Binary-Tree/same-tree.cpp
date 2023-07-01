#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr){};
};

class Solution
{
public:
    bool ans = true;

    void func(TreeNode *p, TreeNode *q)
    {
        if (p && q)
        {
            if (p->val != q->val)
            {
                ans = false;
            }

            func(p->left, q->left);
            func(p->right, q->right);
        }
        if (p != NULL && q == NULL)
        {
            ans = false;
        }

        if (p == NULL && q != NULL)
        {
            ans = false;
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        func(p, q);
        return ans;
    }
};

int main()
{
    TreeNode *p = new TreeNode();
    p->val = 4;
    p->left = new TreeNode();
    p->left->val = 2;
    p->right = new TreeNode();
    p->right->val = 7;

    TreeNode *q = new TreeNode();
    q->val = 4;
    q->left = new TreeNode();
    q->left->val = 7;
    q->right = new TreeNode();
    q->right->val = 2;

    Solution obj;
    bool result = obj.isSameTree(p, q);
    if (result)
    {
        std::cout << result << "";
    }
    return 0;
}
