#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const ll mx = 2000005;
const ll BLK = 700;
 
#define End cout << "\n"

ll a[mx], cnt[mx], sum, ans[mx];
int n, qu;

struct hello{
    int L, R, idx;
}q[mx];

bool compare(hello a, hello b){
    if(a.L/BLK!=b.L/BLK){
        return a.L/BLK < b.L/BLK;
    }
    return a.R < b.R;
}


void add(int pos)
{
    ++cnt[a[pos]];
    ll cc = cnt[a[pos]];
    sum+=(1LL*cc*cc*a[pos]);
    --cc;
    sum-=(1LL*cc*cc*a[pos]);
}

void sub(int pos)
{
    ll cc = cnt[a[pos]];
    --cnt[a[pos]];
    sum-=(1LL*cc*cc*a[pos]);
    cc = cnt[a[pos]];
    sum+=(1LL*cc*cc*a[pos]);
}
 
void solve()
{
    cin >> n >> qu;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=qu; i++){
        int x, y;
        cin >> x >> y;
        if(x>y)
            swap(x, y);
        q[i].L = x, q[i].R = y, q[i].idx = i;
    }
    sort(q+1, q+1+qu, compare);

    int ML=0, MR=-1;

    for(int i=1; i<=qu; i++){
        int l=q[i].L;
        int r=q[i].R;
 
        while(ML>l){
            ML--;
            add(ML);
        }
 
         while(MR<r){
            MR++;
            add(MR);
        }
 
        while(ML<l){
            sub(ML);
            ML++;
        }
 
        while(MR>r){
            sub(MR);
            MR--;
        }
 
        ans[q[i].idx]=sum;
    }

    for(int i=1; i<=qu; i++)
        cout << ans[i] << "\n";
    End;


    
}
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc=1;
    while(tc--)
        solve();
    return 0;
}
