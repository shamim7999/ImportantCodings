#include<bits/stdc++.h>
using namespace std;
 
#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx], par[mx], sz[mx];

void make_set(int num)
{
	par[num] = num;
	sz[num] = 1;
}
int find_set(int aa)
{
	if(par[aa] == aa)
		return aa;
	return par[aa] = find_set(par[aa]);
}
void union_set(int aa, int bb)
{
	int A = aa, B = bb;
	aa = find_set(aa);
	bb = find_set(bb);
	if(aa == bb){
		cout << A << " and " << B << " is already in the same set.\n";
		return; 
	}
	if(sz[aa]<sz[bb])
		swap(aa, bb);
	par[bb] = aa;
	sz[aa]+=sz[bb];
	cout << A << " " << B << " is merged\n";
}
void solve(int kk)
{
    cin >> n;
    for(int i=1; i<=n; i++){
    	make_set(i);
    }
    for(int i=0; i<n; i++){
    	int x, y;
    	cin >> x >> y;
    	union_set(x, y);
    }

}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
