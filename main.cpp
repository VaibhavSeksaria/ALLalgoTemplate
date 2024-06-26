#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,a,b) for(int i=a;i<b;i++)
#define loop(x,n) for(int x=0;x<n;++x)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#include "DSU.h"
#include"Graphs.h"
#include"numbertheory.h"
#include"rangequery.h"
#include"sortingandsearching.h"
#include"stringsalgos.h"
#include"Trees.h"
#include"tries.h"
#include"LinkedList.h"
#include"PriorityQueues.h"
#include"Treeusingnodes.h"
#include"helper.h"
void precal(){
}
void solve(){
    cout<<"Enter any key to proceed"<<endl;
    char f;
    cin>>f;
    cout<<"Types of Modules:-  "<<endl<<endl;
    cout<<"1)DSUs"<<endl;
    cout<<"2)Graphs"<<endl;
    cout<<"3)LinkedList"<<endl;
    cout<<"4)NumberTheory"<<endl;
    cout<<"5)PriorityQueues"<<endl;
    cout<<"6)RangeQuery"<<endl;
    cout<<"7)SortingandSearching"<<endl;
    cout<<"8)Strings"<<endl;
    cout<<"9)Trees"<<endl;
    cout<<"10)TreesusingNodes"<<endl;
     cout<<"11)Tries"<<endl;
    cout<<"select the module number that u want to know about"<<endl;
    int h;
    cin>>h;
    moduleinfo(h);
return;
}
int main(){
fast_io;
cout<<fixed;
cout<<setprecision(10);
precal();
int t=1;
//cin>>t;
for(int i=1;i<=t;i++){
//cout<<i<<;
solve();
}
return 0;
}