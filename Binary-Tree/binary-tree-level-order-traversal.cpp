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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ans.push_back(v);
        }
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
    vector<vector<int>> result = obj.levelOrder(root);
    int k = result.size();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << endl;
    }
    return 0;
}