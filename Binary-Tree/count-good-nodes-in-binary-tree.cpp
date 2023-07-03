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
    int ans = 0;
    void solve(TreeNode *root, int cur)
    {
        if (root == NULL)
            return;

        if (root->val >= cur)
        {
            cur = root->val;
            ans++;
        }
        solve(root->left, cur);
        solve(root->right, cur);
    }

    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        solve(root, root->val);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode();
    root->val = 4;
    root->left = new TreeNode();
    root->left->val = 2;
    root->right = new TreeNode();
    root->right->val = 7;
    root->left->left = new TreeNode();
    root->left->left->val = 1;
    root->left->right = new TreeNode();
    root->left->right->val = 3;
    root->right->left = new TreeNode();
    root->right->left->val = 6;
    root->right->right = new TreeNode();
    root->right->right->val = 9;

    Solution obj;
    int result = obj.goodNodes(root);
    if (result)
    {
        std::cout << result << "";
    }
    return 0;
}