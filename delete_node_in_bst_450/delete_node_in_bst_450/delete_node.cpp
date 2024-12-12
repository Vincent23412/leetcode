#include <iostream>
#include <vector>

using namespace std; 

struct TreeNode{
 int val;
 TreeNode* left;
 TreeNode* right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* deleteNode(TreeNode*& root, int key) {
	if (root)
	{
		if (root->val > key) root->left = deleteNode(root->left, key); 
		else if (root->val < key) root->right = deleteNode(root->right, key); 
		else
		{
			if (!root->right && !root->left) return NULL; 
			if (!root->right || !root->left)
			{
				if (root->left)
					return root->left;
				else
					return root->right; 
			}
			TreeNode* temp = root->left; 
			while (temp->right != NULL)
				temp = temp->right; 
			root->val = temp->val; 
			root->left = deleteNode(root->left, temp->val); 
		}
	}
	return root; 
}


void inorder(TreeNode* root)
{
	if (root != nullptr)
	{
		inorder(root->left); 
		cout << root->val << " "; 
		inorder(root->right); 
	}
}

int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);

	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);

	root->right->right = new TreeNode(7);

	TreeNode* temp = deleteNode(root, 3); 
	inorder(temp); 
}





