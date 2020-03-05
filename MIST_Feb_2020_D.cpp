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

bitset <mx> cc;
int en[mx],st[mx],cnt;
vector <int> g[mx], v;

void clr()
{
    for(int i=0; i<mx; i++) g[i].clear(), en[i]=0, st[i]=0;
    v.clear(), cc.reset(), cnt=0;
}

bool cmp(int a, int b)
{
    return en[a]<en[b];
}

void dfs(int u, int p)
{
    st[u]=cnt++;
    for(auto it : g[u]){
        if(it!=p){
            v.pb(it);
            dfs(it,u);
        }
    }
    en[u]=cnt++;
}

void solve(int kk)
{
    int node;
    cin >> node;
    for(int i=1,x,y; i<node; i++) cin >> x >> y, g[x].pb(y), g[y].pb(x);
    for(int i=1; i<=node; i++) sort(g[i].begin(),g[i].end());
    dfs(1,0);

    v.pb(1);
    sort(v.begin(),v.end(), cmp);

    set < pair <int,int> > s;

    for(int i=1; i<=node; i++) s.insert({en[v[i-1]],v[i-1]});

    int q;

    cout << "Case " << kk << ":\n";
    cin >> q;
    while(q--){
        int choice,Node,pani;
        cin >> choice >> Node;
        if(choice == 1){
            cin >> pani;

            if(cc[Node]) continue;

            pair <int,int> p = {st[Node],Node};
            auto it = s.upper_bound(p);
            auto it2 = it;
            while(pani--){

                auto h = it;
                cc[h->se] = 1;
                it++;
                if(h->se == Node) break;
            }
            s.erase(it2,it);

        }
        else cout << cc[Node] << "\n";
    }
    clr();
}

int main()
{
   fast;
   int t=1,kk=0;
   cin >> t;
   while(++kk<=t) solve(kk);

   return 0;
}
//Thanks to ----> https://github.com/AshrafulHaqueToni
