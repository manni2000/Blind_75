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
    void tree(TreeNode *root)
    {
        if (!root)
            return;
        swap(root->left, root->right);
        tree(root->left);
        tree(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        tree(root);
        return root;
    }
};

int main()
{
    // Example usage
    // Create a sample tree
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

    // Create a solution object
    Solution solution;

    // Invert the tree
    TreeNode *invertedTree = solution.invertTree(root);

    // Print the inverted tree (preorder traversal)
    cout << "Inverted Tree (Preorder Traversal): ";
    stack<TreeNode *> s;
    s.push(invertedTree);
    while (!s.empty())
    {
        TreeNode *node = s.top();
        s.pop();
        if (node)
        {
            cout << node->val << " ";
            s.push(node->right);
            s.push(node->left);
        }
    }
    cout << endl;

    // Clean up the tree (free memory)
    // Code to delete the tree nodes...

    return 0;
}

// TC- O(N)
// SC- O(N)
