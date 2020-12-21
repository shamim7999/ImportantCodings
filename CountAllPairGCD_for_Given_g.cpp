#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long

const int mod = 1e9+7;

//vector <int> prime;
int cnt[mx], b1[mx], n, a[mx], N, p1[mx], p2[mx], nn=1e9, gc;
//bitset <mx> color;

void sieve()
{
 
    int x;
    for(int i=1; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            b1[i]+=cnt[j];
        }
        p1[i] = (b1[i]*(b1[i]-1))/2;
    }
    int ans=-1, rem=1e9;
    for(int i=N; i>=1; i--){
        p2[i] = p1[i]; //6
        for(int j=i+i; j<=N; j+=i){
            p2[i]-=p2[j];
        }

       
    }

    cout << p2[2] << "\n"

    
}



void solve(int kk)
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ++cnt[a[i]];
        N = max(N, a[i]);
        

       
    }
   
    sieve();

    

    

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   //fast;
   int t=1,kk=0;
   
   //scanf("%d", &t);
   //cin >> t;
   while(++kk<=t) solve(kk);

   return 0;
}
