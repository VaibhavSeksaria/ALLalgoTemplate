#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
bool cmp(pair<int,int>&a,pair<int,int>&b){
return a.second>b.second;
}
const int y=1000000;
bool prime[y+1];
void sieve(){
    for(int i=1;i<=y;i++){
        prime[i]=true;
    }
    for(int i=2;i*i<=y;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=y;j=j+i){
                prime[j]=false;
            }
        }
    }
}
void segmentedsieve(int l,int r){
     sieve();
    vector<int>pri;
    for(int i=2;i<=y;i++){
      if(prime[i]){
        pri.push_back(i);
      }
    }
    if(r<100000){
        for(int s=l;s<=r;s++){
          if(prime[s]){
            cout<<s<<" ";
          }
        }
        cout<<endl;
      }
      else{
      vector<bool>arr(r-l+1,true);
      int n=sqrt(r);
      int r1=upper_bound(pri.begin(),pri.end(),n)-pri.begin();
      r1=r1-1;
      
      for(int i=0;i<=r1;i++){
       // cout<<pri[i]<<" ";
        int p=pri[i];
        int s=(l/p)*p;
        if(l%p!=0){
          s+=p;
        }
        for(;s<=r;s+=p){
          arr[s-l]=false;
        }
      }
      for(int i=l;i<=r;i++){
        if (arr[i - l]) {
          cout << i << " ";
        }
      }
      cout << endl;
      }
}
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
int extendedgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int g=extendedgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
//output x as x*c/g and ic c%g==0 then only solution exists
int moduloinverse(int a,int m){
    int x,y,g;
    g=extendedgcd(a,m,x,y);
    if(g==1){
        x=((x%m)+m)%m;
        return x;
        //cout<<"modulo inverse of "<<a<<" = "<<x<<endl;
        //cout<<"(a+ x)%m = "<<(a * x)%m<<endl;
    }
    else{
       // cout<<"modulo inverse does not exixt "<<endl;
       return -1;
    }
}
const int N=1000000;
int phi[N+1];
void eulertotientfxn(){
    for(int i=1;i<=N;i++){
        phi[i]=i;
    }
        for(int i=2;i<=N;i++){
            if(phi[i]==i){
                for(int j=i;j<=N;j+=i){
                    phi[j]=phi[j]*(i-1);
                    phi[j]=phi[j]/i;
                }
            }
        }
    
}
ll powern(int a,int n,int p){
    ll res=1;
    while(n>0){
        if(n%2!=0){
            res=(res%p*a%p)%p;
            n--;
        }
        n=n/2;
        a=(a%p*a%p)%p;
    }
    return res;
}
unsigned long long  powInverse(int n, int p)
{
    return powern(n, p - 2, p);
}
bool check_composite(ll a,ll s,ll d,ll n){
    ll x=powern(a,d,n);
    if(x==1 || x==(n-1)){
        return false;
    }
    fr(i,1,s){
        x=(x*x)%n;
        if(x==n-1){
            return false;
        }
    }
    return true;
}
bool millerrabin(ll n){
    if(n<4){
        return(n==2 || n==3);  
    }
    // first 4 primes for 32 bit numbers
    // first 12 prims for 64 bit numbers
    ll primes[]={2,3,5,7};
    ll d=n-1;
    ll s=0;
    while(d%2==0){
        s++;
        d/=2;
    }
    for(ll a:primes){
        if(check_composite(a,s,d,n)==true){
            return false;
        }
    }
    return true;
}
void prod(ll A[2][2],ll B[2][2],int n){
    ll temp[2][2]={{0,0},{0,0}};
    fr(i,0,n){
        fr(j,0,n){
            fr(k,0,n){
                temp[i][j]=(temp[i][j]+(A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    fr(i,0,n){
        fr(j,0,n){
            A[i][j]=temp[i][j];
        }
    }
}
 
ll fib(int n){
    if(n<=2){
        return 1;
    }
    ll T[2][2]={{1,1},{1,0}};
    ll res[2][2]={{1,0},{0,1}};
    int p=n-2;
    while(p>0){
        if(p%2==1){
            prod(res,T,2);
                p--;
        }
        p=p/2;
        prod(T,T,2);
    }
    ll ans=(res[0][0]+res[0][1])%mod;
    return ans;
}
ll fact[N + 1];
ll invFact[N + 1];

ll powernum(ll a, ll n)
{
    ll res = 1;

    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }

    return res;
}

ll C(int n, int r)
{
    if (n < r)
        return 0;

    ll result = (fact[n] * invFact[r]) % mod;
    return (result * invFact[n - r]) % mod;
}

void init()
{
    fact[0] = invFact[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = powernum(fact[i], mod - 2);
    }
}