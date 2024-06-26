#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
typedef struct Node
{
    Node *next[26];
    int cnt;
    bool isending ;
    Node(){
        cnt=0;
        isending=false;
        fr(i,0,26){
            next[i]=NULL;
        }
    }
}Node;
void insert(Node *curr,string &s,int index){
    curr->cnt+=1;
    if(index==s.length()){
        curr->isending=true;
        return;
    }
    int nextindex=int(s[index]-'a');
    if(curr->next[nextindex]==NULL){
        curr->next[nextindex]=new Node();
    }
    insert(curr->next[nextindex],s,index+1);
}
int search(Node *curr,string &s,int index){
    if(curr==NULL){
        return 0;
    }
    if(index==s.length()){
        return curr->cnt;
    }
    int nextindex=int(s[index]-'a');
    return search(curr->next[nextindex],s,index+1);
}
Node* remove(Node *curr,string &s,int index){
    curr->cnt-=1;
    if(curr->cnt==0){
        delete curr;
        return NULL;
    }
    if(index==s.length()){
        curr->isending=false;
        return curr;
    }
    int nextindex=int(s[index]-'a');
    curr->next[nextindex]=remove(curr->next[nextindex],s,index+1);
    return curr;
}