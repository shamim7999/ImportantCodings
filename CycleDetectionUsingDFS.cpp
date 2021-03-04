#include<bits/stdc++.h>
using namespace std;
 
#define mx 200005
#define ll long long
#define mod 1000000007

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector <int> v[mx]; 

int n, e, color[mx];

bool ok;


void dfs(int node, int par)
{
	if(color[node] == BLACK)
		return;
	color[node] = GRAY;
	for(auto it : v[node]){
		if(it == par)
			continue;
		if(color[it] == WHITE){
			color[it] = GRAY;
			dfs(it, node);
		}
		if(color[it] == GRAY)
			ok=1;
	}
	color[node] = BLACK;

}
void solve()
{
	cin >> e;
	for(int i=1, x, y; i<=e; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1, -1);

	ok ? cout << "Cycle Exists\n" : cout << "Cycle Doesn't Exist\n";
}
 
int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}
