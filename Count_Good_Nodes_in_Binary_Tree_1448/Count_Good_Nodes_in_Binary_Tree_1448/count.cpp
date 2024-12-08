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


int findGoodNodes(TreeNode* root, int max)
{
	if (root == nullptr)
		return 0; 
	else
	{
		if (root->val >= max)
			return 1 + findGoodNodes(root->right, root->val) + findGoodNodes(root->left, root->val);
		else
			return findGoodNodes(root->right, max) + findGoodNodes(root->left, max); 
	}
}

int goodNodes(TreeNode* root) {
	int count = 1; 
	int right = findGoodNodes(root->right, root->val); 
	int left = findGoodNodes(root->left, root->val); 
	return count + right + left; 
}

int main()
{
	TreeNode* root = new TreeNode(3); 
	root->left = new TreeNode(1); 
	root->left->left = new TreeNode(3); 
	root->right = new TreeNode(4); 
	root->right->right = new TreeNode(5); 
	root->right->left = new TreeNode(1); 
	cout << goodNodes(root);
}