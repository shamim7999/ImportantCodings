#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx];

const int N = 10000000;
int lp[N+1];
vector<int> pr;

void Linear_Sieve()
{
  for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back (i);
      }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
          lp[i * pr[j]] = pr[j];
  }

}

void func(int x)
{
    while(x>1){
        int xx = lp[x]; // lp[3] = 2
        cout << xx << " ";
        x/=xx;
    }
}

void solve(int kk)
{
    cin >> n;
    func(n);

}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  Linear_Sieve();
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
