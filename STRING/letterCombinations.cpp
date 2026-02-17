#include<bits/stdc++.h>
using namespace std;class Solution {
private:
//    void solve(string n, vector<string>&curr, vector<string>&ans){
//         int digit = 0;
//         for(int i = 0; i < 2; i++){
//             digit = digit * 10 + (s[i] - '0');  
//         }
//         int lastDigit = digit % 10;
//         for(auto it : letters[lastDigit]){
//             solve(it, );
//         }
//     }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>letters{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

        // solve();
    }
};
int main(){
    string s = "23";
    vector<string>letters{
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
    cout<< letters[0][0];
   return 0;
}