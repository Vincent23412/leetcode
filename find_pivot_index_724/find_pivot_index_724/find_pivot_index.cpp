// link https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>

using namespace std; 

int pivotIndex(vector<int>& nums)
{
	if (nums.size() == 0) return 0; 
	int rightSum = 0; 
	for (int i = 0 ; i < nums.size(); i++) 
		rightSum += nums[i]; 
	
	int leftSum = 0; 

	for (int i = 0; i < nums.size(); i++)
	{
		rightSum -= nums[i]; 

		if (leftSum == rightSum)
			return i; 

		leftSum += nums[i];

	}
	return -1; 
	
}


int main()
{
	vector<int> nums = { 1,7,3,6,5,6 };
	cout << pivotIndex(nums); 

}