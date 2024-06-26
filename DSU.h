#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class DSU{
    vector<int>parent;
    vector<int>subtree_size;
    int N;
public:
    DSU(int n){
        N=n;
        parent=vector<int>(n+1,0);
        subtree_size=vector<int>(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
        int findroot(int u){
            while(u!=parent[u]){
                parent[u]=parent[parent[u]];
                u=parent[u];
            }
            return u;
        }
        void combine(int u,int v){
            int ru=findroot(u);
            int rv=findroot(v);
            if(subtree_size[ru]>subtree_size[rv]){
                parent[rv]=ru;
                subtree_size[ru]+=subtree_size[rv];
            }
            else{
                parent[ru]=rv;
                subtree_size[rv]+=subtree_size[ru];
            }
        }
    
};