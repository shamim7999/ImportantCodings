#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
 
int cur[mx], node[mx][11], tot_nodes=1;

void add_string(string &s1)
{
    int now=1;
    //cout << "Now is: " << now << "\n";
    cur[now]++;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'0';
        if(!node[now][id])
            node[now][id] = ++tot_nodes;
        now = node[now][id];
        cur[now]++;
    }
}

int search_prefix(string s1)
{
   int now=1;
   for(int i=0; s1[i]; i++){
      int id = s1[i]-'a';
      if(!node[now][id])
         return 0;
   }
   return cur[now];
}

void solve()
{
   bool ok=1;
   clr();
   string s1;
   int n;
   cin >> n;
   vector <string> v;
   for(int i=0; i<n; i++){
        cin >> s1;
        add_string(s1);
   }
   cin >> s1;
   cout << search_prefix(s1) << "\n";
}
 
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   //#ifndef ONLINE_JUDGE
   //freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
   //freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
   //#endif
   int Case=0, t=1;
   //cin >> t;
   while(t--)
      solve();
    
 
} 
