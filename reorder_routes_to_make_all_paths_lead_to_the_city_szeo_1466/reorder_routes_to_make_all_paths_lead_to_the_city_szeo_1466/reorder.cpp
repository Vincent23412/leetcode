#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int minReorder(int n, vector<vector<int>>& connections) {
	set<int>addNode; 
	int count = 0;  
	if (connections[0][0] != 0 && connections[0][1] == 0)
	{
		count++;
		addNode.insert(connections[0][0]);
		addNode.insert(connections[0][1]); 
	}

	for (int i = 1; i < n - 1; i++)
	{
		int start = connections[i][0]; 
		int end = connections[i][1]; 
		if (addNode.find(start) != addNode.end())
			addNode.insert(end); 
		else
		{
			count++; 
			addNode.insert(start);
		}
		
	}
	return count; 
}

int main()
{
	int n = 6; 
	vector<vector<int>>	connections = { {0, 1},{1, 3},{2, 3},{4, 0},{4, 5} }; 
	cout << minReorder(n, connections); 
}