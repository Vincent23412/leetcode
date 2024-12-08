// link https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findDir(TreeNode* root, TreeNode* p, vector<int>& dir, int level)
{
    if (!root) return false; 
    if (root == p) return true; 
    dir.push_back(0); 
    if (findDir(root->left, p, dir, level + 1))
        return true; 
    dir.pop_back(); 
    dir.push_back(1);
    if (findDir(root->right, p, dir, level + 1))
        return true; 
    dir.pop_back(); 
    return false; 
    
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<int>pDir; 
    vector<int>qDir; 
    findDir(root, p, pDir, 0); 
    findDir(root, q, qDir, 0); 

    for (auto i : pDir)
        cout << i << " "; 

    int length = max(pDir.size(), qDir.size()); 
    int index = 0; 

    TreeNode* target = root; 
    while (index < pDir.size() && index < qDir.size())
    {
        if (pDir[index] == qDir[index])
        {
            if (pDir[index] == 1)
                target = target->right;
            else
                target = target->left; 
            index++; 
        }
        else
            return target; 
    }

    return target; 

}

int main()
{
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* temp = lowestCommonAncestor(root, root->left, root->left->right->right); 
    cout << temp->val; 
}
