#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long

ll b[]= {307,367};
ll mod[]= {1040160883,1066517951};
ll preBase[2][mx], Hash_s1[2][mx], Hash_s2[2][mx];
int n1, n2, st1=-1, st2=-1;
string s1, s2;
bool ss1, ss2;

void calc()
{
   preBase[0][0] = preBase[1][0] = 1;
   for(int j=0; j<2; j++){
       for(int i=1; i<mx; i++){
            preBase[j][i] = preBase[j][i-1]*b[j];
            if(preBase[j][i]>=mod[j])
                preBase[j][i]%=mod[j];
        }
   }
}

void Hashing()
{
   Hash_s1[0][n1] = Hash_s1[1][n1] = 0;
   for(int j=0; j<2; j++){
       for(int i=n1-1; i>=0; i--){
            Hash_s1[j][i] = (Hash_s1[j][i+1]*b[j] + (s1[i]-'a'+1));
            if(Hash_s1[j][i]>=mod[j])
                Hash_s1[j][i]%=mod[j];
        }
   }
   Hash_s2[0][n2] = Hash_s2[1][n2] = 0;
   for(int j=0; j<2; j++){
       for(int i=n2-1; i>=0; i--){
            Hash_s2[j][i] = (Hash_s2[j][i+1]*b[j] + (s2[i]-'a'+1));
            if(Hash_s2[j][i]>=mod[j])
                Hash_s2[j][i]%=mod[j];
        }
   }
}

pair <ll, ll> HashVal1(int st, int en)
{
    ll tem1 = Hash_s1[0][en+1], sob1 = Hash_s1[0][st];
    ll tem2 = Hash_s1[1][en+1], sob2 = Hash_s1[1][st];
    int sz = en-st+1;
    tem1*=preBase[0][sz];
    tem2*=preBase[1][sz];
    if(tem1>=mod[0])
        tem1%=mod[0];
    sob1-=tem1;
    if(sob1<0)
        sob1+=mod[0];
    

    if(tem2>=mod[1])
        tem2%=mod[1];
    sob2-=tem2;
    if(sob2<0)
        sob2+=mod[1];
    
    pair <ll, ll> p1 = {sob1, sob2};
    return p1;
    

}

pair <ll, ll> HashVal2(int st, int en)
{
    ll tem1 = Hash_s2[0][en+1], sob1 = Hash_s2[0][st];
    ll tem2 = Hash_s2[1][en+1], sob2 = Hash_s2[1][st];
    int sz = en-st+1;
    tem1*=preBase[0][sz];
    tem2*=preBase[1][sz];
    if(tem1>=mod[0])
        tem1%=mod[0];
    sob1-=tem1;
    if(sob1<0)
        sob1+=mod[0];
    

    if(tem2>=mod[1])
        tem2%=mod[1];
    sob2-=tem2;
    if(sob2<0)
        sob2+=mod[1];
    
    pair <ll, ll> p1 = {sob1, sob2};
    return p1;
    
}

int func()
{
    pair<ll,ll> a2 = HashVal2(0, n2-1);
    int sum=0, left=0, right = n2-1;
    while(right < n1){
        pair <ll,ll> a1 = HashVal1(left, right);
        sum+=(a2.first == a1.first && a2.second == a1.second);
        ++left, ++right;
    }
    return sum;

}

void solve()
{
   int n;
   cin >> s1 >> s2;
   n1 = s1.size(), n2 = s2.size();
   Hashing();
   cout << func(); /// total number of patterns(s2) in s1.
   //cout << "aklakla";


}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
  freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
  #endif 
   ios_base::sync_with_stdio(0);
   cin.tie(0);
 
   int Case=0, t=1;
   //cin >> t;
   calc();
   while(t--)
      solve();


}
