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

void inOrder(Node* node)
{
     if(node == NULL)
          return;
     inOrder(node->Left);
     cout << node->val << " ";
     inOrder(node->Right);
}

void solve(int kk)
{
   root = new Node(1);
   Node* l = new Node(2);
   Node* r = new Node(5);
   root->Left = l;
   root->Right = r;
   l = new Node(3);
   root->Left->Left = l;
   l = new Node(4);
   root->Left->Left->Left = l;
   r = new Node(6);
   root->Left->Left->Right = r;
   
   inOrder(root);
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
