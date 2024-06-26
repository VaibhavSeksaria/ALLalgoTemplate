
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool cmpk(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b)
{
    return a.second > b.second;
}
vector<int> ar[100001];
bool vis[100001];
int dis[10001];
void dfs(int node){
    vis[node] = true;
    cout << node << " ";
    for (int v : ar[node]){
        if (vis[v] == false){
            dfs(v);
        }
    }
}
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dis[src]=0;
    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        sort(ar[u].begin(),ar[u].end());
        for(int v:ar[u]){
            if(!vis[v]){
                vis[v]=true;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
vector<int>ins(10001);
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    int n=nodes;
    int e=edges;
    for(int i=0;i<n;i++){
        ar[i].clear();
        //dist[i]=0;
        vis[i]=false;
        ins[i]=0;
    }
    queue<int>q;
    for(int i=0;i<e;i++){
        int u=graph[i][0];
        int v=graph[i][1];
        ins[v]++;
        ar[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        if(ins[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(int v:ar[u]){
            ins[v]--;
            if(ins[v]==0){
                q.push(v);
            }
        }
    }
    return ans;
    
}
int kruskal(int v,int e,vector<pair<pair<int,int>,int>>edges){
    DSU dsu=DSU(v);
     sort(edges.begin(),edges.end(),cmpk);
        int ans=0;
        for(int i=0;i<e;i++){
            int a=edges[i].first.first;
            int b=edges[i].first.second;
            int w=edges[i].second;
            int ue=dsu.findroot(a);
            int re=dsu.findroot(b);
            if(ue!=re){
                ans=ans+w;
                dsu.combine(a,b);
            }
        }
        return ans;
}
vector<pair<int,int>>ar2[10001];
bool vis2[10001];
int min_dist[10001];
const int inf2=1e9;
void finddist(int v){
    set<pair<int,int>>s;
    s.insert({0,0});
    while(!s.empty()){
        int node=s.begin()->second;
        int dis=s.begin()->first;
        s.erase(s.begin());
        for(pair<int,int> e:ar2[node]){
            if(min_dist[e.first]>dis+e.second){
                min_dist[e.first]=dis+e.second;
                s.insert({min_dist[e.first],e.first});
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<min_dist[i]<<endl;
    }
}
struct edge{
    int a,b,w;
};
vector<int>awr[1001];
bool visb[1001];
//bool vis[1001];
void dfsb(int s,vector<int>&ans){
    visb[s]=true;
    ans.push_back(s);
   // cout<<s;
    for(int v:awr[s]){
        if(!visb[v]){
            visb[v]=true;
            dfsb(v,ans);
        }
    }
}
void bellmanford(){
     int v,e;
        cin>>v>>e;
        int src,des;
        cin>>src>>des;
        vector<edge>ar(e);
         for(int i=1;i<=v;i++){
            awr[i].clear();
            visb[i]=false;
        }
        for(int i=0;i<e;i++){
            int a,b,c;
            cin>>a>>b>>c;
            ar[i].a=a;
            ar[i].b=b;
            ar[i].w=c;
            awr[a].push_back(b);
        }
        long long  dist[v+1];
        for(int i=0;i<=v;i++){
            dist[i]=inf;
            //cout<<dist[i]<<endl;
        }
        vector<int>ans;
        dfsb(src,ans);
        bool cond=true;
       // cout<<u;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==des){
                cond=false;
                break;
            }
        }
        if(cond){
        cout<<1000000000<<endl;
        }
        else{
        dist[src]=0;
        for(int i=0;i<v;i++){
            int count=0;
            if(i==v-1){
                dist[des]=1e9+7;
                break;
            }
            for(int j=0;j<e;j++){
                int w=ar[j].w;
                int a=ar[j].a;
                int b=ar[j].b;
                if(dist[b]>dist[a]+w){
                    dist[b]=dist[a]+w;
                    count++;
                }
            }
            if (count == 0) {
                break;
            }
        }
        cout << dist[des] << endl;
        }
}
vector<int>arf[1001];
bool visf[1001];
const int inff=1e9;
struct edgef{
    int a,b,w;

};
void dfsf(int s,vector<int>&ans){
    visf[s]=true;
    ans.push_back(s);
   // cout<<s;
    for(int v:ar[s]){
        if(!visf[v]){
            visf[v]=true;
            dfsf(v,ans);
        }
    }
}
void floydwarshall(){
     int v,e;
        cin>>v>>e;
        vector<edgef>edges(e);
        for(int i=1;i<=v;i++){
            arf[i].clear();
            visf[i]=false;
        }
        int dp[v+1][v+1];
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                dp[i][j]=inff;
                if(i==j){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<e;i++){
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b],c);
            dp[b][a]=min(dp[b][a],c);
           // dp[b][a]=c;
            edges[i].a=a;
            edges[i].b=b;
            edges[i].w=c;
              arf[a].push_back(b);
            arf[b].push_back(a);
        }
        for(int i=1;i<=v;i++){
            for(int a=1;a<=v;a++){
                for(int b=1;b<=v;b++){
                    dp[a][b]=min(dp[a][b],(dp[a][i]+dp[i][b]));
                }
            }
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            cout<<dp[a][b]<<endl;
        }
}