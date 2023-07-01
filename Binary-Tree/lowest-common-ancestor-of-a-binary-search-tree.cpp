#include <iostream>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);

        while (root != nullptr)
        {
            if (root->val > large)
            {
                root = root->left;
            }
            else if (root->val < small)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
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

    TreeNode *p = new TreeNode(); // Corrected: allocate memory for p and q
    p->val = 2;
    TreeNode *q = new TreeNode();
    q->val = 7;

    Solution obj;
    TreeNode *result = obj.lowestCommonAncestor(root, p, q);
    if (result)
    {
        std::cout << result->val << ""; // Corrected: print the value of the common ancestor, not the pointer itself
    }

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    delete p;
    delete q;

    return 0;
}

// TC - O(N)
// SC - O(H)