#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 200005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

char a1[5][5],a2[5],a3[5];
bool over;

bool test()
{
		 if((a1[0][0] == a1[0][1] && a1[0][0] == a1[0][2] && a1[0][0]) || (a1[1][0] == a1[1][1] && a1[1][0] == a1[1][2] && a1[1][0]) || (a1[2][0] == a1[2][1] && a1[2][0] == a1[2][2] && a1[2][0]) ) return 1;
		 if((a1[0][0] == a1[1][0] && a1[0][0] == a1[2][0] && a1[0][0]) || (a1[0][1] == a1[1][1] && a1[0][1] == a1[2][1] && a1[0][1]) || (a1[0][2] == a1[1][2] && a1[0][2] == a1[2][2] && a1[0][2]) ) return 1;

		 if(a1[0][0]!='\0' && a1[0][0] == a1[1][1] && a1[1][1] == a1[2][2]) return 1;
		 if(a1[2][0]!='\0' && a1[2][0] == a1[1][1] && a1[1][1] == a1[0][2]) return 1;

   		return 0;
}

bool Dice(string s)
{
    printf("|--------|--------|---------|\n");
    printf("|        |        |         |\n");
    printf("|   %c    |  %c     |   %c     |\n", a1[0][0], a1[0][1], a1[0][2]);
    printf("|        |        |         |\n");
    printf("|--------|--------|---------|\n");
    printf("|        |        |         |\n");
    printf("|   %c    |  %c     |   %c     |\n", a1[1][0], a1[1][1], a1[1][2]);
    printf("|        |        |         |\n");
    printf("|--------|--------|---------|\n");
    printf("|        |        |         |\n");
    printf("|   %c    |  %c     |   %c     |\n", a1[2][0], a1[2][1], a1[2][2]);
    printf("|        |        |         |\n");
    printf("|--------|--------|---------|\n");

    if(test()){
        cout << s << " has won.\n";
        return 1;
    }
    return 0;

}

void Set()
{
	a1[0][0]='1', a1[0][1]='2', a1[0][2]='3';
	a1[1][0]='4', a1[1][1]='5', a1[1][2]='6';
	a1[2][0]='7', a1[2][1]='8', a1[2][2]='9';
}

void Game()
{
    //cout << "\n\n";
    string s1[2];
    short int again;
    while(1){
		Set();
        printf("Enter Player 1\'s Name: ");
        cin >> s1[1];
        printf("Enter PLayer 2\'s Name: ");
        cin >> s1[0];

        for(int i=1; i<=9; i++){
            tutu:
			system("cls");
            cout << s1[i%2] << "\'s Turn:\n";
          //  system("cls");
            if(Dice(s1[i%2])) break;
            int ch,g;
            dd gg;
            cin >> ch;
            if(ch>9 || ch<1) goto tutu;
            gg = ceil(ch/3.0);
            if(ch%3 == 0) ch=3;
            else ch%=3;
            g = gg;
            bool ok=0;
            while(1){
                //if(g == 1){
                    if(a1[g-1][ch-1] == 'O' || a1[g-1][ch-1] == 'X'){
                        goto tutu;
                    }
                    else break;
                //}

            }
            Dice(s1[i%2]);
            if(i%2 == 1){
                if(g == 1) a1[g-1][ch-1]='O';
                else if(g == 2) a1[g-1][ch-1]='O';
                else a1[g-1][ch-1]='O';
                system("cls");
				if(Dice(s1[1])){
                    over=1;
                    break;
                }
            }
            else{
                if(g == 1) a1[g-1][ch-1]='X';
                else if(g == 2) a1[g-1][ch-1]='X';
                else a1[g-1][ch-1]='X';
                system("cls");
				if(Dice(s1[0])){
                    over=1;
                    break;
                }
            }

        }

			printf("Enter 1 For Play Again:\n");
			printf("Enter 2 For Quit:\n");
			cin >> again;
			if(again!=1) return;
			system("cls");

    }
}


void solve()
{
//	int aa=20;
//	for(int i=0; i<=5; i++){
//		//delay(1);
//		//cout << i << "\n";
//		system("cls");
//		cout << "Loading.           " << i*aa << "%";
//		delay(1);
//
//		system("cls");
//
//		cout << "Loading..          " << i*aa << "%";
//		delay(1);
//
//		system("cls");
//		//delay(1);
//
//		cout << "Loading...         " << i*aa << "%";
//		delay(1);
//
//		system("cls");
//		//delay(1);
//
//		cout << "Loading....        " << i*aa << "%";
//	//	system("cls");
//	}
	system("cls");
    Game();
    printf("Thanks for Playing the Game....");

}

int main()
{
   //fast;
   int t=1;
   //cin >> t;
   while(t--) solve();

   return 0;
}// 20ph671m

///https://codeforces.com/contest/1341/problem/D
