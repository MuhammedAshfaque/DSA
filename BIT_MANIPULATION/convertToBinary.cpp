#include<bits/stdc++.h>
using namespace std;
string convert2Binary(int x){
    string res = "";
    while(x > 0){
        if(x % 2 == 1) res += '1';
        else res += '0';
        x = x / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string s = convert2Binary(13);
    cout << s;
   return 0;
}