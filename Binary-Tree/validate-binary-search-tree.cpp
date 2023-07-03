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
    bool solve(TreeNode *root, long long &prev)
    {
        if (!root)
        {
            return true;
        }

        // In-order traversal: left -> root -> right
        if (!solve(root->left, prev))
        {
            return false;
        }

        // Check if the current node's value is greater than the previous node's value
        if (root->val <= prev)
        {
            return false;
        }

        // Update the previous node's value to the current node's value
        prev = root->val;

        return solve(root->right, prev);
    }

    bool isValidBST(TreeNode *root)
    {
        long long prev = LLONG_MIN; // Using long long to handle edge cases with INT_MIN
        return solve(root, prev);
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
    int result = obj.isValidBST(root);
    if (result)
    {
        std::cout << result << "";
    }
    return 0;
}

// TC- O(N)
// SC- O(N)