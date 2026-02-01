#include<bits/stdc++.h>
using namespace std;

// 2^10  x = 2, n = 10
double myPow(double x, int n) {
    double ans = 1.0;
    long long N = n;   // since N is too long.. we have to take care in looping to avoid TLE.
    if (N < 0) N = -N;
    while(N > 0){
        if(N % 2 == 0){
            x = x * x; 
            N = N / 2;
        }
        else{ 
            ans = ans * x;
            N = N - 1;
        }
    }
    if(n < 0) ans = 1.0 / ans;
    return ans;
}

int main(){
    double x = 2.0;
    int n = 10;
    cout << myPow(x, n);
    return 0;
}