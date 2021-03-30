#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long
#define mod 1000000007

int ar[mx];
int n,m,ii,k;

string s1;

bool ok(int pos)
{
    char cc = s1[pos];
    return (cc < '0' || cc>'9');
    //return (cc!='0' && cc!='1' && cc!='2' && cc!='3' && cc!='4' && cc!='5' && cc!='6' && cc!='7' && cc!='8' && cc!='9');
}

void solve()
{
    //string s1;

    while(cin >> s1)
    {
        vector < string > v;
        vector < int > sig;
        vector < ll > lob, hor;
        stack < pair<char, char> > ss;
        int minus = 0, sz = 0;
        n = s1.size();

        for(int i=0; s1[i]; i++)
        {

            if(s1[i] == '(')
            {
                if(i>0 && s1[i-1] == '-')
                    minus++, ss.push({'(', '-'});
                else
                    ss.push({'(', '+'});
            }
            else if(s1[i] == ')')
            {
                char cc1 = ss.top().first, cc2 = ss.top().second;
                if(cc2 == '-')
                    --minus;
                if(minus<0)
                    minus = 0;
                ss.pop();
            }

            else if(s1[i] == '/')
            {
                //string aa = s1[i-1], bb = s1[i+1], cc = "";
                string aa = "", bb = "", cc = "";
                bool paisi = 0;
                aa+=s1[i-1];
                bb+=s1[i+1];

                if(i-2>=0 && s1[i-2]>='0' && s1[i-2]<='9')
                    aa+=s1[i-2], paisi = 1;

                if(i-3>=0 && s1[i-3]>='0' && s1[i-3]<='9' && paisi)
                    aa+=s1[i-3];

                if(i+2<n && s1[i+2]>='0' && s1[i+2]<='9')
                    bb+=s1[i+2];
                reverse(aa.begin(), aa.end());
                //reverse(bb.begin(), bb.end());
                cc+=aa;
                cc+='/';
                cc+=bb;
                lob.push_back(stol(aa));
                hor.push_back(stol(bb));
                v.push_back(cc);
                //cout << minus << "\n";
                if(i-2>=0 && (s1[i-2] == '-' || ok(i-2)))
                {
                    (s1[i-2] == '-') ? sig.push_back(1) : sig.push_back(0);
                }
                else if(i-3>=0 && (s1[i-3] == '-' || ok(i-3)))
                {
                    (s1[i-3] == '-') ? sig.push_back(1) : sig.push_back(0);
                }
                else if(i-4>=0 && (s1[i-4] == '-' || ok(i-4)))
                {
                    (s1[i-4] == '-') ? sig.push_back(1) : sig.push_back(0);
                }
                else
                {
                    sig.push_back(0);
                }
                //cout << cc << " sign is: " << sig[sz] << "\n";

                if(minus%2 == 1)
                    sig[sz] = 1-sig[sz];
                //cout << cc << " sign is: " << sig[sz] << "\n";
                //return;
                ++sz;

            }
        }

        vector<pair<char,string>>a;

        for(int i=0; i<sz; i++)
        {
            char ch =  '-';
            sig[i] == 0 ? ch = '+' : ch = '-';
            // cout << ch << v[i];
            a.push_back({ch,v[i]});
        }
        //cout << "\n";
        ll ans = hor[0];
        for (int i = 1; i < sz; i++){
            ans = (((hor[i] * ans)) /
                (__gcd(hor[i], ans)));
        }
        ll pum = 0;

        for(int i=0; i<sz; i++){
            ll di = ans/hor[i];
            ll gun = di*lob[i];
            if(sig[i] == 1)
              pum-=gun;
            else
              pum+=gun;
        }
        ll gc = __gcd(abs(pum), ans);
        ans/=gc, pum/=gc;
        cout << pum << "/" << ans << "\n";

    }


}

int main()
{
    int t=1;
    //scanf("%d",&t);
    while(t--)solve();
    return 0;
}
