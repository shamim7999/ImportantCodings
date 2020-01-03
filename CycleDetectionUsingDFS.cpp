//Cycle Detection
#include<bits/stdc++.h>
char s1[60][60];
bool vis[60][60];
int r,c;
bool ok;

void dfs(int x, int y, int FromX,int FromY, char ch)
{
    if(x<0 || y<0 || x>=r || y>=c || s1[x][y]!=ch) return;
    if(vis[x][y] == 1){
        ok=1;
        return;
    }
    vis[x][y]=1;
    if(x+1!=FromX || y!=FromY) dfs(x+1,y,x,y,ch);
    if(x-1!=FromX || y!=FromY) dfs(x-1,y,x,y,ch);
    if(x!=FromX || y+1!=FromY) dfs(x,y+1,x,y,ch);
    if(x!=FromX || y-1!=FromY) dfs(x,y-1,x,y,ch);
}
int main()
{
   fast;
   cin >> r >> c;
   for(int i=0; i<r; i++){
      cin >> s1[i];
   }
   for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
           if(!vis[i][j]){
               dfs(i,j,i,j,s1[i][j]);
           }
           if(ok){
              cout << "Yes\n";
              return 0;
           }
       }
   }

    cout << "No\n";

   return 0;
}
