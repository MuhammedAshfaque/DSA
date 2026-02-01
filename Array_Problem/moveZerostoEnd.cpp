#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {3, 0, 2, 1, 0, 0, 5, 2, 9};
    int j = -1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i = j+1; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for(int it: arr){
        cout<<it<<" ";
    }

   return 0;
}
