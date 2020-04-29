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
#define con continue
#define Ones(x) __builtin_popcount(x)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

int tc=1;

void addZero(string &s1, string &s2)
{
    int a1 = s1.size(), a2 = s2.size();

    if(a1 < a2){
        int need;
        need = a2-a1;
        for(int i=0; i<need; i++){
            s1 = "0"+s1;
        }
    }
    else if(a1>a2){
        int need;
        need = a1-a2;
        for(int i=0; i<need; i++){
            s2 = "0"+s2;
        }
    }
    s1 = "0"+s1, s2 = "0"+s2;

}

string bigSum(string s1, string s2)
{
    string hh="",ans="";
    addZero(s1,s2);
    //cout << s1 << "\n" << s2 << "\n";
    bool now=0;
    int carry=0,sum=0;
    for(int i=s1.size()-1; ~i; i--){
        int s = (s1[i]-'0')+(s2[i]-'0')+carry;
        sum = s%10, carry = s/10;
        hh = hh+(char)(sum+'0');
        //cout << sum;
    }
    reverse(hh.begin(),hh.end());
    for(int i=0; hh[i]; i++){
        if(hh[i]!='0') now=1;
        if(now) ans+=hh[i];
    }
    return ans;
}


void solve(int kk)
{
    string a,b;
    cin >> a >> b;
    cout << bigSum(a,b) << "\n";
}

int main()
{
   fast;
   int kk=0;
   //cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}
