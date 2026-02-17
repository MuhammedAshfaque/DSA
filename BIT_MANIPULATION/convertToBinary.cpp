#include<bits/stdc++.h>
using namespace std;
// string convert2Binary(int x){
//     string res = "";
//     while(x > 0){
//         if(x % 2 == 1) res += '1';
//         else res += '0';
//         x = x / 2;
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }


// Input: n = 43261596    Output: 964176192

// 43261596 : 00000010100101000001111010011100
// 964176192 : 00111001011110000010100101000000

int reverseBits(int x) {
    string res = "";
    for(int i = 0; i < 32; i++){
        if(x % 2 == 1) res += '1';
        else res += '0';
        x = x / 2;
    }
    cout<< res << endl;
    // reverse(res.begin(), res.end());
    int count = 0;
    int i = res.length() - 1;
    int ans = 0;
    while(i >= 0){
        if(res[i] == '1'){
            ans += pow(2, count);
        }
        count++;
        i--;
    }
    return ans;
}

int main(){
    int s = reverseBits(14);
    cout << s;
   return 0;
}