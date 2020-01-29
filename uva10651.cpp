#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 200005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)

void Set( ll &mask ,ll pos){mask |= ( 1 << pos) ;}
void  Reset(ll &mask,ll pos){mask = mask & ~( 1 << pos) ;}
bool check( ll mask , ll pos ){ return bool( mask & ( 1 << pos) ) ; }

ll dp[1<<14+2], n;
string s1;

ll func(ll mask)
{
    if(dp[mask]!=-1) return dp[mask];
    ll a1 = __builtin_popcount(mask);
    for(ll i=0; i<12; i++){
        if(i<10 && check(mask,i) && check(mask,i+1) && !check(mask,i+2)){
             ll temp = mask;
             Reset(temp,i), Reset(temp,i+1), Set(temp,i+2);
             a1 = min(a1,func(temp));
        }
        if(i>1 && check(mask,i) && check(mask,i-1) && !check(mask,i-2)){
              ll temp = mask;
              Reset(temp,i), Reset(temp,i-1), Set(temp,i-2);
              a1 = min(a1,func(temp));
        }
    }
    return dp[mask]=a1;
}

void solve()
{
    memo(dp,-1);
    cin >> s1;
    ll mask=0;
    for(ll i=0; i<12; i++) if(s1[i] == 'o') Set(mask,i);
    cout << func(mask) << "\n";
}
int main()
{
   fast;
   ll t,tc=0;
   cin >> t;
   while(t--) solve();

   return 0;
}
