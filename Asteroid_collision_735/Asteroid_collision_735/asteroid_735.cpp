// link https://leetcode.com/problems/asteroid-collision/submissions/1470806055/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int>st; 
	for (int a : asteroids)
	{
		if (a > 0) st.push(a); 
		else
		{
			while (!st.empty() && st.top() > 0 && st.top() < -a) {
				st.pop(); 
			}
			if (st.empty() || st.top() < 0) {
				st.push(a); 
			}
			if (!st.empty() && st.top() == -a) {
				st.pop(); 
			}
		}
	}
	int i = st.size() - 1;
	vector<int>ans(st.size(), 0);

	for (i; i >= 0; i--)
	{
		ans[i] = st.top(); 
		st.pop(); 
	}

	return ans;

}

int main()
{
	vector<int>asteroids = { 5,10,-5 }; 
	vector<int> ans = asteroidCollision(asteroids); 
	for (auto i : ans)
		cout << i << " "; 

}