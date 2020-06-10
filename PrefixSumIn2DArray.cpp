#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 70
#define mod 1000000007
#define fr first
#define se second
#define End cout << "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define memo(Array, val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout << fixed << setprecision(i)
#define con continue
#define all(ele) (ele).begin(), (ele).end()
#define Ones(x) __builtin_popcount(x)
#define trailingZero(x) __builtin_ctz(x)
#define len(ele) (ele).size()

template <typename... T>
void get(T &... args)
{
    ((cin >> args), ...);
}

template <typename... T>
void Get(T &... args) { ((getline(cin, args)), ...); }

template <typename... T>
void print(T &&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos) { return (n & (1 << pos)); }
bool Set(ll n, ll pos) { return (n | (1 << pos)); }
ld LOG(ld b, ld e) { return log(b) / log(e); }
ld rad(ld x) { return ((ld)PI * x) / 180.0; }

/// Code Starts From Here.............................................///

int tc = 1, r, c;
int pre[mx][mx], a[mx][mx];

void solve(int kk)
{
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            cin >> a[i][j];
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            pre[i][j] = pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i-1][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1,y1,x2,y2;
        get(x1,y1,x2,y2);
        ++x1, ++x2, ++y1, ++y2;
        int sum = pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
        print("(", x1-1, ",", y1-1, ") to (", x2-1, ",", y2-1, ") -----> ", sum, "\n");
    }

}

int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    fast;
    int kk = 0;
    cin >> tc;
    //scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
