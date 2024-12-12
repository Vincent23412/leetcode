#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std; 
int findCircleNum(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<bool> vis(n, false);
    int ans = 0;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (mat[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans++;
            vis[i] = true;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int nb : adj[x]) {
                    if (!vis[nb]) {
                        q.push(nb);
                        vis[nb] = true;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
	vector<vector<int>>isConnected = { {1,0,0}, {0,1,0} , {0,0,1} };
	cout << findCircleNum(isConnected); 
}