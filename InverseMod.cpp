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
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define PI acos(-1)

int inv[mx];
void invCalc()
{
    inv[1] = 1;
    for(int i=2; i<=n; i++){
        inv[i] = (-(mod/i) * inv[mod%i]) % mod;
        inv[i]+=mod;
    }
}

ll bigmod(ll e, ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}
ll ModInverse(ll x){return bigmod(x,mod-2)%mod;}

int main()
{
    ll a,b;
    cin >> a >> b;
    cout << bigmod(a,b) << "\n";

    return 0;
}
