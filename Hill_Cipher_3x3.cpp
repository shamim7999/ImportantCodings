#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k[10][10], aT[10][10], adj[10][10];

int norm(int x)
{
    if(x>=26)
        x%=26;
    if(x<0)
        x+=26;
    return x;
}

int multiplicative_inverse(int r1, int r2)
{
    int t1 = 0, t2 = 1, s1 = 1, s2 = 0, s, t, q, r;
    if(r1<r2)
      swap(r1, r2);
    while(r2){
        r = r1%r2;
        q = r1/r2;
        s = s1 - q*s2;
        t = t1 - q*t2;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
        r1 = r2;
        r2 = r;
    }
    //cout << "GCD is: " << r1 << "\n";
    //cout << "s1: " << s1 << "\n";
    if(t1<0)
       t1+=26;
    return t1;
}

vector<int> hill_Cipher(string p, int ar[][10])
{
    int p1 = p[0] - 'a', p2 = p[1] - 'a', p3 = p[2] - 'a';
    int c1 = norm(norm(p1 * ar[1][1]) + norm(norm(p2 * ar[2][1]) + norm(p3 * ar[3][1])));
    int c2 = norm(norm(p1 * ar[1][2]) + norm(norm(p2 * ar[2][2]) + norm(p3 * ar[3][2])));
    int c3 = norm(norm(p1 * ar[1][3]) + norm(norm(p2 * ar[2][3]) + norm(p3 * ar[3][3])));
    vector < int > v;
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);
    return v;
}
int det()
{
	int ans = 0;
	for(int i=1; i<=n; i++){
		ans+=(k[1][i] * adj[i][1]);
		ans = norm(ans);
	}
	return ans;
}
void func()
{
    //int aT[10][10]
    int rr = 1, cc;
    for(int j=1; j<=n; j++){
    	cc = 1;
    	for(int i=1; i<=n; i++){
    		aT[rr][cc] = norm(k[i][j]);
    		cc++;
    	}
    	rr++;
    }

    for(int i=1; i<=n; i++){
    	for(int j=1; j<=n; j++){
    		int po = powl(-1, (i+j));
    		int x = aT[i][j];
    		int idx = 0;
    		vector < int > v[2];
    		for(int r = 1; r<=n; r++){
    			for(int c=1; c<=n; c++){
    				if(r == i || c == j)
    					continue;
    				if(v[idx].size()!=2)
    					v[idx].push_back(aT[r][c]);
    				else
    					v[idx+1].push_back(aT[r][c]);
    				//cout << a[r][c] << " ";
    			}
    		}
    		//exit(0);

    		int a1 = norm(norm(v[0][0])*norm(v[1].back()));
    		int a2 = norm(norm(-v[1][0])*norm(v[0].back()));
    		int ans = norm(po*norm((a1+a2)));
    		//cout << aT[i][j] << " -----> " << ans << "\n";
    		adj[i][j] = ans;
    	}
    }

    int x = det();
    int ml = multiplicative_inverse(x, 26);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            adj[i][j] *= ml;
            adj[i][j] = norm(adj[i][j]);
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

}

string Print(string s, string Msg, int ar[][10])
{
    string s1="";
    string c="";
    vector < vector<int> > v;
    for(int i=0; s[i]; i++){
        s1+=s[i];
        if(s1.size() == 3){
            v.push_back(hill_Cipher(s1, ar));
            s1="";
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int id : v[i]){
            char ch = id+'a';
            c+=ch;
        }
    }
    cout << Msg << " Msg is: " << c << "\n\n";
    return c;
}

void solve(int kk)
{
    string p, c="";
    cout << "Enter a Plain Text: ";
    cin >> p;
    n = 3;
    cout << "Enter a 3x3 Matrix:\n";
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++)
            cin >> k[i][j], k[i][j] = norm(k[i][j]);
    }

    /// Encryption
    c = Print(p, "Encrypted", k);
    func();
    Print(c, "Decrypted", adj);

}

int32_t main()
{
   //fast;
   int t = 1;
   //cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
