#include "bits/stdc++.h"
using namespace std;

#define mod 100000007
const int inf = 1e18;

int main(){
    //freopen("in.txt", "r", stdin);
	int n, lim, t;
	cin >> t;

	while(t--){
        cin >> n >> lim;

        int v[n+10], sum=0;

        for(int i=1; i<=n; i++)
            cin >> v[i], sum+=v[i];
        bitset <31> b1;

        b1[0]=1;
        for(int i=n; i>=1; i--){
            b1 |=(b1 << v[i]);
        }

        cout << b1[lim] << "\n";
        //cout << "Case " << ++ii << ": " << dp[1][lim] << "\n";

	}
	return 0;
}
