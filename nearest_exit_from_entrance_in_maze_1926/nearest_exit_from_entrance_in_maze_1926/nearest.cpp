#include <iostream>
#include <vector>
#include <set>
#include <queue>


using namespace std; 

struct room {
	int row; 
	int col; 
	int dis; 
};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	int m = maze.size();
	int n = maze[0].size();
	vector<vector<bool>>visited(m, vector<bool>(n, false));

	queue<room>q;
	visited[entrance[0]][entrance[1]] = true;
	q.push({ entrance[0], entrance[1], 0 });

	while (!q.empty())
	{
		auto tmp = q.front();
		int row = tmp.row;
		int col = tmp.col;
		int dis = tmp.dis;
		q.pop();

		if ((row == 0 || col == 0 || row == m - 1 || col == n - 1) && !(row == entrance[0] && col == entrance[1])) {
			return dis;
		}

		if ((row - 1 >= 0) && (maze[row - 1][col] == '.') && (!visited[row - 1][col])) {
			visited[row - 1][col] = true;
			q.push({ row - 1, col, dis + 1 });
		}
		if ((col - 1 >= 0) && (maze[row][col - 1] == '.') && (!visited[row][col - 1])) {
			visited[row][col - 1] = true;
			q.push({ row, col - 1, dis + 1 });
		}
		if ((row + 1 < m) && (maze[row + 1][col] == '.') && (!visited[row + 1][col])) {
			visited[row + 1][col] = true;
			q.push({ row + 1, col, dis + 1 });
		}
		if ((col + 1 < n) && (maze[row][col + 1] == '.') && (!visited[row][col + 1])) {
			visited[row][col + 1] = true;
			q.push({ row, col + 1, dis + 1 });
		}
	}
	return -1;
}


int main()
{
	vector<vector<char>> maze = { {'+', '+' , '.', '+'},{'.', '.', '.', '+'},{'+', '+', '+', '.'} };
	vector<int> entrance = { 1, 2 };
	cout << nearestExit(maze, entrance);
}