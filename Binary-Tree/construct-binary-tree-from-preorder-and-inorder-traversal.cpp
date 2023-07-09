#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int Preorder = 0;
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int is, int ie)
    {
        if (is > ie)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[Preorder]);
        Preorder++;

        int Inorder;
        for (int i = is; i <= ie; i++)
        {
            if (inorder[i] == root->val)
            {
                Inorder = i;
                break;
            }
        }
        root->left = solve(preorder, inorder, is, Inorder - 1);
        root->right = solve(preorder, inorder, Inorder + 1, ie);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *ans = solve(preorder, inorder, 0, inorder.size() - 1);
        return ans;
    }
};

// Example usage:
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    // You can now use the `root` to perform various operations on the binary tree.
    return 0;
}
