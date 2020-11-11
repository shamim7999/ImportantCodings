#include<bits/stdc++.h>
using namespace std;

#define mx 105
#define int long long

int dp1[31][2][100][2];

string Left, Right;


int func(int pos, int isSmall, int tot,  int start, string &s1)
{
    if(pos>=20)
        return tot;
    int &ret = dp1[pos][isSmall][tot][start];
    if(ret!=-1)
        return ret;
    int en=s1[pos]-48, a1=0, zero=0;

    if(isSmall)
        en = 9;

    for(int i=0; i<=en; i++){
        a1+=func(pos+1, isSmall | (i<en), tot+(i == 0 && start), start | (i>0), s1);
    }
    return ret = a1;

}

void add(string &s1)
{
    int need = 20-s1.size();
    for(int i=1; i<=need; i++)
        s1 = '0'+s1;
}

void clr()
{
    memset(dp1, -1, sizeof dp1);
   // memset(dp2, -1, sizeof dp2);
}

void solve()
{

    int a, b;
    cin >> a >> b;
    Left = to_string(a-1);
    Right = to_string(b);
    add(Left);
    add(Right);

    clr();
    a = func(0,0,0,0, Left);
    clr();
    b = func(0,0,0,0,Right);
    cout << b-a << "\n";


    //cout << b << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
