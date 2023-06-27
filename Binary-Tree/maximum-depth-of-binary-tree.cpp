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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxDepthleft = maxDepth(root->left);
        int maxDepthright = maxDepth(root->right);
        return max(maxDepthleft, maxDepthright) + 1;
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
    int result = obj.maxDepth(root);
    if (result)
    {
        std::cout << result << "";
    }
    return 0;
}

// TC- O(n)
// SC- O(h)