#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int>rank, parent, size;
 public:
    Disjoint(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUlparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] =  findUlparent(parent[node]);
    }
    // Take union of two node
    void unionByRank(int u, int v){
        int ulp_u = findUlparent(u);
        int ulp_v = findUlparent(v);
        if(ulp_u == ulp_v) return; //No need to do anything. Bcz both already belong to same component
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    // Here size indicates the size of the component.. kind of number of vertices
    void unionBySize(int u, int v){
        int ulp_u = findUlparent(u);
        int ulp_v = findUlparent(v);
        if(ulp_u == ulp_v) return; //No need to do anything. Bcz both already belong to same component
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    Disjoint ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUlparent(3) == ds.findUlparent(7)){
        cout << "same" << endl;
    }
    else cout << "Not same" << endl;
    ds.unionBySize(3,7);
    if(ds.findUlparent(3) == ds.findUlparent(7)){
        cout << "same" << endl;
    }
    else cout << "Not same" << endl;
   return 0;
}