// link https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>

using namespace std; 

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int countPaths(TreeNode* root, long long targetSum) {
    if (!root) return 0;

    int count = ((long long)(root->val) == targetSum) ? 1 : 0;

   
    count += countPaths(root->left, targetSum - (long long)(root->val));
    count += countPaths(root->right, targetSum - (long long)(root->val));

    return count;
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;

    int count = countPaths(root, targetSum);

    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count;
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    root->right->right = new TreeNode(11);

    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);

    root->left->right->right = new TreeNode(1);

    cout << pathSum(root, 8); 

}

