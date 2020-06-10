#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 103
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

int tc = 1, r, c, b;
int pre[mx][mx][mx], a[mx][mx][mx];

void solve(int kk)
{
    cin >> r >> c >> b;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<b; k++)
                cin >> a[i][j][k];
        }
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            for(int k=0; k<b; k++){
                pre[i][j][k] = a[i-1][j-1][k-1]+pre[i-1][j][k]+pre[i][j-1][k]+pre[i][j][k-1]-pre[i-1][j-1][k]-pre[i-1][j][k-1]-pre[i][j-1][k-1]+pre[i-1][j-1][k-1];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1,y1,z1,x2,y2,z2;
        get(x1,y1,z1,x2,y2,z2);
        ++x1,++y1,++z1,++x2,++y2,++z2;
        int sum = -pre[x1-1][y2][z2]-pre[x2][y1-1][z2]-pre[x2][y2][z1-1]-pre[x1-1][y1-1][z1-1]+pre[x1-1][y1-1][z2]+pre[x1-1][y2][z1-1]+pre[x2][y1-1][z1-1]+pre[x2][y2][z2];
        printf("(%d, %d, %d) to (%d, %d, %d) ----> %d\n", x1,y1,z1,x2,y2,z2,sum);
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
