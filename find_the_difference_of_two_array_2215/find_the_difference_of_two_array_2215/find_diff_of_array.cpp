// link https://leetcode.com/problems/find-the-difference-of-two-arrays/submissions/1469195594/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
#include <set>

using namespace std; 

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
{
	set<int>a(nums1.begin(), nums1.end());
	set<int>b(nums2.begin(), nums2.end()); 

	vector<vector<int>>ans(2, vector<int>(0, 0)); 

	for (int i: a)
	{
		if (!b.count(i))
			ans[0].push_back(i); 
	}

	for (int i: b)
		if (!a.count(i))
			ans[1].push_back(i); 

	return ans; 
}


int main()
{
	vector<int>nums1 = { 1,2,3,3 }; 
	vector<int>nums2 = { 1,1,2,2 }; 
	vector<vector<int>>ans = findDifference(nums1, nums2); 
		
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j]; 
		cout << endl; 
	}
}