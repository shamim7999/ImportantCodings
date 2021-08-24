#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000077
#define mod 1000000007

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

const int block = 447;
int a[mx], cnt[mx], tc=1, ans[mx], tot;
//int block;

struct hello
{
    int L, R, idx;
}q[mx];

void io()
{
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        freopen("out.in", "w", stdout);
    #endif
}
bool cmp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}
void add(int pos)
{
    
}
void sub(int pos)
{
    
}

void solve(int kk)
{
    int n, qq;
    cin >> n >> qq;
    // block = sqrt(n);
    // if(block*block != n) block++;

    for(int i=0; i<n; i++) cin >> a[i];
    
    for(int i=0,l,r; i<qq; i++) cin >> l >> r, q[i].L = l-1, q[i].R = r-1, q[i].idx = i;
    sort(q,q+qq,cmp);

    int currSum=0;
    int l=0, r=-1;
    for(int i=0; i<qq; i++){
        //int left = q[i].L, right = q[i].R;
        while(q[i].L < l){
            add(--l);
        }
        while(q[i].L > l){
            sub(l++);
        }
        while(q[i].R < r){
            sub(r--);
        }
        while(q[i].R > r){
             add(++r);
        }
        ans[q[i].idx]=tot;
    }


    for(int i=0; i<qq; i++)
        cout << ans[i] << "\n";

}

int32_t main()
{
   io();
   fast;
   int kk=0;
   //cin >> tc;
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
