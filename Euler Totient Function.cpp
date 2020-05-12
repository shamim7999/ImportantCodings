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
#define mx 2000000
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

ll phi[mx+2];

void ETF()
{
   for(int i=2; i<=mx; i++)
        phi[i] = i;

    for(int i=2; i<=mx; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=mx; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}
int main()
{
   fast;
   ETF();
   return 0;
}
