
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
ll power(ll a, ll n){
    ll res = 1;
    while (n){
        if (n & 1)
            res = (res * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }
 return res;
}
//RabinCarb algo
vector<int> stringMatch(string text, string pattern) {
	vector<int>ans;
	int n=text.size();
	int m=pattern.size();
	ll f=0;
	int k=0;
	for(int i=m-1;i>=0;i--){
		f=(f%mod + (power(31,i)%mod*(pattern[k]-'a'+1ll)%mod)%mod)%mod;
		k++;
	}
	ll g=0;
	int y=0;
	for(int i=m-1;i>=0;i--){
		g=(g%mod + (power(31,i)%mod*(text[y]-'a'+1ll)%mod)%mod)%mod;
		y++;
	}
	if(g==f){
		ans.push_back(1);
	}
	int d=0;
	for(int i=m;i<n;i++){
	ll 	fir=((text[d]-'a'+1)%mod*power(31,m-1ll)%mod)%mod;
	d++;
		g=(g-fir+mod)%mod;
		g=(g%mod*31%mod)%mod;
		g=(g%mod + (text[i]-'a'+1ll)%mod)%mod;
		if(g==f){
			ans.push_back(d+1);
		}
	}
	return ans;
}
//kmp
vector<int>createLPS(string pattern){
    int pn=pattern.size();
    int j=0;
   vector<int>lps(pn);
   lps[0]=0;
    for(int i=1;i<pn;i++){
        while(j>0 and pattern[i]!=pattern[j]){
            j=lps[j-1];
        }
        if(pattern[i]==pattern[j]){
            j++;
        }
        lps[i]=j;
    }
    return lps;
}
vector<int> KMPalgo(string text,string pattern){
    int tn=text.size();
    int pn=pattern.size();
    vector<int>lps=createLPS(pattern);
    int i=0,j=0;
    vector<int>index;
    while(i<tn){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j==pn){
            index.pb(i-pn);
        }
    }
    return index;
}
vector<int> calZarray(string s){
    int n=s.size();
    vector<int>z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n and s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
	string newstring=p;
    newstring+=char('#');
    newstring+=s;
    int newlen=newstring.size();
    vector<int>Zarray=calZarray(newstring);
	int ans=0;
    for(int i=0;i<newlen;i++){
        if(Zarray[i]==m){
           ans++;
        }
    }
	return ans;
}
string modify(string s){
    string newString="";
    for(int i=0;i<s.size();i++){
        newString+=(char)('#');
        newString+=(char)(s[i]);
    }
    newString+=(char)('#');
    return newString;
}
vector<int> manchers(string s){
    int n = s.size();
    vector<int>arr(n);
    
    int center=0,r=0;
    for(int i=0;i<s.size()-1;i++){
        int other = 2*center -i;
        if(i<r) arr[i] = min(arr[other],r-i);
        while(i-arr[i]-1>=0 && i+arr[i]+1<n && s[i+arr[i]+1] == s[i-arr[i]-1]) arr[i]++;
        if(i+arr[i]>r){
            center=i;
            r=i+arr[i];
        }
    }
    return arr;
}
struct suffix
{
    int index;  // To store original index
    int rank[2]; // To store ranks and next
                 // rank pair
};
 
// A comparison function used by sort() to compare
// two suffixes. Compares two pairs, returns 1 if
// first pair is smaller
int cmps(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])?
           (a.rank[1] < b.rank[1] ?1: 0):
           (a.rank[0] < b.rank[0] ?1: 0);
}
 
// This is the main function that takes a string
// 'txt' of size n as an argument, builds and return
// the suffix array for the given string
vector<int> buildSuffixArray(string txt, int n)
{
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];
 
    // Store suffixes and their indexes in an array
    // of structures. The structure is needed to sort
    // the suffixes alphabetically and maintain their
    // old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = (int)txt[i];
        suffixes[i].rank[1] = ((i+1) < n)?
                              (int)txt[i + 1]: -1;
    }
 
    // Sort the suffixes using the comparison function
    // defined above.
    sort(suffixes, suffixes+n, cmps);
 
    // At his point, all suffixes are sorted according
    // to first 2 characters.  Let us sort suffixes
    // according to first 4 characters, then first
    // 8 and so on
    int ind[n];  // This array is needed to get the
                 // index in suffixes[] from original
                 // index. This mapping is needed to get
                 // next suffix.
    for (int k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and index values to first suffix
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        // Assigning rank to suffixes
        for (int i = 1; i < n; i++)
        {
            // If first rank and next ranks are same as
            // that of previous suffix in array, assign
            // the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank &&
               suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
 
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        // Assign next rank to every suffix
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                      suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        // Sort the suffixes according to first k characters
        sort(suffixes, suffixes+n, cmps);
    }
 
    // Store indexes of all sorted suffixes in the suffix
    // array
    vector<int>suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);
 
    // Return the suffix array
    return  suffixArr;
}
 
/* To construct and return LCP */
vector<int> kasai(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();
 
    // To store LCP array
    vector<int> lcp(n, 0);
 
    // An auxiliary array to store inverse of suffix array
    // elements. For example if suffixArr[0] is 5, the
    // invSuff[5] would store 0.  This is used to get next
    // suffix string from suffix array.
    vector<int> invSuff(n, 0);
 
    // Fill values in invSuff[]
    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;
 
    // Initialize length of previous LCP
    int k = 0;
 
    // Process all suffixes one by one starting from
    // first suffix in txt[]
    for (int i=0; i<n; i++)
    {
        /* If the current suffix is at n-1, then we don’t
           have next substring to consider. So lcp is not
           defined for this substring, we put zero. */
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
 
        /* j contains index of the next substring to
           be considered  to compare with the present
           substring, i.e., next string in suffix array */
        int j = suffixArr[invSuff[i]+1];
 
        // Directly start matching from k'th index as
        // at-least k-1 characters will match
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
 
        lcp[invSuff[i]] = k; // lcp for the present suffix.
 
        // Deleting the starting character from the string.
        if (k>0)
            k--;
    }
 
    // return the constructed lcp array
    return lcp;
}