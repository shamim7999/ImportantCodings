#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    ll a[n+10], sum=0;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<32; i++){
        int one=0, zero=0;
        for(int j=0; j<n; j++){
            one+=(a[j]%2 == 1);
            zero+=(a[j]%2 == 0);
            a[j]/=2;
        }
        sum+=1LL*one*zero*(1LL<<i);
    }
    cout << "All pair XOR sum is: " << sum << "\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
    freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
   
    return 0;
}
