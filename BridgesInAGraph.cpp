#include <bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1000077
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

int tc = 1;
int Time, in[mx], low[mx];
bitset <mx> vis;
vector <int> v[mx]; 

void dfs(int node, int par)
{
    vis[node]=1;
    in[node] = low[node] = Time;
    ++Time;
    for(auto child : v[node]){
        if(child == par) con;
        if(vis[child]) low[node] = min(low[node], in[child]);
        else{
            dfs(child, node);
            if(low[child]>in[node])
                print(child, " to ", node, " there is a Bridge.\n");
            low[node]=min(low[node], low[child]);
        }
    }
}


void solve(int kk)
{
    int node,edge,a,b;
    get(node,edge);
    while(edge--)
        get(a,b), v[a].pb(b), v[b].pb(a);
    dfs(1, 0);

}

int main()
{
    //freopen("text.txt", "r", stdin);
    //freopen("text2.txt", "w", stdout);
    //fast;
    int kk = 0;
    //cin >> tc;
    //scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}
