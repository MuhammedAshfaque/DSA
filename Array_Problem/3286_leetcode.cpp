#include<bits/stdc++.h>
using namespace std;
bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int>drow = {+1, -1, 0, 0};
    vector<int>dcol = {0, 0, -1, +1};

    queue<pair<pair<int, int>, int>>q;
    q.push({{0, 0}, health});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it.first.first;
        int col = it.first.second;
        int power = it.second;
        if(power <= 0) continue;
        if(row == m-1 && col == n-1 && power > 0){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                int newHealth = power - grid[nrow][ncol];
                if(nrow == m-1 && ncol == n-1 && newHealth > 0){
                    return true;
                }
                if(newHealth > 0){
                    q.push({{nrow, ncol}, newHealth});
                }
                
            }
        }
    }
    return false;
}
int main(){
    // grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
vector<vector<int>> grid = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };
    int health = 3;
    if(findSafeWalk(grid, health)){
        cout << "Safe walk is possible." << endl;
    } else {
        cout << "Safe walk is not possible." << endl;
    }
   return 0;
}