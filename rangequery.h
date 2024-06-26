#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// segmented tree
const int Nr=1e5+5;
int a[Nr];
int st[4*Nr];
void build(int beg,int end,int pos){
    if(beg==end){
        st[pos]=a[beg];
        return;
    }
    int mid=(beg+end)/2;
    build(beg,mid,2*pos+1);
    build(mid+1,end,2*pos+2);
    st[pos]=st[2*pos+1]+st[2*pos+2];
}
void updatex(int beg,int end,int idx,int val,int pos){
    if(beg==end){
        st[pos]=val;
        return;
    }
    int mid=(beg+end)/2;
    if(idx<=mid){
        updatex(beg,mid,idx,val,2*pos+1);
    }
    else{
        updatex(mid+1,end,idx,val,2*pos+2);
    }
    st[pos]=st[2*pos+1]+st[2*pos+2];
}
int querye(int beg,int end,int ql,int qr,int pos){
    if(ql<=beg and qr>=end){
        return st[pos];
    }
    else if(ql>end || qr<beg){
        return 0;
    }
    int mid=(beg+end)/2;
    return (querye(beg,mid,ql,qr,2*pos+1)+querye(mid+1,end,ql,qr,2*pos+2));
}
//Lazy propagation
const int N2=1e5+5;
int alazy[N2];
int stlazy[4*N2];
int lazy[4*N2];
void pushdown(int pos,int beg,int end){
    if(lazy[pos]>0){
        stlazy[pos]+=(end-beg+1)*lazy[pos];
        if(beg!=end){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
}
void buildlazy(int beg,int end,int pos){
    if(beg==end){
        stlazy[pos]=alazy[beg];
        lazy[pos]=0;
        return;
    }
    int mid=(beg+end)/2;
    buildlazy(beg,mid,pos);
    buildlazy(mid+1,end,pos);
    stlazy[pos]=stlazy[2*pos+1]+stlazy[2*pos+2];
    lazy[pos]=0;
    return;
}
void updatelazy(int beg,int end,int ul,int ur,int val,int pos){
    pushdown(pos,beg,end);
    if(ul<=beg and ur>=end){
        lazy[pos]+=val;
        pushdown(pos,beg,end);
        return;
    }
    if(ul>end or ur<beg){
        return;

    }
    int mid=(beg+end)/2;
    updatelazy(beg,mid,ul,ur,val,2*pos+1);
    updatelazy(mid+1,end,ul,ur,val,2*pos+2);
    stlazy[pos]=stlazy[2*pos+1]+stlazy[2*pos+2];
}
int querylazy(int beg,int end,int ql,int qr,int pos){
    pushdown(pos,beg,end);
    if(ql<=beg and qr>=end){
        return stlazy[pos];
    }
    if(ql>end or qr<beg){
        return 0;
    }
    int mid=(beg+end)/2;
    return (querylazy(beg,mid,ql,qr,2*pos+1)+querylazy(mid+1,end,ql,qr,2*pos+2));
}
//Binary index tree fenwik tree
int bit[Nr];
int querybit(int r,int n){
    int res=0;
    for(int i=r+1;i>0;i=i-(i & -i)){
        res+=bit[i];
    }
    return res;
}
void updatebit(int k,int delta,int n){
    k+=1;
    for(;k<=n;k+=(k&-k)){
        bit[k]+=delta;
    }
}