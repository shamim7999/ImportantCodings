#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, a[mx];

class Node
{
   public:
      int val;
      Node* Left;
      Node* Right;
      Node(int val){
         this->val = val;
         Left = NULL;
         Right = NULL;
      }
};

Node* root=NULL;

queue <Node*> q;

void dfs(Node* node)
{
   cout << node->val << " ";
   if(node->Left!=NULL)
      dfs(node->Left);
   if(node->Right!=NULL)
      dfs(node->Right);
}
void solve(int kk)
{
   cin >> n;
   vector <int> v;
   for(int i=n-1, x; i>=0; i--){
      cin >> x;
      v.push_back(x);
   }
   reverse(v.begin() , v.end());
   root = new Node(v.back());
   q.push(root);
   v.pop_back();
   int tot = 2;
   while(!q.empty() && !v.empty()){
      for(int i=0; i<tot && !v.empty(); i++){
         Node* xx = q.front();
         Node* n1 = new Node(v.back());
         xx->Left = n1;
         v.pop_back();
         Node *n2 = new Node(v.back());
         xx->Right = n2;
         v.pop_back();
         q.push(n1);
         q.push(n2);
         q.pop();
      }
      tot*=2LL;
   }
   dfs(root);
}

int32_t main()
{
   fast;
   int t = 1;
   //cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
