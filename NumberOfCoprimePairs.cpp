// here (a, a), (b, a), (a, b) considering different pairs..
#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

int n, m, a[mx+5], g[mx+5], f[mx+5], cnt[mx+5];
bitset < mx+5 > b1;

void io()
{
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
}

void solve(int kk)
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i], cnt[a[i]]++;
    
    for(int i=mx; i>=1; i--){
        int tot = cnt[i];
        for(int j=i+i; j<=mx; j+=i){
            if(cnt[j]){
                tot+=cnt[j];
            }
        }
        f[i] = tot*tot;
    }
    for(int i=mx; i>=1; i--){
        g[i] = f[i];
        for(int j=i+i; j<=mx; j+=i){
            g[i]-=g[j];
        }
    }
    cout << g[1] << "\n";
}

int32_t main()
{
   io();
   fast;
   //calc();
      int t = 1;
   //seive(mx-3);
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
