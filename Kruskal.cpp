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
ld LOG(ld e, ld b){ return log(e)/log(b); }
vector < pair<int, pair<int,int> > > graph;
vector < pair<int,int> > g[mx];
int parent[mx];
int n;

int Findparent(int x)
{
    return (x==parent[x])?x:(parent[x]=Findparent(parent[x]));
}

void Union(int x,int y)
{
    parent[Findparent(x)]=parent[Findparent(y)];
}

void kruskal()
{
    //cout<<0;
    sort(graph.begin(),graph.end());
    for(int i=0;i<graph.size();i++)
    {
      int u=graph[i].second.first;
      int v=graph[i].second.second;
      int w=graph[i].first;

      if(Findparent(u)!=Findparent(v)){
        g[u].pb({v,w});
        g[v].pb({u,w});
        cout<<"("<<u<<","<<v<<","<<w<<")";
        Union(u,v);
      }
    }
}

void ini()
{
    for(int i=1; i<=n; i++) parent[i]=i;
}

void solve()
{
    int edge;
    cin >> n >> edge;
    for(int i=0,n1,n2,w; i<edge; i++) cin >> n1 >> n2 >> w, graph.pb({w,{n1,n2}});
    ini();
    kruskal();
}


int main()
{
   fast;
   int t=1;
   //cin >> t;
   while(t--) solve();

   return 0;
}

