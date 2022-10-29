#include<bits/stdc++.h>
using namespace std;
#define dd double
//#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int rand(int a, int b)
{
	return a+rand()%(b-a+1); 
}

int main(int argc, char* argv[])
{
   srand(atoi(argv[1]));
   int n = rand(1, 100000);
   cout << 1 << "\n" << n << "\n";
   //cout << "1\n100\n";
   multiset <int> used;
   for(int i=0; i<n; i++){
   	 int x;
   	// do{
   	 	x = rand(1, 1000000);
   	// }while(used.count(x));
   	//cout << x << " ";
   	used.insert(x);
   }
   for(int x : used)
   		cout << x << " ";
   cout << "\n";
   return 0;
}
