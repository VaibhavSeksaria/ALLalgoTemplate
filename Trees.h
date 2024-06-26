#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int Nt=int(1e4+5);
vector<int>tree[Nt];
int height[Nt];
int maxheight[Nt];
int anstree=0;
void dfstree(int s,int p){
    //cout<<s<<" ";
    for(int v:tree[s]){
        if(v!=p){
            dfstree(v,s);
        }
    }
}
void bfstree(int root){
    queue<int> q;
    q.push(root);
    vector<bool> visited(Nt,false);
    visited[root]=true;
    //cout<<"running bfs"<<endl;
    while(!q.empty()){
        int u=q.front();
        //cout<<u<<" ";
        q.pop();
        for(int v:tree[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int ans=0;
void dfsfordiameteroftree(int s,int p,int ht=0){
    //cout<<ht<<" ";
    height[s]=ht;
    maxheight[s]=ht;
    int maxin=0,secondmaxin=0;
    for(int v:tree[s]){
        if(v!=p){
            dfsfordiameteroftree(v,s,ht+1);
            maxheight[s]=max(maxheight[s],maxheight[v]);
            if(maxheight[v]>maxin){
                secondmaxin=maxin;
                maxin=maxheight[v];
            }
            else if(maxheight[v]>secondmaxin){
                secondmaxin=maxheight[v];
            }
        }
    }
    int maxdis=max(0,max(maxin-ht,maxin+secondmaxin-2*ht));
    anstree=max(maxdis,ans);
}