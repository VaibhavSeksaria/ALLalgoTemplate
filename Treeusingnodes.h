#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*> children;//<T> not necessary 
    treenode(T data){
        this->data=data;
    }
    ~treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
treenode<int>* takeinputlevelvise(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        treenode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter num of children of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childdata;
            cout<<"enter "<<i+1<<" th child of"<<front->data<<endl;
            cin>>childdata;
            treenode<int>*child=new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
    
}
treenode<int>* takeinputtree(){
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    int n;
    cout<<"enter num of children of"<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child=takeinputtree();
        root->children.push_back(child);
    }
    return root;
}
void printtree(treenode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printtree(root->children[i]);
    }
}
int numNodes(treenode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}
void printatlevelk(treenode<int>* root,int k){
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printatlevelk(root->children[i],k-1);
    }
}
void preorder(treenode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void deletetree(treenode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}