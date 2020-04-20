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

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1,sz;
vector <int> v[mx], level[mx], lv(mx,0), child(mx,0);

void bfs(int start)
{
    int sm=0;
    bitset <mx> b1;
    queue <int> q;
    q.push(start);
    level[0].pb(start);
    while(!q.empty()){

        int x = q.front();
        q.pop();

        for(auto it : v[x]){
            if(!b1[it]){
                b1[it]=1;
                q.push(it);
                lv[it]=lv[x]+1;
                level[lv[it]].pb(it);
                sz=max(sz,lv[it]);
            }
        }
        b1[x]=1;

    }
}

void solve(int kk)
{
    int n,edge;
    cin >> n >> edge;
    for(int i=0,a,b; i<edge; i++) cin >> a >> b, v[a].pb(b), v[b].pb(a);
    bfs(1);
    
    for(int i=sz-1; i>=0; i--){

        for(auto u : level[i]){
            //cout << u << " ";
            for(auto v : v[u]){
                if(lv[v]>lv[u]) child[u]+=child[v]+1;
            }
        }

    }

}

signed main()
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
