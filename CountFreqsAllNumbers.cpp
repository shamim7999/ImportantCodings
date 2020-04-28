https://codeforces.com/contest/1163/problem/B2
/// Very Important Code, counts the frequencies of numbers in given range..
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
int cnt[mx], a[mx], f[mx], mm=-1;

void solve(int kk)
{
    int n,pos=1;
    cin >> n;
    bool ok=0;
    for(int i=1; i<=n; i++){
        int color;
        cin >> color; /// 2
        cnt[f[color]]--; /// cnt[0]=-2, cnt[1]=1
        f[color]++; /// f[1]=1, f[2]=2
        cnt[f[color]]++; /// cnt[1]=1, cnt[2]=1

        mm = max(mm,f[color]);

        ok=0;

        if(cnt[1] == i) ok=1; /// sob vinno
        else if(cnt[i] == 1) ok=1; /// 1 ta number shudhu beshi
        else if(cnt[1] == 1 && cnt[mm]*mm == i-1) ok=1;
        else if(cnt[mm] == 1 && cnt[mm-1]*(mm-1) == i-mm) ok=1;

        if(ok) pos=i;
        //ok=0;

    }
    cout << pos << "\n";
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
