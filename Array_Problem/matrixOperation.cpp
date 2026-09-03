#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>matrix = {
        {3, 1, 2}, 
        {9, 5, 7}, 
        {4, 6, 8}
    };
    int m = matrix.size();
    int n = matrix[0].size();
    // for(int i = 0; i < m; i++){
    //     for (int j = 0; j < n; j++)
    //     {
    //         reverse(matrix.begin(), matrix.end());
    //     }
        
    // }
    reverse(matrix.begin() + 1, matrix.end());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
   return 0;
}