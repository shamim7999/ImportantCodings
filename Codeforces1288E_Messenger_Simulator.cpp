#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define nthElement(x) find_by_order(x)
#define lessThan(x) order_of_key(x)
#define dd double
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1000077
#define mod 1000000007
#define fr first
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

template<typename... T> void get(T&... args) { ((cin >> args), ...); }

template<typename... T> void Get(T&... args){ ((getline(cin,args)), ...); }

template<typename... T> void print(T&&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
ld rad(ld x) {  return ((ld)PI*x)/180.0; }

/// Code Starts From Here.............................................///

int tc=1, n, m, x, q, block;
int a[mx], cnt[mx], last[mx];
int mini[mx], maxi[mx];

struct hello
{
    int val, L, R;
    hello(int _val, int _L, int _R){
        val = _val, L = _L, R = _R;
    }
};
vector <hello> v;

bool cmp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}

void func()
{
    block = sqrt(n);
    if(block*block != n) block++;

    sort(all(v), cmp);
    q = len(v);
    int ans=0;
    int currL=0, currR=0;
    for(int i=0; i<q; i++){
        int left = v[i].L, right = v[i].R;
        int vv = v[i].val;
        while(currL<left){
            cnt[a[currL]]--;
            if(cnt[a[currL]] == 0) ans--;
            currL++;
        }
        while(currL>left){
            cnt[a[currL-1]]++;
            if(cnt[a[currL-1]] == 1) ans++;
            currL--;
        }
        while(currR<=right){
              cnt[a[currR]]++;
              if(cnt[a[currR]] == 1) ans++;
              currR++;
        }
        while(currR>right+1){
             cnt[a[currR-1]]--;
             if(cnt[a[currR-1]] == 0)  ans--;
             currR--;
        }
        maxi[vv] = max(maxi[vv],1+ans);
    }
}

void solve(int kk)
{
    get(n,m);

    for(int i=1; i<=n; i++)
        maxi[i]=i, mini[i]=i;

    ordered_set os;

    memo(last, -1);

    for(int i=0; i<m; i++){

        get(a[i]), x = a[i];

        os.insert(a[i]);

        if(last[x] == -1){
            int ss = len(os)-os.lessThan(x+1);
            maxi[x] = max(maxi[x], x+ss);
        }
        else{
            v.pb({x, last[x]+1, i-1});
        }
        last[x]=i;
        mini[x]=1;

    }
    for(int i=1; i<=n; i++){
        if(last[i] == -1){
            int ss = len(os)-os.lessThan(i+1);
            maxi[i] = max(maxi[i], i+ss);
        }
        else{
            v.pb({i, last[i]+1, m-1});
        }
    }
    func();
    for(int i=1; i<=n; i++)
        print(mini[i], ' ', maxi[i], '\n');

}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   fast;
   int kk=0;
   //cin >> tc;
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
