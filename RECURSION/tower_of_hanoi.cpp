#include<bits/stdc++.h>
using namespace std;
int solve(int n, int from, int to, int aux) {
    if (n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    int count = solve(n - 1, from, aux, to);

    count++; // Move the nth disk from 'from' to 'to'

    count += solve(n - 1, aux, to, from);
    return count;
}
int main(){
    int n = 3;
    cout << "Minimum number of moves: " << solve(n, 1, 2, 3) << "\n";
    return 0;
}