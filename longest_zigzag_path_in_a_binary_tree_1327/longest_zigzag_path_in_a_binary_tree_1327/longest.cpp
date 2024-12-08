#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


int helper(TreeNode* root, bool isLeft, int length)
{
    if (!root) return 0; 

    int left = helper(root->left, 1, isLeft ? 1 : length + 1);
    int right = helper(root->right, 0, !isLeft ? 1 : length + 1);

    return max(length, max(left, right));
         
}

int longestZigZag(TreeNode* root) {
    if (!root) return 0; 
    int right = helper(root->right, 0, 1); 
    int left = helper(root->left, 1, 1); 

    return max(left, right);
}

int main()
{
    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);

    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);

    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);

    cout << longestZigZag(root); 
}
