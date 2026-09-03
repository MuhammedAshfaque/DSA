#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    vector<int>rank, parent, size;
 public:
    Disjoint(int n){
        rank.resize(n+1, 0); // So that can work for 1 based indexing as well.
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
        /* Path compression is done in findUlparent function. Now when you call findUlparent for any node, it will update the parent of that node to its ultimate parent, making future calls faster. Like when you check if two nodes belong to the same component in future, at that time the path is already compressed. So O(1) time will be taken for that checking. */

        if(ulp_u == ulp_v) return; // No need to do anything.Bcz both already belong to same component
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
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    // ds.unionBySize(1,2);
    // ds.unionBySize(2,3);
    // ds.unionBySize(4,5);
    // ds.unionBySize(6,7);
    // ds.unionBySize(5,6);

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