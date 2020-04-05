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
#define mx 100005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

int Find(int a[])
{
    int torto = a[0];
    int hare = a[0];
    while(1){
        torto = a[torto];
        hare = a[a[hare]];
        if(torto == hare) break;
    }
    int ptr1 = a[0];
    int ptr2 = torto;
    while(ptr1!=ptr2){
        ptr1 = a[ptr1];
        ptr2 = a[ptr2];
    }
    return ptr1;
}

void solve(int kk)
{
   int n;
   cin >> n;
   int a[n+10];
   for(int i=0; i<n; i++) cin >> a[i];

   cout << Find(a);

}

int main()
{
    fast;

   int kk=0;

  // scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
