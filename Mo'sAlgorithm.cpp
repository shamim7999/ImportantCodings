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

int block, a[mx];

struct hello
{
    int L, R, idx;
}q[mx];

bool cmp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}

void solve()
{
    int n;
    cin >> n;
    block = sqrt(n);
    if(block*block != n) block++;

    for(int i=0; i<n; i++) cin >> a[i];
    int qq;
    cin >> qq;
    for(int i=0,l,r; i<qq; i++) cin >> l >> r, q[i].L = l, q[i].R = r, q[i].idx = i;
    sort(q,q+qq,cmp);

    int currSum=0;
    int currL=0, currR=0;
    for(int i=0; i<qq; i++){
        int left = q[i].L, right = q[i].R;
        while(currL<left)   currSum-=a[currL], currL++;
        while(currL>left)   currSum+=a[currL-1], currL--;
        while(currR<=right)  currSum+=a[currR], currR++;
        while(currR>right+1) currSum-=a[currR-1], currR--;

        cout << currSum << "\n";
    }


    //for(int i=0; i<qq; i++) cout << q[i].L << " " << q[i].R << "\n";

}

int main()
{
    fast;
	int t;
	t=1;
	while(t--) solve();
	return 0;
}
