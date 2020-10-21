#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000009
#define ll long long
 
ll mod = 1000000007;
ll b = 37;
ll preBase[mx], Hash_s1[mx], Hash_s2[mx];
int n1, n2;
string s1, s2;
 
void clr()
{
    for(int i=0; i<=max(n1, n2); i++)
        Hash_s1[i] = Hash_s2[i] = 0;
}
 
void calc()
{
   preBase[0] = 1;
   for(int i=1; i<mx; i++){
        preBase[i] = preBase[i-1]*b;
        if(preBase[i]>=mod)
            preBase[i]%=mod;
   }
}
 
void Hashing()
{
   Hash_s1[n1] = 0;
   for(int i=n1-1; i>=0; i--){
        Hash_s1[i] = (Hash_s1[i+1]*b + (s1[i]-'a'+1));
        if(Hash_s1[i]>=mod)
            Hash_s1[i]%=mod;
   }
   Hash_s2[n2] = 0;
   for(int i=n2-1; i>=0; i--){
        Hash_s2[i] = (Hash_s2[i+1]*b + (s2[i]-'a'+1));
        if(Hash_s2[i]>=mod)
            Hash_s2[i]%=mod;
   }
}
 
ll HashVal1(int st, int en)
{
    ll tem = Hash_s1[en+1], sob = Hash_s1[st];
    int sz = en-st+1;
    tem*=preBase[sz];
    if(tem>=mod)
        tem%=mod;
    sob-=tem;
    if(sob<0)
        sob+=mod;
 
    return sob;
}
 
void solve(int Case)
{
   cin >> s1 >> s2;
   n1 = s1.size(), n2 = s2.size();
   Hashing();
   ll nn = Hash_s2[0];
   int left=0, right=n2-1;
   ll sum=0;
   while(right < n1){
      ll aa = HashVal1(left, right);
      sum+=(aa == nn);
      ++left, ++right;
   }
   printf("Case %d: %lld\n", Case, sum);
   //cout << sum << "\n";
}
 
int main()
{
   //ios_base::sync_with_stdio(0);
   //cin.tie(0);
//   #ifndef ONLINE_JUDGE
//   freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
//   freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
//   #endif
   int Case=0, t=1;
   //cin >> t;
   scanf("%d", &t);
   calc();
   while(++Case<=t)
      solve(Case);
 
 
}
