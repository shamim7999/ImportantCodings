https://codeforces.com/contest/375/problem/D

#include<bits/stdc++.h>
using namespace std;

const int mx = 100005;
const int block = 700;
//int block;
struct hello
{
    int L, R, idx, k;
};

hello qu[mx];

int n, st[mx], en[mx], ft[2*mx], Time=1, colF[mx], ff[mx], col[mx], q;
int ans[mx], nodeF[mx], pre[mx], sq;
vector <int> v[mx];

bool comp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}

int getBlock(int id)
{
	int cc = (id/block)+(id%block!=0);
	return cc;
}

int getAns(int x, int y)
{
    int sum=0;

    int LB = getBlock(x), RB = getBlock(y);

    if(LB == RB){
    	for(int i=x; i<=y; i++)
    		sum+=ff[i];
    }
    else{
    	int yo = LB;
    	for(int i=x; i<=LB*block; i++)
    		sum+=ff[i];
    	for(int i=LB+1; i<RB; i++)
    		sum+=pre[i], yo = i;
    	for(int i=yo*block+1; i<=y; i++)
    		sum+=ff[i];
    }
    return sum;
}

void dfs(int node, int par)
{
    st[node] = Time;
    ft[Time] = node; /// Time  - - - Pos
    ++Time;

    //cout << node << " ";

    for(auto child : v[node]){
        if(child!=par)
            dfs(child, node);
    }
    en[node] = Time;
    ft[Time] = node;
    ++Time;
    //cout << node << " ";
}

void add(int pos)
{
    int node = ft[pos];
    int c = col[node];
    nodeF[node]++;

    if(nodeF[node] == 2){
        colF[c]++;
        ff[colF[c]]++;
        pre[getBlock(colF[c])]++;
        ff[colF[c]-1]--;
        pre[getBlock(colF[c]-1)]--;
    }

}

void sub(int pos)
{
    int node = ft[pos];
    int c = col[node];
    nodeF[node]--;

    if(nodeF[node] == 1){
        colF[c]--;
        ff[colF[c]]++;
        pre[getBlock(colF[c])]++;
        ff[colF[c]+1]--;
        pre[getBlock(colF[c]+1)]--;
    }
}

void solve()
{
    cin >> n >> q;
    
    for(int i=1; i<=n; i++){
        cin >> col[i];
    }
    for(int i=1, a, b; i<n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, -1);
//    block = sqrt(n);
//    if(block*block != n) block++;
    for(int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;
        qu[i].L = st[a];
        qu[i].R = en[a];
        qu[i].idx = i;
        qu[i].k = b;

    }

    //cout << ft[0] << "\n";

    sort(qu+1, qu+1+q, comp);

    int ML=0, MR=-1;

    for(int i=1; i<=q; i++){
        int l=qu[i].L;
        int r=qu[i].R;
        int K = qu[i].k;

        while(ML>l){
            ML--;
            add(ML);
        }

         while(MR<r){
            MR++;
            add(MR);
        }

        while(ML<l){
            sub(ML);
            ML++;
        }

        while(MR>r){
            sub(MR);
            MR--;
        }

        ans[qu[i].idx]=getAns(K, n);
    }

    for(int i=1; i<=q; i++)
        cout << ans[i] << "\n";

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    while(tc--)
        solve();
    return 0;
}
