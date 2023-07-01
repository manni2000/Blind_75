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
    bool isIdentical(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
        return (s->val == t->val) && isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (t == nullptr)
            return true;
        if (s == nullptr)
            return false;

        if (isIdentical(s, t))
            return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main()
{
    TreeNode *s = new TreeNode();
    s->val = 4;
    s->left = new TreeNode();
    s->left->val = 2;
    s->right = new TreeNode();
    s->right->val = 7;

    TreeNode *t = new TreeNode();
    t->val = 4;
    t->left = new TreeNode();
    t->left->val = 2;
    t->right = new TreeNode();
    t->right->val = 7;

    Solution obj;
    bool result = obj.isSubtree(s, t);
    std::cout << result << "";
    return 0;
}
