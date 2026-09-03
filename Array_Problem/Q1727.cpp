#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<vector<int>>matrix = {{3, 1, 2}, {9, 5, 7}, {4, 6, 8}};
   for(auto &row : matrix){
      sort(row.begin(), row.end(), [](auto &a, auto &b){
            return a > b;
      });
   }
   for(auto &row : matrix){
      for(auto &col : row){
         cout << col << " ";
      }
      cout << "\n";
   }
   return 0;
}