#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
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
bool check(int n, int pos){ return (n&(1<<pos)); }
bool Set(int n, int pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int n;
int a[mx], b[mx];
vector < int > Tree[4*mx];
map < int, int > mp;

void init(int node,int be,int en)
{
    if(be==en)
    {
        Tree[node].push_back(a[be]);
        return;
    }
    int mid=(be+en)/2;
    init(node*2,be,mid);
    init(node*2+1,mid+1,en);
    merge(Tree[node*2].begin(),Tree[node*2].end(),Tree[node*2+1].begin(),Tree[node*2+1].end(),back_inserter(Tree[node]));
}

int Query(int node, int b, int e, int i, int j, int val)
{
    //relax(node,b,e);
    if(i>e || j<b)return 0;
    if(b>=i && e<=j){
        auto f = upper_bound(Tree[node].begin(), Tree[node].end(), val)-Tree[node].begin();
        return (int)f;
    }

    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    int p=Query(left,b,mid,i,j, val);
    int q=Query(right,mid+1,e,i,j, val);
    return p+q;
}


void solve(int kk)
{
    int xx, q, col = 1;
    cin >> n >> q;
    
    vector < int > v;

    for(int i=1; i<=n; i++){
        cin >> xx;
        v.push_back(xx);
        b[i] = xx;
    }

    sort(v.begin(), v.end());

    for(auto it : v){
        mp[it] = col;
        ++col;
    }

    for(int i=1; i<=n; i++){
        a[i] = mp[b[i]]; /// Array Compression
    }

    init(1, 1, n);

    while(q--){
        int l, r;
        int x;
        cin >> l >> r >> x;
        int left = 1, right = n;
        int ans = 1;
        while(left <= right){
            int mid = (left+right)/2;
            int fre = Query(1, 1, n, l, r, mid);
            if(fre>=x){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }
        cout << v[ans-1] << "\n";
    }
}

int main()
{
   fast;
   int t=1,kk=0;
   //scanf("%d", &t);
   while(++kk<=t) solve(kk);

   return 0;
}
