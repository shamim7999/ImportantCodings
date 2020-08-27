#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    ll sum=0;
    cin >> n;
    int a[n+10];
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<32; i++){
        int odd=0, alter=0;
        for(int j=0; j<n; j++){
            if((1LL<<i) & a[j])
                alter^=1;
            odd+=alter;
        }
        for(int j=0; j<n; j++){
            sum+=((1LL<<i)*odd);
            if(a[j] & (1LL<<i))
                odd=(n-j-odd);
        }
    }
    cout << "All Possible XOR Sum is: " << sum << "\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
    freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;
    while(t--)
        solve();
   
    return 0;
}
