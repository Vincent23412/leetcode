#include <iostream>
#include <vector>


using namespace std; 

int bfs(vector<vector<int>>& grid, vector<int>& start, int orangeCount, int time)
{
	if (orangeCount == 0)
		return time;

	

}


int orangesRotting(vector<vector<int>>& grid)
{
	int startRow = -1; 
	int startCol = -1; 
	int orangeCount = 0; 

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
				orangeCount++; 
			if (grid[i][j] == 2)
			{
				startRow = i; 
				startCol = j; 
			}
		}
	}

	return bfs(grid, { startRow, startCol }, orangeCount, 0); 
}

int main()
{
	vector<vector<int>> grid = { {2, 1, 1},{1, 1, 0},{0, 1, 1} }; 
	cout << orangesRotting(grid); 
}