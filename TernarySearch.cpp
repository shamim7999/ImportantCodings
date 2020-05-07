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
#define mx 1005
#define mod 1000000007
#define fr first
#define cti(a) (int)(a)
#define itc(a) (char)(a)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define len(ele) (ele).size()
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
int tc=1;

int ternarySearch(int a[], int left, int right, int x)
{
    if(right-left<=0) return -1;

    int midfr = left+(right-left)/3;
    int midse = midfr+(right-left)/3;

    if(a[midfr] == x) return midfr;
    if(a[midse] == x) return midse;
    if(x < a[midfr]) return ternarySearch(a, left, midfr-1, x);
    if(x > midse) return ternarySearch(a, midse+1, right, x);
    return ternarySearch(a, midfr+1, midse-1, x);

}

void solve(int kk)
{
    int n,x;
    cin >> n;
    int a[n+5];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    cout << "Enter Key: ";
    cin >> x;

    x = ternarySearch(a, 0, n, x);

    if(x == -1) cout << "Key Doesn't exist.\n";
    else cout << "Index is: " << x << "\n";

}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   //fast;
   int kk=0;
   //cin >> tc;
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}

