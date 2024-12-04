// link https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    for (int i = 0; i < n; i++) {       
        for (int j = 0; j < n; j++) {   
            bool isEqual = true;
            for (int k = 0; k < n; k++) {
                if (grid[i][k] != grid[k][j]) {  
                    isEqual = false;
                    break;
                }
            }
            if (isEqual) count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    };

    cout << equalPairs(grid) << endl;
    return 0;
}
