#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
	vector<int>connected(n + 1, false); 
	connected[0] = 1; 
	unordered_map<int, vector<int>>outgoing;
	unordered_map<int, vector<int>>ingoing; 
	for (auto p : connections)
	{
		outgoing[p[0]].push_back(p[1]); 
		ingoing[p[1]].push_back(p[0]); 
	}
	queue<int>q; 
	q.push(0);

	int ans = 0; 

	
	while (!q.empty())
	{
		int u = q.front(); 
		q.pop(); 
		for (auto v : outgoing[u])
		{
			if (!connected[v])
			{
				ans++; 
				connected[v] = 1; 
				q.push(v);
			}
		}

		for (auto z : ingoing[u])
		{
			if (!connected[z])
			{
				connected[z] = 1; 
				q.push(z); 
			}
		}
	}

	return ans; 

}

int main()
{
	int n = 3;
	vector<vector<int>>	connections = { {1,2}, {2,0} };
	cout << minReorder(n, connections);
}