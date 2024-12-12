// link https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <queue>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*>q; 
    q.push(root); 
    int ans = 1; 
    int depth = 1; 
    int size, maxSum = root->val, sum; 

    while (!q.empty())
    {
        sum = 0; 
        size = q.size(); 
        while (size > 0)
        {
            TreeNode* node = q.front();
            q.pop();
            size--; 
            sum += node->val; 
            if (node->left != nullptr) q.push(node->left); 
            if (node->right != nullptr) q.push(node->right); 
        }

        if (sum > maxSum)
        {
            maxSum = sum; 
            ans = depth; 
        }
        depth++; 
    }
    return ans; 

}

int main()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->right = new TreeNode(-8);

    root->left->left = new TreeNode(7);

    cout << maxLevelSum(root); 
}