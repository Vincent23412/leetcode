// link https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
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


vector<int> rightSideView(TreeNode* root) {
    vector<int>right;
    if (root == nullptr) return right; 
    queue<pair<TreeNode*, int>>queue; 
    queue.emplace(root, 0); 
    right.push_back(root->val); 
    while (!queue.empty())
    {
        auto temp = queue.front();
        queue.pop(); 
        
        TreeNode* node = temp.first;
        int level = temp.second;
        if (level > right.size() - 1)
            right.push_back(node->val);
        if (node->right != nullptr) queue.emplace(node->right, level + 1);
        if (node->left != nullptr) queue.emplace(node->left, level + 1);
         
    }
    return right; 
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(4);

    vector<int>temp = rightSideView(root);
    for (auto i : temp)
        cout << i << " "; 

    
    return 0;
}