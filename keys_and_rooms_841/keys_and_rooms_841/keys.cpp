// link https://leetcode.com/problems/keys-and-rooms/solutions/5938408/easy-to-understand-solution-for-can-visit-all-rooms/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	vector<bool>visited(rooms.size(), false);
	queue<int>key; 
	visited[0] = true; 
	for (auto i : rooms[0])
		key.push(i); 
	while (!key.empty())
	{
		int newKey = key.front(); 
		key.pop(); 
		visited[newKey] = true;
		for (auto i : rooms[newKey])
			if (visited[i] == false)
				key.push(i); 
	}


	for (auto i : visited)
		if (i == false)
			return false; 

	return true; 

}

int main()
{
	vector<vector<int>> rooms = { {1}, {2}, {3}, {} }; 
	cout << canVisitAllRooms(rooms); 
}