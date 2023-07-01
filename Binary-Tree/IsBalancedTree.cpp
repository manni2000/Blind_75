#include <bits/stdc++.h>
using namespace std;

// Define of binary tree
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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool solve(TreeNode *root)
    {
        if (root == NULL)
            return true;

        bool bal = abs(height(root->left) - height(root->right)) <= 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if (bal && left && right)
        {
            return true;
        }
        return false;
    }

    bool isBalanced(TreeNode *root)
    {
        return solve(root);
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
    int result = obj.isBalanced(root);
    if (result)
    {
        std::cout << result << "";
    }
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N) in the worst case, O(log N) in the best case