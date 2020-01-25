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
#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
#define PI acos(-1)
#define n 1000000
ll phi[n+2], phi2[n+2];

void ETF1()
{
    for(ll i=1; i<=n; i++) phi[i]=i;
    for(ll i=2; i<=n; i+=2){
        if(phi[i] == i){
            for(ll j=i; j<=n; j+=i) phi[j] = (phi[j]*(i-1))/i;
        }
    }
    for(ll i=3; i<=n; i+=2){
        if(phi[i] == i){
            for(ll j=i; j<=n; j+=i) phi[j] = (phi[j]*(i-1))/i;
        }
    }
}
/// Another Technique
void ETF2()
{
    for (int i = 1; i <= n; i++) {
		phi2[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (phi2[i] == i) {
			phi2[i] = i - 1;
			for (int j = 2 * i; j <= n; j += i) {
				phi2[j] = (phi2[j] * (i - 1)) / i;
			}
		}
	}
}

int main()
{
   fast;
   ETF1();
   ETF2();

   for(ll i=1; i<=n; i++){
      if(phi[i] != phi2[i]){
         cout << "Miss_Match found in phi[" << i << "] = " << phi[i] << " and phi2[" << i << "] = " << phi2[i] << "\n";
         return 0;
      }
   }
   cout << "All the elements Matched.\n";

   return 0;
}
