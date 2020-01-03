///LCS
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
ll dp[3003][3003];
string ans="";
ll func(ll i, ll j)
{
    if(s1[i] == 0 || s2[j] == 0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans1=0,ans2=0,ans3=0;
    if(s1[i] == s2[j]){
        ans1 = 1+func(i+1,j+1);
    }
    ans2 = func(i+1,j);
    ans3 = func(i,j+1);
    return dp[i][j] = max({ans1,ans2,ans3});
}

void Print(ll i, ll j)
{
    if(s1[i] == 0 || s2[j] == 0){
        cout << ans << "\n";
        return;
    }
    if(s1[i] == s2[j]){
        ans+=s1[i];
        Print(i+1,j+1);
    }
    else{
        if(dp[i][j+1]>dp[i+1][j]) Print(i,j+1);
        else Print(i+1,j);
    }
}

void PrintAll(ll i, ll j) /// Prints All Possible LCS
{
    if(s1[i] == 0 || s2[j] == 0){
        cout << ans << "\n";
        return;
    }
    if(s1[i] == s2[j]){
        ans+=s1[i];
        PrintAll(i+1,j+1);
        ans.erase(ans.end()-1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) PrintAll(i+1,j);
        else if(dp[i][j+1]>dp[i+1][j]) PrintAll(i,j+1);
        else{
            PrintAll(i,j+1);
            PrintAll(i+1,j);
        }
    }

}

int main(){
    cin >> s1 >> s2;
    cout << func(0,0) << "\n"; /// Prints only the length of the LCS
    Print(0,0); /// Prints only one LCS String
    PrintALL(0,0); ///Prints All Possible LCS String
    return 0;
}

