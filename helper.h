#include<bits/stdc++.h>
using namespace std;
void moduleinfo(int h){
if(h<1 or h>11){
        cout<<"Invalid no try again"<<endl;
        return;
    }
    if(h==1){
        cout<<"DSU Module:-"<<endl;
        cout<<"1) define DSU syntax---  DSU(int size)"<<endl;
        cout<<"2) finding parent of that element syntax--- findroot(int element)"<<endl;
        cout<<"3) Combining two non connected elements syntax-- combine(int a1,int a2)"<<endl;        
    }
    if(h==2){
        cout<<"Graphs Module:-"<<endl;
        cout<<"1) do dfs transversal syntax--- dfs(int node)";
        cout<<"2) do bfs transversal syntax--- bfs(int src)";
        cout<<"3) do topological sort syntax--- topologicalSort(vector<vector<int>> &graph, int edges, int nodes)";
        cout<<"4) get minimum spanning tree using kruskal algo syntax--- kruskal(int v,int e,vector<pair<pair<int,int>,int>>edges)";
        cout<<"5) find the distance between the given node and every other node syntax--- finddist(int v)";
        cout<<"6) do bellmanford algo syntax--- bellmanford()";
        cout<<"7) do floydwarshall algo syntax--- floydwarshall()";
    }
     if(h==3){
        cout<<"LinkedList Module:-"<<endl;
        cout<<"1) define node syntax:-- -node(int data)"<<endl;
        cout<<"2) print the entire linkedlist syntax:--- print(node *head)"<<endl;
        cout<<"3) insert a node at a particular position syntax:--- insertnode(node *head,int i,int data)"<<endl;
        cout<<"4) take input untill data entered is -1 syntax--- takeinput()"<<endl;
    }
     if(h==4){
        cout<<"NumberTheory Module:-"<<endl;
        cout<<"1) store all prime numbers syntax--- sieve()"<<endl;
        cout<<"2) large prime numbers between a particular range syntax--- segmentedsieve(int l,int r)"<<endl;
        cout<<"3) gcd of long type nums syntax--- gcd(int a,int b)"<<endl;
        cout<<"4) extended gcd syntax--- extendedgcd(int a,int b,int &x,int &y)"<<endl;
        cout<<"5) modular inverse of a number synax--- moduloinverse(int a,int m)"<<endl;
        cout<<"6) eulertotientfunction syntax--- eulertotientfxn()"<<endl;
        cout<<"7) power of two large numbers syntax--- powern(int a,int n,int p)"<<endl;
        cout<<"8)power of inverse of a number syntax--- powInverse(int n, int p)"<<endl;
        cout<<"9) check wheather two numbers are composite or not syntax--- check_composite(ll a,ll s,ll d,ll n)"<<endl;
        cout<<"10) find wheather the given numbers is prime or not using millerrabin algo syntax--- millerrabin(ll n)"<<endl;
        cout<<"11) Product of two matrices syntax--- prod(ll A[2][2],ll B[2][2],int n)"<<endl;
        cout<<"12) print's the nth value of a recursive relation syntax--- fib(int n)"<<endl;
        cout<<"13)combination of two numbers nCr syntax--- C(int n,int r)"<<endl;
    }
     if(h==5){
        cout<<"PriorityQueues Module:-"<<endl;
        cout<<"1) check wheather the list is empty or not syntax--- isempty()"<<endl;
        cout<<"2) size of current list syntax--- getsize()"<<endl;
        cout<<"3) get the minimum element of the list syntax--- getmin()"<<endl;
        cout<<"4) Insert anew element syntax--- insert(int data)"<<endl;
        cout<<"5) remove the topmost element syntax-- remove()"<<endl;
    }
     if(h==6){
        cout<<"RangeQuery Module:-"<<endl;
        cout<<"Segmented Tree Functions:-"<<endl;
        cout<<"1) build the segmented tree array syntax--- build(int beg,int end,int pos)"<<endl;
        cout<<"2) update a particular value syntax--- updatex(int beg,int end,int idx,int val,int pos)"<<endl;
        cout<<"3) get the value in a particular range syntax--- querye(int beg,int end,int ql,int qr,int pos)"<<endl;
        cout<<"Lazy Propagation functions"<<endl;
        cout<<"1) build the segmented tree array syntax--- buildlazt(int beg,int end,int pos)"<<endl;
        cout<<"2) update a particular range of values syntax--- updatelazy(int beg,int end,int ul,int ur,int val,int pos)"<<endl;
        cout<<"3) get the value in a particular range syntax--- querye(int beg,int end,int ql,int qr,int pos)"<<endl;
        cout<<"Finwik Tree"<<endl;
        cout<<"1) get the value upto to r index syntax--- querybit(int r,int n)"<<endl;
        cout<<"2) update a particular value syntax--- updatebit(int k,int delta,int n)"<<endl;
    }
     if(h==7){
        cout<<"SortingandSearching Module:-"<<endl;
        cout<<"1) searching a element in sorted list syntax--- binary(vector<int> &arr, int target)"<<endl;
        cout<<"2) getting lowerbound syntax--- lowerbound(vector<int> &arr,int target)"<<endl;
        cout<<"3) getting upperbound syntax--- upperbound(vector<int>&arr, int target)"<<endl;
        cout<<"4) do quick sort syntax--- quicksort(vector<int> &a, int left, int right)"<<endl;
        cout<<"5) do merge sort syntax--- MergeSort(vector<int> &a, int start, int end)"<<endl;
        cout<<"6) do counting sort syntax--- countingsort(vector<int>&a,int n) "<<endl;
    }
     if(h==8){
        cout<<"Strings Module:-"<<endl;
        cout<<"1) get each occourance of pattern in the given text using Rabincarb algo syntax--- stringMatch(string text, string pattern)"<<endl;
        cout<<"2) getting lps array syntax--- createLPS(string pattern)"<<endl;
        cout<<"3) get each occourance of pattern in the given text using KMPalgo syntax--- KMPalgo(string text,string pattern)"<<endl;
        cout<<"4) get Z-array syntax--- calZarray(string s)"<<endl;
        cout<<"5) get manchers array syntax--- manchers(string s)"<<endl;
        cout<<"6) get suffix array syntax--- buildSuffixArray(string txt, int n)"<<endl;
        cout<<"7) get lcp array using kasai algo syntax--- kasai(string txt, vector<int> suffixArr)"<<endl;
    }
     if(h==9){
        cout<<"Trees Module:-"<<endl;
        cout<<"1) dfs syntax--- dfstree(int s,int p)"<<endl;
        cout<<"2) bfs syntax--- bfstree(int root)"<<endl;
        cout<<"3) get the diameter of the tree syntax--- dfsfordiameteroftree(int s,int p,int ht=0)"<<endl;
    }
     if(h==10){
        cout<<"TreesusingNodes Module:-"<<endl;
        cout<<"1) define tree syntax--- treenode(T data) T-datatype"<<endl;
        cout<<"2) taking input levelvise syntax--- takeinputlevelvise() "<<endl;
        cout<<"3) print the entire tree syntax--- printtree(treenode<int>* root)"<<endl;
        cout<<"4) number of nodes in a tree syntax--- numNodes(treenode<int>* root)"<<endl;
        cout<<"5) print level k of the tree syntax--- printatlevelk(treenode<int>* root,int k)"<<endl;
        cout<<"6) preorder transvel of the tree syntax--- preorder(treenode<int>* root)"<<endl;
        cout<<"7) delete the tree syntax--- deletetree(treenode<int>* root)"<<endl;
    }
     if(h==11){
        cout<<"Tries Module:-"<<endl;
        cout<<"1) define trie structure syntax--- Node *root=new Node()"<<endl;
        cout<<"2) insert a string syntax--- insert(Node *curr,string &s,int index) "<<endl;
        cout<<"3) search for a particular string syntax--- search(Node *curr,string &s,int index)"<<endl;
        cout<<"4) remove a particular element syntax--- remove(Node *curr,string &s,int index)"<<endl;
    }
}